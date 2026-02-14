# 💥 Geometrik Çarpışma Denetimi (Geometric Collision Detection)

Bu proje, C# ve Windows Forms kullanılarak geliştirilmiş, 2 boyutlu (2D) ve 3 boyutlu (3D) geometrik cisimler arasındaki çarpışma durumlarını matematiksel algoritmalarla hesaplayan ve görselleştiren bir masaüstü uygulamasıdır.

## 🎯 Projenin Amacı
Uygulama, temel bir fizik motoru (physics engine) mantığıyla çalışarak; kullanıcı tarafından koordinatları ve boyutları girilen farklı geometrik şekillerin uzayda birbirleriyle kesişip kesişmediğini (collision) tespit etmeyi amaçlar.

## ⚙️ Özellikler ve Teknik Detaylar
* **Çoklu Nesne Desteği:** Nokta, Çember, Dikdörtgen, Küre, Dikdörtgenler Prizması, Silindir ve 3D Yüzeyler (X-Y, Y-Z, X-Z) gibi geniş bir nesne yelpazesi.
* **Matematiksel Algoritmalar:** Cisimlerin merkez noktaları, yarıçapları ve uzunlukları kullanılarak (Pisagor teoremi, mutlak değer algoritmaları ve Signum fonksiyonu) 20'den fazla farklı çarpışma senaryosu hesaplanmaktadır.
* **Görselleştirme (GDI+):** Windows Forms `System.Drawing.Graphics` kütüphanesi kullanılarak, girilen değerlere göre cisimlerin izdüşümleri dinamik olarak ekrandaki (Panel) koordinat sistemine çizdirilmektedir.
* **Dinamik UI:** Nesne seçimine göre (Combobox) gereksiz girdi alanlarının (Textbox) kapatılması ve anlık durum bildirimi sağlayan kullanıcı dostu arayüz.

## 💻 Kullanılan Teknolojiler
* **Dil:** C#
* **Platform:** .NET Framework / Windows Forms (WinForms)
* **Kavramlar:** Object-Oriented Programming (OOP), GDI+ (Graphics, Pen, Brush), Mathematical Modeling, Event-Driven Programming.

---
*Not: Projemin tamamını kodladığım ve çalıştırdığım youtube linki: https://youtu.be/j3gJ-nlVG68*
## 📸Uygulama Ekran Görüntüleri
<img width="981" height="560" alt="Ekran görüntüsü 2026-02-14 152324" src="https://github.com/user-attachments/assets/787387bc-0d1d-4471-8bc4-30681e7dd2ef" />
<img width="977" height="560" alt="Ekran görüntüsü 2026-02-14 152528" src="https://github.com/user-attachments/assets/8fe2ca33-0641-435f-9eba-d0254dfe7883" />
<img width="981" height="556" alt="Ekran görüntüsü 2026-02-14 152650" src="https://github.com/user-attachments/assets/faff9215-0147-4349-9d8c-1cc39192a4a9" />
<img width="978" height="555" alt="Ekran görüntüsü 2026-02-14 152623" src="https://github.com/user-attachments/assets/6bca7821-d160-4f6c-843b-dc86a4dc2268" />
<img width="983" height="557" alt="Ekran görüntüsü 2026-02-14 152458" src="https://github.com/user-attachments/assets/4eba02b2-d655-490b-9a06-19fcf924f109" />
<img width="978" height="559" alt="Ekran görüntüsü 2026-02-14 152434" src="https://github.com/user-attachments/assets/8f64ac5e-4e66-4225-9ff6-55f455db17a3" />



