# 🔗 Gelişmiş Bağlı Liste ve Bellek Yönetimi (Advanced Linked List Manager)

Bu proje, Sakarya Üniversitesi Veri Yapıları dersi kapsamında C++ kullanılarak geliştirilmiş; "iç içe tek yönlü bağlı liste" (singly linked list) mimarisiyle çalışan bir sayı ve bellek yönetim simülasyonudur.

## 🎯 Projenin Amacı
Büyük veri setlerinin standart diziler (arrays) yerine dinamik bellek tahsisi (dynamic memory allocation) kullanılarak ram üzerinde nasıl optimize edilebileceğini göstermektir. Projede pointer (işaretçi) manipülasyonu ile veriler üzerinde karmaşık algoritmik işlemler gerçekleştirilmiştir.

## ⚙️ Özellikler ve Teknik Detaylar
* **İç İçe Bağlı Liste Mimarisi:** `Sayilar.txt` dosyasından okunan her bir sayı bir düğümde (Dugum), o sayının her bir rakamı ise alt bir bağlı listede (Basamak) tutulmaktadır.
* **Dinamik Bellek Yönetimi (Memory Management):** `new` ve `delete` anahtar kelimeleriyle sınıfların `Destructor` (Yıkıcı) metotları kullanılarak bellek sızıntıları (memory leak) engellenmiştir.
* **Algoritmik İşlemler:**
  * Sayıların basamaklarındaki tek rakamları pointer koparmalarıyla listenin başına taşıma.
  * Bir sayının basamaklarını bellek üzerinde tamamen tersine çevirme (Reverse Linked List).
  * Bağlı liste üzerinde gezinerek en büyük değere sahip olan düğümü tespit edip güvenli bir şekilde silme.
* **Özel Bellek Görüntüleme:** Ekran çıktısında her bir düğümün RAM üzerindeki belleğinin (hexadecimal formatta son 3 hanesi) özel bir tasarımla çizdirilmesi.

## 💻 Kullanılan Teknolojiler
* **Dil:** C++
* **Kavramlar:** Singly Linked Lists, Pointers, Dynamic Memory Allocation, File I/O (Dosya Okuma/Yazma), Destructors, OOP.

## 📸 Ekran Görüntüleri
<img width="1049" height="817" alt="Ekran görüntüsü 2026-02-14 164220" src="https://github.com/user-attachments/assets/12f7b4bc-4e79-4140-8131-4d6f57ad2b54" />
<img width="1043" height="812" alt="Ekran görüntüsü 2026-02-14 164320" src="https://github.com/user-attachments/assets/62b49541-ac58-4164-a797-211cbb236765" />
<img width="1043" height="797" alt="Ekran görüntüsü 2026-02-14 164355" src="https://github.com/user-attachments/assets/36f71b09-f5fa-4711-8cc4-9e7b880dbaf0" />
<img width="1054" height="817" alt="Ekran görüntüsü 2026-02-14 164504" src="https://github.com/user-attachments/assets/18f3f0e7-7d5a-4a29-9cd1-79228b37fce0" />
<img width="1044" height="820" alt="Ekran görüntüsü 2026-02-14 164534" src="https://github.com/user-attachments/assets/37d73da9-0982-4172-8484-0d4875af19bd" />
<img width="778" height="543" alt="Ekran görüntüsü 2026-02-14 164940" src="https://github.com/user-attachments/assets/904bb1f4-1fd1-4ef1-bc9f-45e47f402c8f" />
<img width="738" height="411" alt="Ekran görüntüsü 2026-02-14 164957" src="https://github.com/user-attachments/assets/601dc8d1-836a-4ecf-aa5d-8da1497cfa03" />
<img width="727" height="270" alt="Ekran görüntüsü 2026-02-14 165010" src="https://github.com/user-attachments/assets/2bb473e3-dc9e-440f-9331-e2e07cd8e2c0" />
<img width="714" height="265" alt="Ekran görüntüsü 2026-02-14 165053" src="https://github.com/user-attachments/assets/b6f4add6-cf5f-4d42-bae7-c7d3e8eed468" />
