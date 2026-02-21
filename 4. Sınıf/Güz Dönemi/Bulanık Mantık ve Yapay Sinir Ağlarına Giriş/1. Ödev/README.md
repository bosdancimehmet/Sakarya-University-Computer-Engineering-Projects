# 🧠 Bulanık Çıkarım Sistemi (FIS) ile Makroekonomik İşsizlik Tahmin Modeli

Bu proje, Sakarya Üniversitesi Bulanık Mantık ve Yapay Sinir Ağlarına Giriş dersi kapsamında geliştirilmiş; kesin sınırları olmayan makroekonomik değişkenleri (Gelir, Gider, Nüfus) kullanarak "İşsizlik Oranı" tahmini yapan Java tabanlı bir Bulanık Mantık (Fuzzy Logic) uzman sistemidir.

## 🎯 Projenin Amacı
Geleneksel (Boolean/Crisp) algoritmaların yetersiz kaldığı "Az", "Orta", "Çok" gibi yoruma dayalı gerçek dünya verilerini matematiksel üyelik fonksiyonlarıyla (Membership Functions) modellemek ve bu sayede ekonomik senaryolara uyum sağlayabilen esnek bir yapay zeka karar mekanizması oluşturmaktır.

## ⚙️ Sistem Mimarisi ve Teknik Özellikler
* **FCL (Fuzzy Control Language) Modellemesi:** Sistem kuralları ve üyelik fonksiyonları (Üçgen ve Yamuk formda) endüstri standardı olan FCL formatında `Model.fcl` dosyası içerisinde bağımsız olarak tasarlanmıştır.
* **Gelişmiş Kurallar Motoru:** Gelir (Açlık/Yoksulluk sınırlarına göre), Gider ve Nüfus endekslerine bağlı olarak 20'den fazla IF-THEN mantıksal kuralı yazılmış ve senaryoların ağırlıkları (Weight) belirlenmiştir.
* **Farklı Durulaştırma (Defuzzification) Algoritmaları:** Modelin ürettiği bulanık sonuçları gerçek (crisp) sayılara dönüştürmek için **COG (Center of Gravity - Ağırlık Merkezi)** ve **RM (Right Maximum)** algoritmaları entegre edilmiş ve aynı girdiler üzerindeki sonuç farkları analiz edilmiştir.
* **Görselleştirme:** `JFuzzyChart` kütüphanesi kullanılarak; üyelik fonksiyonları, aktif olan kurallar ve oluşan çıktı (işsizlik oranı) üzerindeki taralı alanlar (Defuzzifier alanı) dinamik grafikler halinde konsola/ekrana çizdirilmiştir.

## 💻 Kullanılan Teknolojiler
* **Dil:** Java (OOP)
* **Kütüphane / API:** jFuzzyLogic (Fuzzy Inference System API)
* **Kavramlar:** Fuzzy Logic, Defuzzification (COG, RM), FCL, Rule-Based AI Systems, Data Visualization.
