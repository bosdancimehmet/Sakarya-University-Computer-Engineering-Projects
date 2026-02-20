# 🤖 DFA Durum İndirgeme Algoritması (DFA State Minimization)

Bu proje, Sakarya Üniversitesi Biçimsel Diller ve Soyut Makineler dersi kapsamında geliştirilmiş; Deterministik Sonlu Otomatların (DFA) geçiş tablolarını optimize ederek en sade hallerine indirgeyen algoritmik bir C# konsol uygulamasıdır.

## 🎯 Projenin Amacı
Verilen herhangi bir DFA'nın çalışma mantığını bozmadan, içerisindeki gereksiz/denk (equivalent) durumları tespit edip birleştirerek ve alt küme karmaşasını ortadan kaldırarak minimum durum sayısına sahip optimize bir DFA modeli (Minimized DFA) oluşturmaktır.

## ⚙️ Özellikler ve Algoritmik Adımlar
* **Kullanıcı Etkileşimi:** Kullanıcıdan başlangıç durumları, 0/1 geçiş tabloları (transition tables) ve kabul durumları (accept states) dinamik olarak alınır.
* **Denklik Gruplarının Hesaplanması (Equivalence Partitioning):** Kabul ve ret durumları iteratif bir şekilde taranarak durumlar kendi içlerinde denklik gruplarına (equivalence classes) ayrılır.
* **Alt Küme Optimizasyonu:** Oluşan durum grupları arasında alt küme (subset) ilişkisi kontrol edilir ve yalnızca en büyük, anlamlı gruplar muhafaza edilir.
* **Yeni Geçiş Tablosu Üretimi:** Birleştirilen (indirgenen) yeni durumlar için DFA kurallarına uygun, optimize edilmiş yeni bir geçiş tablosu ve başlangıç/kabul durumları çıktısı üretilir.

## 💻 Kullanılan Teknolojiler
* **Dil:** C# (.NET)
* **Kavramlar:** Automata Theory (Otomata Teorisi), DFA State Minimization, Discrete Mathematics (Ayrık Matematik), HashSet / Dictionary Data Structures.

## 🎥 Çalışma Videosu
https://github.com/user-attachments/assets/9782fc34-3c10-4977-8058-5a73dc4512e6

## 📸 Ekran Görüntüleri
*Örnek 1*
<img width="814" height="1233" alt="image" src="https://github.com/user-attachments/assets/b671ad14-ba68-45c7-a6fd-b04ba82956e3" />
*Örnek 2*
<img width="865" height="1319" alt="image" src="https://github.com/user-attachments/assets/4ea834c0-d179-42ea-a533-e8c56e500047" />
