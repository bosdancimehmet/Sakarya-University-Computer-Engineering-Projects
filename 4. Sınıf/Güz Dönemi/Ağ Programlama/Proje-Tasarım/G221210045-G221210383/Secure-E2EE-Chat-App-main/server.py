import asyncio
import json
from database import DatabaseManager

# --- DB AYARLARI ---
DB_CONFIG = {
    "dbname": "chatdb",
    "user": "postgres",
    "password": "12345", 
    "host": "localhost",
    "port": "5432"
}

db = DatabaseManager(DB_CONFIG)

clients = {}      # username -> writer
# public_keys sözlüğünü RAM'de tutmaya devam edebiliriz hız için
# ama asıl kaynak artık veritabanı
public_keys_cache = {} 

async def handle_client(reader, writer):
    username = None
    try:
        while True:
            data = await reader.readline()
            if not data: break
            
            try:
                packet = json.loads(data.decode().strip())
            except: continue

            # ===== LOGIN =====
            if packet["type"] == "login":
                username = packet["username"].strip().lower()
                pub_key = packet.get("pub_key")
                
                if pub_key:
                    # 1. RAM'e yaz Hız için
                    public_keys_cache[username] = pub_key
                    # 2. Veritabanına yaz (Kalıcılık için)
                    db.register_user(username, pub_key)
                
                clients[username] = writer
                print(f"[+] {username} logged in.")
                
                # Offline Mesajları İlet
                offline_msgs = db.get_offline_messages(username)
                if offline_msgs:
                    print(f"[DB] {username} için {len(offline_msgs)} adet bekleyen mesaj var.")
                    for sender, content, timestamp in offline_msgs:
                        offline_packet = {
                            "type": "msg",
                            "from": sender,
                            "to": username,
                            "message": content,
                            "is_offline": True
                        }
                        writer.write((json.dumps(offline_packet) + "\n").encode())
                    await writer.drain()
                    db.mark_messages_delivered(username)
                continue

            # ===== REQ KEY (Anahtar İsteği) =====
            if packet["type"] == "req_key":
                target = packet["target_user"].strip().lower()
                response = {"type": "key_response", "target_user": target, "found": False}
                
                # 1. Önce RAM'e bak Online ise buradadır
                if target in public_keys_cache:
                    response["pub_key"] = public_keys_cache[target]
                    response["found"] = True
                
                # 2. Yoksa Veritabanına bak Offline ise buradadır
                else:
                    db_key = db.get_public_key(target)
                    if db_key:
                        response["pub_key"] = db_key
                        response["found"] = True
                
                writer.write((json.dumps(response) + "\n").encode())
                await writer.drain()
                continue
            
            # ===== REQ USER LIST =====
            if packet["type"] == "req_user_list":
                #Veritabanından HERKESİ çek
                all_registered_users = db.get_all_users()
                
                # Kendisi hariç diğer herkesi listeye al
                target_users = [u for u in all_registered_users if u != username]
                
                writer.write((json.dumps({"type": "user_list_response", "users": target_users}) + "\n").encode())
                await writer.drain()
                continue

            # ===== MESSAGE =====
            if packet["type"] == "msg":
                sender = packet["from"]
                message = packet["message"]
                
                # "to" veya "recipients" kontrolü
                target_list = packet.get("recipients", [packet.get("to")])
                
                for recipient in target_list:
                    if not recipient: continue
                    recipient = recipient.strip().lower()
                    
                    if recipient in clients:
                        try:
                            w = clients[recipient]
                            out = {"type": "msg", "from": sender, "to": recipient, "message": message}
                            w.write((json.dumps(out) + "\n").encode())
                            await w.drain()
                            db.save_message(sender, recipient, message, is_delivered=1)
                        except: pass
                    else:
                        # Kullanıcı offline ama veritabanına kaydet
                        print(f"[!] {recipient} çevrimdışı. Mesaj veritabanına kaydedildi.")
                        db.save_message(sender, recipient, message, is_delivered=0)

    except: pass
    finally:
        if username and username in clients:
            del clients[username]
            # public_keys_cache'den silmiyoruz, belki hemen geri gelir.
            # Zaten DB'de var.
        writer.close()
        await writer.wait_closed()

async def main():
    server = await asyncio.start_server(handle_client, "127.0.0.1", 8888)
    print("[*] Server with Persistent Key Registry Running...")
    async with server:
        await server.serve_forever()

if __name__ == "__main__":
    asyncio.run(main())