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
