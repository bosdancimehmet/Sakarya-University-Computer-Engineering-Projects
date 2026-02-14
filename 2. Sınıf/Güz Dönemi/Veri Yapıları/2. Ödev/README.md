# 🌳 AVL Ağacı ve Yığıt (Stack) Entegrasyon Simülasyonu

Bu proje, Sakarya Üniversitesi Veri Yapıları dersi kapsamında C++ ile geliştirilmiş; **AVL Ağaçları (AVL Trees)** ve **Yığıtların (Stacks)** eşzamanlı olarak bellek üzerinde yönetildiği gelişmiş bir veri yapısı ve algoritma simülasyonudur.

## 🎯 Projenin Amacı
Karmaşık veri setlerini okuyarak kendini dengeleyen (self-balancing) arama ağaçları oluşturmak, bu ağaçların belirli düğümlerini (yapraklarını) yığıtlara aktararak iki farklı veri yapısı arasında asenkron bir veri akışı ve rekabetçi bir silme algoritması (min/max öncelikli) kurgulamaktır.

## ⚙️ Özellikler ve Teknik Detaylar
* **Gelişmiş AVL Ağacı Mimarisi:** Verilen sayılardan kendini otomatik olarak dengeleyen (Sağ-Sol rotasyonları) dinamik AVL ağaçları oluşturulmuştur.
* **Postorder Traversal & Stack Entegrasyonu:** Her bir AVL ağacının yaprak düğümleri (leaf nodes) `postorder` (sol-sağ-kök) gezinme algoritması ile bulunup, o ağaca özel olarak bellekte tahsis edilen bir Yığıta (Stack) itilmiştir (`push`).
* **Matematiksel Düğüm Analizi:** Ağacın yaprak olmayan düğümlerinin toplamı hesaplanıp özel bir formülle `[ Toplam % (90-65+1) + 65 ]` ASCII karakterlerine dönüştürülmüştür.
* **Rekabetçi Silme Algoritması:** Tüm yığıtlar taranarak sırasıyla *en küçük* ve *en büyük* elemanlar yığıtlardan (`pop`) çıkarılmıştır. Elemanı biten yığıt ve bağlı olduğu AVL ağacı bellekten güvenli bir şekilde silinmiş (memory leak önlemi), döngü tek bir ağaç kalana kadar devam etmiştir.
* **Dinamik Bellek Yönetimi:** C++ `new` ve `delete` keywordleri ile pointer manipülasyonları yapılmış, silinen ağaçlardan sonra kalan ağaçlar dinamik olarak yeniden indekslenmiştir.

## 💻 Kullanılan Teknolojiler
* **Dil:** C++
* **Kavramlar:** AVL Trees, Stacks (LIFO), Postorder Traversal, Dynamic Memory Allocation, ASCII Manipulation, File I/O.

## 🎥 Çalışma Videosu
https://github.com/user-attachments/assets/b9f70824-4043-4364-9e4f-fadc6705c315
