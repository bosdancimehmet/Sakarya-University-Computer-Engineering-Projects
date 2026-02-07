import psycopg2
import time
from crypto import CustomHash

class DatabaseManager:
    def __init__(self, db_config):
        try:
            self.conn = psycopg2.connect(**db_config)
            self.conn.autocommit = True
            self.cursor = self.conn.cursor()
            self.create_tables()
            print("[DB] Bağlantı başarılı.")
        except Exception as e:
            print(f"[DB ERROR] {e}")

    def create_tables(self):
        # 1. Mesajlar Tablosu
        self.cursor.execute("""
            CREATE TABLE IF NOT EXISTS messages (
                id SERIAL PRIMARY KEY,
                sender VARCHAR(100),
                receiver VARCHAR(100),
                message TEXT,
                msg_hash VARCHAR(200),
                timestamp REAL,
                is_delivered INTEGER DEFAULT 0 
            )
        """)
        
        # 2. YENİ: Kullanıcılar ve Anahtarları Tablosu
        # Public Key çok büyük bir sayı olduğu için TEXT olarak tutacağız.
        self.cursor.execute("""
            CREATE TABLE IF NOT EXISTS users (
                username VARCHAR(100) PRIMARY KEY,
                public_key TEXT,
                last_seen REAL
            )
        """)

    def register_user(self, username, public_key):
        """Kullanıcı giriş yaptığında anahtarını kaydeder veya günceller."""
        # UPSERT (Update or Insert) mantığı
        query = """
            INSERT INTO users (username, public_key, last_seen) 
            VALUES (%s, %s, %s)
            ON CONFLICT (username) 
            DO UPDATE SET public_key = EXCLUDED.public_key, last_seen = EXCLUDED.last_seen;
        """
        try:
            self.cursor.execute(query, (username, str(public_key), time.time()))
            # print(f"[DB] {username} anahtarı güncellendi.")
        except Exception as e:
            print(f"[DB ERROR] User Key Update: {e}")

    def get_public_key(self, username):
        """Kullanıcı offline olsa bile veritabanından anahtarını getirir."""
        query = "SELECT public_key FROM users WHERE username = %s"
        try:
            self.cursor.execute(query, (username,))
            result = self.cursor.fetchone()
            if result:
                return int(result[0]) # String olarak kaydetmiştik, int'e çevirip dönüyoruz
            return None
        except Exception as e:
            print(f"[DB ERROR] Key Fetch: {e}")
            return None

    def get_all_users(self):
        """Kayıtlı tüm kullanıcı adlarını listeler (Offline dahil)."""
        query = "SELECT username FROM users"
        try:
            self.cursor.execute(query)
            # fetchall() -> [('ali',), ('veli',)] şeklinde döner
            # Biz bunu düz listeye ['ali', 'veli'] çevirelim:
            return [row[0] for row in self.cursor.fetchall()]
        except Exception as e:
            print(f"[DB ERROR] Get All Users: {e}")
            return []

    # --- Diğer Mesaj Fonksiyonları Aynen Kalıyor ---
    def save_message(self, sender, receiver, message, is_delivered=0):
        msg_hash = CustomHash.generate(message)
        query = """
            INSERT INTO messages (sender, receiver, message, msg_hash, timestamp, is_delivered) 
            VALUES (%s, %s, %s, %s, %s, %s)
        """
        try:
            self.cursor.execute(query, (sender, receiver, message, msg_hash, time.time(), is_delivered))
        except Exception as e:
            print(f"[DB ERROR] Save Msg: {e}")

    def get_offline_messages(self, user):
        query = "SELECT sender, message, timestamp FROM messages WHERE receiver = %s AND is_delivered = 0"
        try:
            self.cursor.execute(query, (user,))
            return self.cursor.fetchall()
        except: return []

    def mark_messages_delivered(self, user):
        try:
            self.cursor.execute("UPDATE messages SET is_delivered = 1 WHERE receiver = %s AND is_delivered = 0", (user,))
        except: pass