# 🧬 C Dilinde OOP Benzetimi: Habitat Simülasyonu (Ecosystem Simulation in C)

Bu proje, Sakarya Üniversitesi Programlama Dillerinin Prensipleri dersi kapsamında geliştirilmiştir. Projenin temel odak noktası, Nesne Yönelimli Programlama (OOP) desteği olmayan **C programlama dilinde**, `struct` ve fonksiyon işaretçileri (function pointers) kullanılarak Kalıtım (Inheritance) ve Çok Biçimlilik (Polymorphism) mimarilerinin sıfırdan inşa edilmesidir.

## 🎯 Projenin Amacı
C dilinin düşük seviyeli bellek kontrolü gücünü kullanarak, dinamik boyutlu bir matris üzerinde (Habitat) yaşayan farklı canlı türlerinin (Bitki, Böcek, Sinek, Pire) av-avcı ilişkilerini OOP prensipleriyle (Soyut sınıflar, Kalıtım) simüle etmektir.

## ⚙️ Özellikler ve Teknik Detaylar
* **Nesne Yönelimli Benzetim (OOP Simulation):** C dilindeki `struct` yapıları kullanılarak sanal sınıflar (pseudo-classes) oluşturulmuştur.
* **Kalıtım Hiyerarşisi (Inheritance):** Ortak özellikleri barındıran üst `Canli` yapısı oluşturulmuş; `Bitki` ve `Bocek` doğrudan bu yapıdan, `Sinek` ve `Pire` ise `Bocek` yapısı üzerinden `this->super` pointer'ları ile kalıtım almıştır.
* **Çok Biçimlilik (Polymorphism) ve Soyutlama (Abstraction):** `Canli` yapısındaki gövdesiz `gorunum()` fonksiyon işaretçisi, alt sınıflar (türler) oluşturulurken o türe özel `gorunum_Bitki()`, `gorunum_Bocek()` gibi fonksiyonlarla ezilmiş (override) ve her canlının matriste kendi harfiyle (B, C, S, P) temsil edilmesi sağlanmıştır.
* **Dinamik Bellek Yönetimi:** `Veri.txt` dosyasından okunan ve satır/sütun sayısı belirsiz olan matris için `malloc` ile dinamik bellek tahsisi yapılmış, simülasyon bitiminde tüm nesneler özel `delete_` (Destructor) fonksiyonları hiyerarşik olarak çağrılarak `free()` ile bellekten temizlenmiştir (Memory Leak engellemesi).
* **Besin Zinciri Algoritması:** Matris üzerindeki canlıların değerlerine [1-99 arası] ve türlerine göre birbirlerini yemesi, yenen canlının `X` olarak işaretlenip `dead()` fonksiyonunun çağrılması algoritmik olarak modellenmiştir.

## 💻 Kullanılan Teknolojiler
* **Dil:** C (GCC / MinGW)
* **Kavramlar:** Structs, Function Pointers, Inheritance & Polymorphism Simulation, Dynamic Memory Allocation (`malloc`/`free`), 2D Arrays (Matrix), File I/O.

* ## 🎥 Çalışma Videosu
https://github.com/user-attachments/assets/0b3d16ed-a888-4f63-affa-3b4ced19c9c6
