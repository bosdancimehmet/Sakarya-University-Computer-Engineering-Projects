# ➕ Karmaşık Sayı Hesaplama Aracı (Complex Number Calculator)

Bu proje, C++ ile Nesne Yönelimli Programlama (OOP) prensipleri kullanılarak geliştirilmiş kapsamlı bir karmaşık sayı (complex number) hesaplama aracıdır.

## 🎯 Projenin Amacı
Projenin temel hedefi, C++ dilindeki **Operatör Aşırı Yükleme (Operator Overloading)** yeteneklerini kullanarak, karmaşık sayıların sanki standart veri tipleriymiş (`int`, `double` gibi) gibi doğal bir sözdizimi ile matematiksel işlemlere tabi tutulmasını sağlamaktır.

## ⚙️ Özellikler ve Teknik Detaylar
* **Kapsülleme (Encapsulation):** Karmaşık sayıların reel ve sanal kısımları `private` olarak tanımlanmış, erişimler `Getter` ve `Setter` metotları ile güvenli hale getirilmiştir.
* **Aritmetik Operatör Aşırı Yüklemeleri:** İki karmaşık sayı nesnesi arasında `+`, `-`, `*`, `/` işlemleri operatör seviyesinde tanımlanmıştır.
* **Bileşik Atama Operatörleri:** Bellek ve işlem verimliliği için `+=`, `-=`, `*=`, `/=` operatörleri aşırı yüklenmiştir.
* **Kutupsal Gösterim (Polar Representation):** Girilen karmaşık sayıların orijine olan uzaklıkları (R vektörü) pisagor teoremi ( `<cmath>` kütüphanesi) ile hesaplanarak kutupsal formda sunulmaktadır.
* **Dinamik CLI Menüsü:** Kullanıcının çalışma zamanında (runtime) nesneleri oluşturup anlık olarak tüm operatörleri test edebildiği sonsuz döngülü bir menü arayüzü.

## 💻 Kullanılan Teknolojiler
* **Dil:** C++
* **Kavramlar:** Object-Oriented Programming (OOP), Classes, Operator Overloading, Encapsulation, `<cmath>`.
