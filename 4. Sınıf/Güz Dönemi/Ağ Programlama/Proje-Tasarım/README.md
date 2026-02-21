# 🔒 Soket Programlama E2EE(End to End Encryption) TCP/IP Anlık Mesajlaşma Sistemi (Secure Chat Application)

Bu proje, Sakarya Üniversitesi Ağ Programlama dersi kapsamında Python ile geliştirilmiş; istemci-sunucu (client-server) mimarisinde çalışan, asenkron ve **Uçtan Uca Şifrelemeli (End-to-End Encrypted - E2EE)** bir anlık mesajlaşma (Instant Messaging) sistemidir.

## 🎯 Projenin Amacı
TCP/IP protokolü üzerinde çalışan çoklu istemci (multi-client) destekli bir ağ altyapısı kurmak; iletişim trafiğini aradaki sunucunun bile okuyamayacağı şekilde Diffie-Hellman algoritmasıyla şifrelemek ve çevrimdışı (offline) mesajlaşma yeteneği kazandırmaktır.

## ⚙️ Özellikler ve Teknik Detaylar
* **Asenkron Soket Mimarisi:** Sunucu ve istemci haberleşmesi, Python `asyncio` kütüphanesi kullanılarak TCP soketleri üzerinden non-blocking (bloklanmayan) bir yapıda kurgulanmıştır. Birebir, çoklu (grup) ve broadcast (tüm ağa) mesaj gönderimi desteklenir.
* **Uçtan Uca Şifreleme (E2EE):** İstemciler arası iletişimde **Diffie-Hellman (RFC 3526)** anahtar değişimi algoritması kullanılmıştır. Üretilen ortak sırlar (shared secrets) ile mesajlar XOR tabanlı özel bir simetrik şifreleyici (`CustomCipher`) ile istemci tarafında şifrelenir ve çözülür.
* **Çevrimdışı Mesajlaşma (Offline Delivery):** PostgreSQL veritabanı entegrasyonu sayesinde, hedef kullanıcı çevrimdışıysa sunucu şifreli mesajı ve mesajın hash değerini (`CustomHash`) veritabanına kaydeder. Kullanıcı giriş yaptığında (login) bekleyen mesajlar otomatik olarak asenkron şekilde teslim edilir (`is_delivered` flag).
* **Ağ Trafiği Analizi:** Geliştirilen şifreleme algoritmasının doğruluğu, **Wireshark** üzerinden TCP paket akışının (stream) dinlenmesiyle test edilmiş ve şifreli verinin (ciphertext) okunamadığı kanıtlanmıştır.

## 💻 Kullanılan Teknolojiler
* **Dil:** Python 3 (Asyncio)
* **Ağ & Güvenlik:** TCP/IP Sockets, Diffie-Hellman Key Exchange, Custom Symmetric Encryption & Hashing
* **Veritabanı:** PostgreSQL (`psycopg2`)
* **Araçlar:** Wireshark (Network Sniffing / Packet Analysis).

## 📸 Ekran Çıktıları ve Mimari Diyagramlar
<img width="767" height="748" alt="Ekran görüntüsü 2026-02-21 164639" src="https://github.com/user-attachments/assets/46c8a485-948e-40af-81e3-fbd92e3fb183" />
<br>

**UNICAST Haberleşme**

<br>
<img width="1483" height="859" alt="Ekran görüntüsü 2026-02-21 160553" src="https://github.com/user-attachments/assets/cc853ca3-d758-4f75-af66-711c68f04c10" />
<img width="1484" height="862" alt="Ekran görüntüsü 2026-02-21 160608" src="https://github.com/user-attachments/assets/e2b6cc2a-8a82-4bb8-8e76-51d4f8f161f0" />
<img width="1476" height="860" alt="Ekran görüntüsü 2026-02-21 160622" src="https://github.com/user-attachments/assets/6c44f8d0-5ca9-4b7f-af0f-d95d986e1755" />
<br>

**MULTICAST Haberleşme**
<br>

<img width="1481" height="860" alt="Ekran görüntüsü 2026-02-21 161148" src="https://github.com/user-attachments/assets/f57df3cf-bac3-4cb6-8b98-17a27e011aa3" />
<img width="1480" height="861" alt="Ekran görüntüsü 2026-02-21 161202" src="https://github.com/user-attachments/assets/df981491-015f-4801-b078-09e17d3a5a88" />
<img width="1481" height="860" alt="Ekran görüntüsü 2026-02-21 161221" src="https://github.com/user-attachments/assets/f2b097a8-419c-4574-b286-4b626bee4b08" />
<img width="1484" height="858" alt="Ekran görüntüsü 2026-02-21 161355" src="https://github.com/user-attachments/assets/6dd14b80-4be3-47b2-816d-7d571d59a13a" />
<img width="1481" height="860" alt="Ekran görüntüsü 2026-02-21 161414" src="https://github.com/user-attachments/assets/dde78587-5dde-40bd-b5c9-c060ac00a62f" />
<br>

**BROADCAST Haberleşme**

<br>
<img width="1485" height="861" alt="Ekran görüntüsü 2026-02-21 162124" src="https://github.com/user-attachments/assets/1f45a960-f4a1-4638-acad-d74fd8f3513f" />
<img width="1482" height="858" alt="Ekran görüntüsü 2026-02-21 162137" src="https://github.com/user-attachments/assets/a70b80ce-1e76-4c3c-a34d-f70f7d2036f3" />
<img width="1485" height="818" alt="Ekran görüntüsü 2026-02-21 162220" src="https://github.com/user-attachments/assets/b4f4003e-db06-4359-ae55-5d7f9d38100b" />
<img width="1483" height="816" alt="Ekran görüntüsü 2026-02-21 162244" src="https://github.com/user-attachments/assets/36d10a3b-5708-4607-9031-ad4126b59579" />
<img width="1482" height="823" alt="Ekran görüntüsü 2026-02-21 162346" src="https://github.com/user-attachments/assets/a16abcf6-3231-48af-9d17-7719b01d880c" />
<img width="1479" height="862" alt="Ekran görüntüsü 2026-02-21 162400" src="https://github.com/user-attachments/assets/ed0bcdf0-546c-4fa0-8b2e-7809d6535043" />
<br>

**PostgreSQL Veri Tabanı Tabloları**

<br>
<img width="1533" height="557" alt="Ekran görüntüsü 2026-02-21 170032" src="https://github.com/user-attachments/assets/c0dbe307-596a-47e9-b35f-f33ba5d9b4fb" />
<img width="1529" height="521" alt="Ekran görüntüsü 2026-02-21 163418" src="https://github.com/user-attachments/assets/40bdb82c-3426-40a2-8bf4-cc967fb04955" />
<img width="1525" height="522" alt="Ekran görüntüsü 2026-02-21 163500" src="https://github.com/user-attachments/assets/3767f7b2-6259-4fe5-8cb1-b25b8c9d2993" />
<br>

**WireShark Görseller**

<br>
<img width="1919" height="1018" alt="Ekran görüntüsü 2026-02-21 164147" src="https://github.com/user-attachments/assets/e09824c9-233e-4221-9d22-b739948c4a94" />
<img width="1276" height="1016" alt="Ekran görüntüsü 2026-02-21 164205" src="https://github.com/user-attachments/assets/5db6ac83-f082-4696-9489-3f55de3ed8ce" />
