# 🌐 NFC Destekli Akıllı Ortam Serinletme ve Güvenlik Sistemi (IoT Smart Environment)

Bu proje, Sakarya Üniversitesi Nesnelerin İnterneti (IoT) dersi kapsamında geliştirilmiş; donanım sensörleri ile bulut tabanlı bir kontrol panelini (Blynk) entegre eden akıllı bir ev/ortam prototipidir.

## 🎯 Projenin Amacı
Ortam güvenliğini ve iklimlendirmesini otonom hale getirmektir. Sistem, yetkisiz kişilerin kullanımını engellemek için RFID (NFC) teknolojisi ile korunmakta olup; yetkili giriş yapıldığında ortam sıcaklığına göre otomatik serinletme (iklimlendirme) yapmakta ve ultrasonik sensörler ile çevre güvenliğini sağlayarak verileri anlık olarak bulut platformuna aktarmaktadır.

## ⚙️ Özellikler ve Teknik Detaylar
* **NFC/RFID ile Kimlik Doğrulama:** Sistem, yalnızca yetkili RFID kartı (RC522 modülü) okutulduğunda aktif hale gelmektedir.
* **Otonom İklimlendirme (Soğutma):** LM35 sıcaklık sensörü ile ortamın ısısı sürekli ölçülmekte; sıcaklık belirli bir eşik değerini aştığında soğutucu motor (fan) otonom olarak devreye girmektedir.
* **Çevre ve Güvenlik Takibi:** HC-SR04 Ultrasonik mesafe sensörü ile sisteme yaklaşan nesnelerin mesafesi cm cinsinden ölçülmektedir.
* **Bulut Entegrasyonu (Blynk Platformu):** Tüm sensör verileri (Sıcaklık, Mesafe ve Sistem Durumu) Wi-Fi üzerinden **Blynk IoT** platformuna aktarılmakta ve kullanıcıya mobil cihaz/web üzerinden anlık izleme imkanı sunulmaktadır.

## 💻 Kullanılan Teknolojiler ve Donanımlar
* **Yazılım:** C/C++ (Arduino IDE), Blynk IoT Cloud Platform
* **Donanım:** Mikrokontrolör (ESP8266/NodeMCU), RFID-RC522 (NFC), LM35 (Sıcaklık), HC-SR04 (Ultrasonik Mesafe), DC Motor (Soğutucu).

## 📸 Devre Şeması ve Arayüz Görüntüleri
<img width="970" height="592" alt="image" src="https://github.com/user-attachments/assets/d70f72c7-9693-410c-b013-a86651dfc922" />
<img width="987" height="649" alt="Ekran görüntüsü 2026-02-20 180713" src="https://github.com/user-attachments/assets/80500290-84fb-4e44-bd1e-7f2419b7fbed" />
<img width="590" height="668" alt="image" src="https://github.com/user-attachments/assets/a66f48d6-55fb-4ab4-a9fa-c7445eb036f7" />
<img width="680" height="336" alt="Ekran görüntüsü 2026-02-20 181604" src="https://github.com/user-attachments/assets/d42ed97f-8695-421b-9df0-b41b244568ab" />

