# 🧊 3D Sahne Editörü ve Grafik Motoru (OpenGL Scene Editor)

Bu proje, Sakarya Üniversitesi Bilgisayar Grafiği dersi kapsamında C++ ve OpenGL kullanılarak geliştirilmiş interaktif bir 3D sahne yönetim ve render aracıdır.

> **💡 Önemli Not:** Projenin temel rendering mimarisi (VAO/VBO soyutlamaları, Shader derleme işlemleri ve temel pencereleme) ders kapsamında oluşturulmuş olup; projenin geri kalan tüm interaktif modülleri, ImGui arayüzü, sahne serileştirme (JSON save/load) algoritmaları ve dinamik obje yönetimi mevcut kod tabanının üzerine geliştirilmiştir.

## 🎯 Projenin Amacı
Kullanıcının 3 boyutlu bir uzayda farklı geometrik şekilleri (Küp, Piramit) dinamik olarak sahneye ekleyebildiği, bu objelerin dünya matrislerini **(Position, Rotation, Scale)** anlık olarak değiştirebildiği ve kamera ayarlarını manipüle edebildiği bir grafik arayüzü (GUI) sunmaktır.

## ⚙️ Eklenen ve Geliştirilen Özellikler
* **Dinamik Sahne Yönetimi (`SceneManager`):** Sahneye anlık olarak yeni objeler eklenebilir, silinebilir ve listeden seçilerek sadece o objeye odaklanılarak dönüşüm (transformation) işlemleri uygulanabilir.
* **Gelişmiş Kullanıcı Arayüzü (ImGui):** Obje koordinatlarının, dönüş açılarının, boyutlarının ve anlık `World Matrix` değerlerinin takip edilip değiştirilebildiği, kamera için FOV, Near, Far değerlerinin ayarlandığı bir panel tasarlandı.
* **Sahne Serileştirme (JSON Integration):** `nlohmann/json` kütüphanesi entegre edilerek, oluşturulan sahnedeki tüm objelerin uzaysal verileri `scene.json` dosyasına kaydedilme ve tekrar yüklenme (Save/Load) özelliği kazandırıldı.
* **Mesh ve Texture Yükleyicisi:** Özelleştirilmiş `.mesh` formatındaki dosyaları okuyup VBO/VAO yapılarına dönüştüren ve `stb_image` ile görselleri kaplama (Texture) olarak uygulayan bellek dostu bir mimari kuruldu.

## 💻 Kullanılan Teknolojiler ve Kütüphaneler
* **Dil:** C++
* **Grafik API:** OpenGL (Core Profile)
* **Pencere ve Girdi Yönetimi:** GLFW, GLAD
* **Matematik ve Dönüşümler:** GLM (OpenGL Mathematics)
* **Kullanıcı Arayüzü:** Dear ImGui
* **Veri Serileştirme & Görsel:** nlohmann/json, stb_image

## 📸 Uygulama Arayüzü ve Ekran Görüntüleri
<img width="1595" height="933" alt="Ekran görüntüsü 2026-02-21 183917" src="https://github.com/user-attachments/assets/716e2410-214e-49d8-b5f7-ece465e3f2ee" />
<img width="1598" height="937" alt="Ekran görüntüsü 2026-02-21 184322" src="https://github.com/user-attachments/assets/c379443a-b6cf-4906-b231-c761d5f99353" />
