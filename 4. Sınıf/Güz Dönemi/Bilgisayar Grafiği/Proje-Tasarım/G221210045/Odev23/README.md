# 🎥 3D Grafik Motoru: Hiyerarşik Modelleme ve Çoklu Viewport (Advanced OpenGL Engine)

Bu proje, Sakarya Üniversitesi Bilgisayar Grafiği dersi kapsamında C++ ve OpenGL kullanılarak geliştirilmiş, hiyerarşik sahne yapısına (Scene Graph) ve çoklu kamera sistemine sahip bir 3D grafik motoru uzantısıdır.

> **💡 Önemli Not:** Projenin temel işleme (rendering) mimarisi, shader derleme algoritmaları ve temel VBO/VAO soyutlamaları **ders kapsamında oluşturulmuş kod tabanına dayanmaktadır.** Aşağıda belirtilen tüm gelişmiş mimariler (Çoklu Viewport, Hiyerarşik Sahne Grafiği, IBO Optimizasyonu ve Serbest Kamera Kontrolleri) mevcut kodun üzerine inşa edilerek sisteme entegre edilmiştir.

## 🎯 Projenin Amacı
Temel bir grafik motorunu alıp; ebeveyn-çocuk (parent-child) ilişkisine sahip karmaşık 3D modellerin bir arada hareket edebildiği, optimizasyon odaklı (Index Buffer) ve aynı ekranda birden fazla kameranın (Picture-in-Picture) çalışabildiği modern bir motor seviyesine taşımaktır.

## ⚙️ Eklenen ve Geliştirilen Modüller
* **Hiyerarşik Sahne Grafiği (Scene Graph):** `SceneObject` sınıfı tasarlanarak nesneler arası ebeveyn-çocuk ilişkisi kuruldu. Ana objeye uygulanan dönüşümler (Position, Rotation, Scale) matematiksel olarak (`parentCombinedMatrix`) tüm alt objelere hiyerarşik olarak aktarıldı.
* **Çoklu Görüntü Alanı (Multi-Viewport / PiP):** `ViewPort` sınıfı geliştirilerek aynı pencere (Window) içerisine birden fazla kamera bağlandı. Ana ekranın yanında, köşede çalışan bağımsız bir "Film Kamerası" (ikincil bakış açısı) arayüzü tasarlandı.
* **Serbest Kamera ve Girdi Kontrolleri:** Dinamik matris (GLM) hesaplamalarıyla `Camera` ve `Transform` sınıfları geliştirildi. WASD tuşları ile uzayda serbest dolaşım ve farenin sağ tuşu (Mouse Drag) ile yön/açı değiştirme (Free-look) özellikleri eklendi.
* **Index Buffer (IBO) Optimizasyonu:** `IndexBuffer` soyutlaması koda entegre edilerek, `glDrawArrays` yerine bellek dostu `glDrawElements` mantığına geçiş yapıldı. Silindir (Cylinder) gibi primitif şekiller indis bazlı render edildi.

## 💻 Kullanılan Teknolojiler
* **Dil:** C++ (OOP Mimarisi)
* **Grafik API:** OpenGL (Core Profile) & GLAD / GLFW
* **Matematik Motoru:** GLM (OpenGL Mathematics)

## 📸 Ekran Görüntüleri ve Viewport Sistemi
<img width="1602" height="937" alt="Ekran görüntüsü 2026-02-21 194141" src="https://github.com/user-attachments/assets/832e55c8-b5c6-4255-8557-3c18b6ff6c1d" />
<img width="1599" height="935" alt="Ekran görüntüsü 2026-02-21 194159" src="https://github.com/user-attachments/assets/bfb21f17-ee30-43ae-adf2-e51a35ac834e" />
<img width="1599" height="937" alt="Ekran görüntüsü 2026-02-21 194116" src="https://github.com/user-attachments/assets/dd5ab360-f792-4f8a-b893-c3f16bb80f2c" />
