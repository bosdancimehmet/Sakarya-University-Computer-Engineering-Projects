import random

class DiffieHellman:
    def __init__(self):
        # RFC 3526 standardına uygun güvenli asal sayı (Hex formatında)
        self.p = 0xFFFFFFFFFFFFFFFFC90FDAA22168C234C4C6628B80DC1CD1  
        self.g = 2

        self.private_key = None
        self.public_key = None
        self.shared_secret = None

    def generate_private_key(self):
        """Özel anahtarı üretir."""
        self.private_key = random.randint(1, self.p - 1)
        return self.private_key

    def generate_public_key(self):
        """Genel anahtarı (Public Key) üretir."""
        if not self.private_key:
            self.generate_private_key()
        self.public_key = pow(self.g, self.private_key, self.p)
        return self.public_key

    def compute_shared_secret(self, other_public_key):
        """Karşı tarafın genel anahtarıyla ortak sırrı hesaplar."""
        if not self.private_key:
            raise Exception("Önce özel anahtar üretilmeli!")
        self.shared_secret = pow(other_public_key, self.private_key, self.p)
        return self.shared_secret

class CustomHash:
    """

    DJB2 algoritmasına benzer basit bir string hash fonksiyonu.
    """
    @staticmethod
    def generate(text):
        hash_value = 5381
        for char in text:
            # Bit kaydırma ve toplama ile karıştırma
            hash_value = ((hash_value << 5) + hash_value) + ord(char)
            # 64-bit integer sınırında tutmak için maskeleme
            hash_value = hash_value & 0xFFFFFFFFFFFFFFFF
        
        # Hex formatında string döndür
        return f"{hash_value:x}"

class CustomCipher:
    """
    UTF-8 destekli, XOR ve Modüler aritmetik tabanlı simetrik şifreleme.
    """
    
    @staticmethod
    def _expand_key(key_int, length):
        """Anahtarı mesaj uzunluğuna gelene kadar tekrarlar (bytes olarak)."""
        key_str = str(key_int)
        key_bytes = key_str.encode('utf-8') # Anahtarı byte'a çevir
        
        expanded = bytearray()
        while len(expanded) < length:
            expanded.extend(key_bytes)
        
        return expanded[:length]

    @staticmethod
    def encrypt(message, key_int):
        """Mesajı (String) şifreler -> Hex String döner."""
        if not key_int:
            raise ValueError("Anahtar yok!")
            
        # 1. Türkçe karakter için utf-8
        msg_bytes = message.encode('utf-8')
        
        # 2. Anahtarı hazırla
        key_bytes = CustomCipher._expand_key(key_int, len(msg_bytes))
        
        encrypted_bytes = bytearray()
        
        # 3. Byte byte şifreleme
        for i in range(len(msg_bytes)):
            # (MesajByte + AnahtarByte) % 256
            enc_byte = (msg_bytes[i] + key_bytes[i]) % 256
            encrypted_bytes.append(enc_byte)
            
        # 4. Hex string olarak geri döndür Ağda taşınması kolay olur
        return encrypted_bytes.hex()

    @staticmethod
    def decrypt(encrypted_hex, key_int):
        """Şifreli Hex Stringi çözer -> Orijinal String döner."""
        if not key_int:
            raise ValueError("Anahtar yok!")
            
        # 1. Hex stringi byte dizisine geri çevir
        try:
            encrypted_bytes = bytes.fromhex(encrypted_hex)
        except ValueError:
            return "[HATA] Bozuk veri paketi."

        key_bytes = CustomCipher._expand_key(key_int, len(encrypted_bytes))
        decrypted_bytes = bytearray()
        
        for i in range(len(encrypted_bytes)):
            # (ŞifreliByte - AnahtarByte) % 256 -> Ters işlem
            dec_byte = (encrypted_bytes[i] - key_bytes[i]) % 256
            decrypted_bytes.append(dec_byte)
            
        # 2. Byte dizisini UTF-8 stringe çevir
        try:
            return decrypted_bytes.decode('utf-8')
        except UnicodeDecodeError:
            return "[HATA] Şifre çözülemedi (Yanlış anahtar?)"

# --- TEST KISMI ---
if __name__ == "__main__":
    print("--- Gelişmiş Türkçe Destekli Test ---")
    alice = DiffieHellman()
    bob = DiffieHellman()
    
    a_pub = alice.generate_public_key()
    b_pub = bob.generate_public_key()
    
    # Sırları hesapla
    alice_secret = alice.compute_shared_secret(b_pub)
    bob_secret = bob.compute_shared_secret(a_pub)
    
    # Türkçe Testi
    mesaj = "Merhaba Dünya! Şiir gibi kod yazıyoruz :)"
    print(f"\nOrijinal: {mesaj}")
    
    sifreli = CustomCipher.encrypt(mesaj, alice_secret)
    print(f"Şifreli:  {sifreli[:50]}...") # Sadece başını göster
    
    cozulen = CustomCipher.decrypt(sifreli, bob_secret)
    print(f"Çözülen:  {cozulen}")
    
    if mesaj == cozulen:
        print("\n[MÜKEMMEL] Türkçe karakterler sorunsuz çalışıyor.")