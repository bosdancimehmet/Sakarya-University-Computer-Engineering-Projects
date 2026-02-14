# 🌐 Web Site Tasarımı

Bu proje, Sakarya Üniversitesi **Web Teknolojileri** dersi kapsamında geliştirilmiş; hem ön yüz (Frontend) hem de arka yüz (Backend) teknolojilerini barındıran giriş-orta seviye bir kişisel web sitesidir.

## 🎯 Projenin Amacı
Sadece statik bilgilerin sergilendiği bir web sayfası oluşturmak yerine; kullanıcı girişli (Authentication), dış kaynaklardan canlı veri çeken (REST API) ve kullanıcı etkileşimlerini sunucuda işleyebilen (PHP) dinamik bir web mimarisi kurgulamaktır.

## ⚙️ Özellikler ve Teknik Detaylar
* **Kullanıcı Doğrulama (Login Sistemi):** Sadece yetkili kullanıcıların giriş yapabildiği, PHP session mantığı ile kurgulanmış log-in sayfası.
* **REST API Entegrasyonu (Dinamik Veri):** "İlgi Alanlarım" sayfasında JavaScript `fetch()` fonksiyonu kullanılarak `restcountries.com` API'sine istek atılmış ve JSON formatındaki küresel ülke/bayrak verileri asenkron olarak arayüze yansıtılmıştır.
* **İstemci Taraflı Doğrulama (Client-Side Validation):** İletişim sayfasındaki form verileri sunucuya gönderilmeden önce JavaScript DOM manipülasyonu ile denetlenmiş (boş alan, özel email uzantısı zorunluluğu, radio buton seçimleri vb.) ve hatalı durumlarda kullanıcıya `alert` ile geri bildirim sağlanmıştır.
* **Sunucu Taraflı İşleme (Server-Side Processing):** Geçerli form verileri PHP backend yapısına post edilmiş (`iletisim.php`), sunucuda işlenen veriler dinamik bir HTML sayfası olarak kullanıcıya geri döndürülmüştür.
* **Özel UI/UX Tasarımı:** Hazır şablon kullanılmadan, `style.css` ile tamamen sıfırdan yazılmış Flexbox/Grid mimarisine sahip, slider destekli ve menü navigasyonlu kullanıcı dostu arayüz.

## 💻 Kullanılan Teknolojiler
* **Frontend:** HTML5, CSS3, JavaScript (ES6+), Fetch API, DOM.
* **Backend:** PHP (Form Post & Data Handling).
* **Veri İletişimi:** JSON, RESTful API.

## 📸 Ekran Görüntüleri
<img width="756" height="367" alt="Ekran görüntüsü 2026-02-14 154610" src="https://github.com/user-attachments/assets/23726a29-2a30-4cdd-823f-1569f67fecbc" />
<img width="754" height="365" alt="Ekran görüntüsü 2026-02-14 154709" src="https://github.com/user-attachments/assets/5656e85d-794d-45e9-b838-7b7af2d27d92" />
<img width="756" height="367" alt="Ekran görüntüsü 2026-02-14 154728" src="https://github.com/user-attachments/assets/265c72b5-0349-4a81-9b32-ad2b580148f9" />
