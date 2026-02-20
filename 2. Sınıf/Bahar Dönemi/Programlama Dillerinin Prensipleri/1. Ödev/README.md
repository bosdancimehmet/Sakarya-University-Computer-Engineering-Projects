# 📊 Java Statik Kod Analiz Aracı (Java Source Code Analyzer)

Bu proje, Sakarya Üniversitesi Programlama Dillerinin Prensipleri dersi kapsamında Java dilinde geliştirilmiş; GitHub üzerindeki projeleri otomatik olarak indirip kaynak kodları metrik bazlı analiz eden bir konsol (CLI) uygulamasıdır.

## 🎯 Projenin Amacı
Geliştiricilerin yazdığı Java kodlarının kalitesini ve dokümantasyon oranını ölçmektir. Program, verilen bir depodaki tüm Java sınıflarını tarayarak kod satırı (LOC), Javadoc yoğunluğu ve fonksiyon sayıları gibi kritik yazılım metriklerini hesaplar.

## ⚙️ Özellikler ve Teknik Detaylar
* **Otomatik Repo Klonlama:** Kullanıcıdan alınan GitHub Repository URL'si kullanılarak, ilgili proje arka planda yerel dizine (Masaüstü) klonlanır.
* **Regex ile Veri Madenciliği:** Kod içerisindeki sınıfları (class), fonksiyonları, standart yorum satırlarını (`//`, `/* */`) ve Javadoc (`/** */`) bloklarını birbirinden kesin olarak ayırmak için karmaşık **Düzenli İfadeler (Regular Expressions - Regex)** ve bool bayrak (flag) mantığı kullanılmıştır.
* **Detaylı Metrik Raporlama:** Her bir `.java` dosyası için:
  * Toplam LOC (Line of Code)
  * Sadece kod içeren satır sayısı (Boşluklar ve yorumlar hariç)
  * Fonksiyon (Metot) sayısı
  * Javadoc ve Normal Yorum satırı sayıları
  * % Yorum Sapma Yüzdesi hesaplanır ve formata uygun (#,##) yazdırılır.
* **Dosya Yönetimi (File I/O):** `BufferedReader` ve `FileReader` kullanılarak dosyalar satır satır okunup analiz edilir.

## 💻 Kullanılan Teknolojiler
* **Dil:** Java (OOP)
* **Kavramlar:** Static Code Analysis, Regular Expressions (Regex) (`java.util.regex`), File I/O, Git CLI Integration.
