# 🐄 Çiftlik ve Besi Üretim Tesisi Veritabanı Yönetim Sistemi

Bu proje, Sakarya Üniversitesi Veritabanı Yönetim Sistemleri dersi kapsamında; gerçek dünya iş kurallarına (business rules) uygun olarak tasarlanmış ilişkisel bir veritabanı mimarisini ve bu veritabanı ile tam entegre çalışan C# masaüstü uygulamasını içermektedir.

## 🎯 Projenin Amacı
Karmaşık veri kümelerini (hayvan kayıtları, personel bilgileri, veteriner tedavi süreçleri, üretim çıktıları) doğru Varlık-Bağıntı (ER-Entity Relationship) modelleriyle tasarlamak ve son kullanıcılar için tüm veri manipülasyonu (CRUD) işlemlerini yapabilecekleri güvenli bir arayüz geliştirmektir.

## ⚙️ Özellikler ve Teknik Detaylar
* **Gelişmiş Veritabanı Tasarımı:** Sistemdeki tüm tablolar (İşçi, Hayvan, Veteriner, Bayi vb.) normalizasyon kurallarına uygun olarak tasarlanmış ve aralarındaki ilişkiler Crow's Foot gösterimiyle ER (Entity Relationship) diyagramlarına dökülmüştür.
* **Tam Kapsamlı CRUD İşlemleri:** C# WinForms arayüzü üzerinden veritabanında Arama (Read), Ekleme (Create), Güncelleme (Update) ve Silme (Delete) işlemleri sorunsuz bir şekilde gerçekleştirilmektedir.
* **Veritabanı Nesneleri:** Sadece tablolarla kalınmamış; veri bütünlüğünü ve iş mantığını veritabanı seviyesinde çözmek için `Triggers` (Tetikleyiciler), `Functions` (Fonksiyonlar), `Stored Procedures` (Saklı Yordamlar) ve `Views` (Sanal Tablolar) kullanılmıştır.
* **Veri Filtreleme ve DataGrid:** Veriler arayüzde `DataGridView` bileşeni kullanılarak listelenmiş ve ID/İsim bazlı anlık arama algoritmaları entegre edilmiştir.

## 💻 Kullanılan Teknolojiler
* **Uygulama Geliştirme:** C# (.NET Framework, Windows Forms)
* **Veritabanı:** PostgreSQL (Relational Database Management System)
* **Kavramlar:** ER (Entity Relationship) Modeling, CRUD, SQL Queries, Triggers, Stored Procedures.

## 📸 ER (Entity Relationship) Diyagramı ve Ekran Görüntüleri 
<img width="1183" height="799" alt="Ekran görüntüsü 2026-02-14 184817" src="https://github.com/user-attachments/assets/03191b5e-8ee0-487f-8543-f40674e5d33d" />
<img width="1183" height="798" alt="Ekran görüntüsü 2026-02-14 184907" src="https://github.com/user-attachments/assets/758bcb87-dfa2-4c41-a81e-cbbf75a603b0" />
<img width="1183" height="657" alt="Ekran görüntüsü 2026-02-14 184949" src="https://github.com/user-attachments/assets/e2c90974-0feb-4375-b33e-204672fc94c7" />
<img width="1185" height="801" alt="Ekran görüntüsü 2026-02-14 185020" src="https://github.com/user-attachments/assets/e5942e94-b501-443b-a59a-9be5d0c5d4d6" />
<img width="1183" height="800" alt="Ekran görüntüsü 2026-02-14 185100" src="https://github.com/user-attachments/assets/9b779c2e-bd9e-410d-ac11-697a42b17a5e" />
<img width="1182" height="798" alt="Ekran görüntüsü 2026-02-14 185122" src="https://github.com/user-attachments/assets/90f0e10b-74b9-4b4b-869a-2e9a20c14965" />
