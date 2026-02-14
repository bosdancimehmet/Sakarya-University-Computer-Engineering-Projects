# 🎓 Öğrenci Not Yönetim Sistemi (Student Grade Management System)

Bu proje, Sakarya Üniversitesi **Programlamaya Giriş** dersi kapsamında C++ dili ile geliştirilmiş konsol tabanlı bir not otomasyon sistemidir.

## 🎯 Projenin Amacı
Öğrencilere ait not verilerinin yapısal (Struct) olarak bellekte tutulması, bu veriler üzerinde istatistiksel hesaplamalar yapılması ve filtrelenerek raporlanması amaçlanmıştır. Sistem, hem rastgele ağırlıklı veri üretimi hem de kullanıcıdan kontrollü veri girişi seçenekleri sunmaktadır.

## ⚙️ Özellikler ve Teknik Detaylar
* **Veri Modelleme:** `Struct` yapısı kullanılarak öğrencilerin ad, soyad ve 7 farklı sınav notu (Vize, Final, Kısa Sınavlar, Ödevler, Proje) modellendi.
* **Rastgele Veri Üretimi:** Belirli bir isim/soyad havuzundan rastgele 100 öğrenci oluşturulup, notları gerçekçi ağırlık yüzdelerine (örn: 0-40 arası %10, 40-70 arası %50 vb.) göre dağıtıldı.
* **İstatistiksel Hesaplamalar:** * Sınıfın en yüksek ve en düşük başarı notunun bulunması.
  * Sınıf ortalaması ve **Standart Sapma** hesaplamaları.
* **Filtreleme ve Raporlama:** Belirli bir not aralığındaki veya sınır değerin altındaki/üstündeki öğrencilerin listelenmesi.
* **Harf Notu Dönüşümü:** 100'lük sistemdeki başarı notlarının (AA, BA, BB vb.) harf sistemine dönüştürülmesi.
* **Kullanıcı Dostu Arayüz:** CLI (Komut Satırı Arayüzü) üzerinden çalışan dinamik menü tasarımı ve 20'şerli sayfalama (pagination) mantığı.

## 💻 Kullanılan Teknolojiler
* **Dil:** C++
* **Kavramlar:** Structs, Arrays, Functions, Loops, CLI Menu, Math Libraries (`<cmath>`, `<ctime>`).
