import asyncio
import json
import os  #klasör işlemleri için
from crypto import DiffieHellman, CustomCipher

# --- GLOBAL ---
my_dh = DiffieHellman()
my_private = None 
my_public = None

active_secrets = {} 
pending_incoming = {}
key_wait_event = asyncio.Event()
user_list_event = asyncio.Event()
fetched_user_list = [] 

# Anahtarların saklanacağı klasör adı
KEYS_FOLDER = "user_keys"

def load_or_generate_keys(username):
    """
    Kullanıcıya özel anahtarı 'user_keys' klasöründen okur. 
    Dosya yoksa klasörü oluşturur, yeni üretip kaydeder.
    """
    global my_private, my_public
    
    # 1. Klasör yoksa oluştur
    if not os.path.exists(KEYS_FOLDER):
        os.makedirs(KEYS_FOLDER)
        print(f"[Sistem] '{KEYS_FOLDER}' klasörü oluşturuldu.")

    # 2. Dosya yolunu belirle (örn: user_keys/meto_key.json)
    filename = os.path.join(KEYS_FOLDER, f"{username}_key.json")
    
    if os.path.exists(filename):
        try:
            with open(filename, "r") as f:
                data = json.load(f)
                my_private = data["private_key"]
                my_dh.private_key = my_private
                my_public = my_dh.generate_public_key()
                print(f"[Sistem] Mevcut kimlik yüklendi: {filename}")
        except Exception as e:
            print(f"[Hata] Anahtar dosyası bozuk, yeni üretiliyor: {e}")
            _generate_new_and_save(filename)
    else:
        print(f"[Sistem] Yeni kimlik oluşturuluyor...")
        _generate_new_and_save(filename)

def _generate_new_and_save(filepath):
    """Anahtarı üretir ve belirtilen yola kaydeder."""
    global my_private, my_public
    my_private = my_dh.generate_private_key()
    my_public = my_dh.generate_public_key()
    
    # Dosyaya kaydet
    with open(filepath, "w") as f:
        json.dump({"private_key": my_private}, f)
    print(f"[Sistem] Kimlik kaydedildi: {filepath}")

async def get_secret(writer, target_user):
    if target_user in active_secrets:
        return active_secrets[target_user]
    
    req = {"type": "req_key", "target_user": target_user}
    writer.write((json.dumps(req) + "\n").encode())
    await writer.drain()
    
    key_wait_event.clear()
    try:
        await asyncio.wait_for(key_wait_event.wait(), timeout=2.0)
    except asyncio.TimeoutError:
        return None
    return active_secrets.get(target_user)

async def get_online_users(writer):
    global fetched_user_list
    req = {"type": "req_user_list"}
    writer.write((json.dumps(req) + "\n").encode())
    await writer.drain()
    
    user_list_event.clear()
    try:
        await asyncio.wait_for(user_list_event.wait(), timeout=3.0)
        return fetched_user_list
    except asyncio.TimeoutError:
        print("[!] Sunucudan kullanıcı listesi alınamadı.")
        return []

async def listen(reader, writer):
    global fetched_user_list
    while True:
        try:
            data = await reader.readline()
            if not data: break
            line = data.decode().strip()
            if not line: continue
            
            try:
                packet = json.loads(line)
            except:
                print(f"\n{line}")
                continue

            # --- RESPONSES ---
            if packet.get("type") == "key_response":
                tgt = packet["target_user"]
                if packet["found"]:
                    secret = my_dh.compute_shared_secret(packet["pub_key"])
                    active_secrets[tgt] = secret
                    
                    if tgt in pending_incoming:
                        for old_packet in pending_incoming[tgt]:
                            # Paketin tamamını sakladığımız için buradan çekiyoruz
                            enc_msg = old_packet["message"] 
                            dec = CustomCipher.decrypt(enc_msg, secret)
                            
                            # Etiket kontrolü
                            prefix = "(OFFLINE)" if old_packet.get("is_offline") else ""
                            
                            print(f"\n[{tgt} -> Siz {prefix}]: {dec}")
                            print("Alıcı: Mesaj > ", end="", flush=True)
                        del pending_incoming[tgt]
                key_wait_event.set()

            elif packet.get("type") == "user_list_response":
                fetched_user_list = packet["users"]
                user_list_event.set()

            # --- INCOMING MSG ---
            elif packet.get("type") == "msg":
                sender = packet["from"]
                enc_msg = packet["message"]
                
                if sender in active_secrets:
                    dec = CustomCipher.decrypt(enc_msg, active_secrets[sender])
                    prefix = "(OFFLINE)" if packet.get("is_offline") else ""
                    print(f"\n[{sender} -> Siz {prefix}]: {dec}")
                    print("Alıcı: Mesaj > ", end="", flush=True)
                else:
                    if sender not in pending_incoming:
                        pending_incoming[sender] = []
                    pending_incoming[sender].append(packet)
                    
                    req = {"type": "req_key", "target_user": sender}
                    writer.write((json.dumps(req) + "\n").encode())
                    await writer.drain()

        except Exception as e:
            print(f"Hata: {e}")
            break

async def tcp_client():
    try:
        reader, writer = await asyncio.open_connection("127.0.0.1", 8888)
    except ConnectionRefusedError:
        print("[Hata] Sunucuya bağlanılamadı. Önce server.py'ı başlatın.")
        return

    username = await asyncio.to_thread(input, "Kullanıcı Adı: ")
    username = username.strip().lower()
    
    # Anahtarları yükle (klasöre bakacak)
    load_or_generate_keys(username)
    
    # Login
    login = {"type": "login", "username": username, "pub_key": my_public}
    writer.write((json.dumps(login) + "\n").encode())
    await writer.drain()
    
    asyncio.create_task(listen(reader, writer))
    
    print("\n=== E2EE CHAT SİSTEMİ ===")
    print(f"Kullanıcı: {username}")
    print("-------------------------")

    while True:
        try:
            inp = await asyncio.to_thread(input, "Alıcı: Mesaj > ")
            if ":" not in inp: continue
            
            targets_str, msg = inp.split(":", 1)
            targets_str = targets_str.strip().lower()
            msg = msg.strip()
            
            target_list = []
            
            if targets_str == "*":
                target_list = await get_online_users(writer)
                if not target_list:
                    print("[!] Kimse online değil.")
                    continue
            elif "," in targets_str:
                target_list = [t.strip() for t in targets_str.split(",")]
            else:
                target_list = [targets_str]

            for target in target_list:
                if target == username: continue 
                
                secret = await get_secret(writer, target)
                
                if secret:
                    enc_msg = CustomCipher.encrypt(msg, secret)
                    packet = {
                        "type": "msg",
                        "from": username,
                        "to": target, 
                        "message": enc_msg
                    }
                    writer.write((json.dumps(packet) + "\n").encode())
                    await writer.drain()
                    print(f"[Ben -> {target}]: {msg}")
                else:
                    print(f"[!] {target} için anahtar bulunamadı.")

        except Exception as e:
            print(f"Hata: {e}")
            break

if __name__ == "__main__":
    try:
        asyncio.run(tcp_client())
    except KeyboardInterrupt: pass