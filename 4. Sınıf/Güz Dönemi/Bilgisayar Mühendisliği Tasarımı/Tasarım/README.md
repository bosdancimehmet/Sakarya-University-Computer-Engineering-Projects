# ♻️ Yapay Zeka Destekli Akıllı Atık Ayrıştırma ve Teşvik Sistemi (AI-Powered Smart Bin & Gamification)

Bu proje, Sakarya Üniversitesi Bilgisayar Mühendisliği Tasarımı dersi kapsamında geliştirilmiş; donanım (IoT), derin öğrenme (Deep Learning) ve mobil uygulama katmanlarını bir araya getiren hibrit (uçtan uca) bir ürün prototipidir.

## 🎯 Projenin Amacı
Geleneksel geri dönüşüm süreçlerindeki insan hatasını sıfıra indirmek ve çevresel sürdürülebilirliği artırmaktır. Sistem, atıkları (kağıt, plastik, metal, cam) kamera aracılığıyla tanıyıp otonom olarak fiziksel haznelerine ayırırken; entegre mobil uygulaması sayesinde kullanıcılara atık başına "reMoney" isimli sanal puanlar vererek geri dönüşümü oyunlaştırmakta (gamification) ve teşvik etmektedir.

## ⚙️ Sistem Mimarisi ve Modüller

### 1. Yapay Zeka ve Bilgisayarlı Görü (AI & Computer Vision)
* Kamera modülünden alınan anlık görüntüler OpenCV kullanılarak işlenmiştir.
* Görüntüler, Python tabanlı oluşturulan **CNN (Evrişimli Sinir Ağları)** derin öğrenme modeline sokularak atığın materyali yüksek doğrulukla sınıflandırılmaktadır.

### 2. Gömülü Sistem ve IoT (Embedded Hardware)
* Sistemin merkezi işlem birimi olarak **Raspberry Pi** mikrodenetleyicisi kurgulanmıştır.
* Yapay zekadan gelen tahmin (prediction) sonucuna göre, ilgili haznenin servo motorları tetiklenerek atık fiziksel olarak doğru bölmeye yönlendirilir.

### 3. Çapraz Platform Mobil Uygulama (Cross-Platform Mobile App)
* **Flutter ve Dart** kullanılarak hem iOS hem de Android için Material Design standartlarında kullanıcı dostu bir arayüz geliştirilmiştir.
* Kullanıcılar, "Dijital Cüzdan" ekranından günlük/aylık geri dönüşüm istatistiklerini (dairesel grafikler ile) ve kazandıkları "reMoney" bakiyelerini anlık olarak takip edebilirler.

### 4. Bulut ve Veri Yönetimi (Cloud & Backend)
* Sistem, **Google Firebase** altyapısı (Authentication & Realtime Database / Firestore) üzerinde koşmaktadır.
* Donanımın (Akıllı Çöp Kutusu) kaydettiği atık verisi ile kullanıcının mobil cihazı arasındaki veri senkronizasyonu gerçek zamanlı (real-time) olarak milisaniyeler içerisinde sağlanmaktadır.

## 💻 Kullanılan Teknolojiler
* **Yapay Zeka:** Python, OpenCV, CNN (Deep Learning)
* **Donanım:** Raspberry Pi, Kamera Modülü, Servo Motorlar
* **Mobil Geliştirme:** Flutter, Dart
* **Bulut & Veritabanı:** Firebase (Auth, Realtime DB)
