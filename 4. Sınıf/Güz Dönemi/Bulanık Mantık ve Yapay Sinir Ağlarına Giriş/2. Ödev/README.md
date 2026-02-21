# 🧠 Yapay Sinir Ağları (YSA) ile Makroekonomik İşsizlik Tahmini

Bu proje, Sakarya Üniversitesi Bulanık Mantık ve Yapay Sinir Ağlarına Giriş dersi kapsamında Java ve **Neuroph Framework** kullanılarak geliştirilmiş; makroekonomik verilere (Gelir, Gider, Nüfus) dayanarak işsizlik oranını tahmin eden bir Derin Öğrenme (Deep Learning) / Çok Katmanlı Algılayıcı (MLP) modelidir.

## 🎯 Projenin Amacı
Bulanık Mantık uzman sistemi kullanılarak üretilen 4000 satırlık sentetik veri seti üzerinden bir Yapay Sinir Ağı (ANN) modelini eğitmek; farklı hiperparametre ve topolojileri test ederek en düşük Hata Kareleri Ortalaması (MSE) değerine sahip optimize edilmiş yapay zeka modelini kurgulamaktır.

## ⚙️ Sistem Mimarisi ve Model Özellikleri
* **Veri Üretimi ve Ön İşleme:** Bulanık çıkarım sistemi kullanılarak rastgele 4000 adet veri üretilmiş (`dataset.txt`); bu veriler sinir ağının daha hızlı ve stabil öğrenebilmesi için Min-Max normalizasyon tekniği ile [0-1] aralığına ölçeklenmiştir.
* **Ağ Topolojisi Optimizasyonu:** Ara (gizli) katmandaki nöron sayıları değiştirilerek 10 farklı ağ mimarisi test edilmiş; overfitting (aşırı öğrenme) ve underfitting (eksik öğrenme) durumları analiz edilerek en optimum sonuç veren **3-12-1 (Girdi-Gizli-Çıktı)** mimarisi seçilmiştir.
* **Eğitim Algoritmaları:** Model, **Backpropagation (geriye yayılım)** algoritmasıyla hem **Momentumlu** hem de **Momentumsuz** olarak eğitilmiş ve bu iki yöntemin yakınsama hızları/test hataları karşılaştırılmıştır (Learning Rate: 0.2, Momentum: 0.7).
* **Model Doğrulama (Validation):** Sistemin genellenebilirliğini ölçmek adına veriler %75 Eğitim, %25 Test olarak ayrılmış ve model başarısı **K-Fold Cross Validation (Çapraz Doğrulama)** yöntemiyle test edilmiştir.
* **İnteraktif Konsol:** Kullanıcıya ağ eğitme, Epoch bazlı hata değişimi izleme, K-Fold uygulama ve tekli manuel test yapma imkanı sunan bir CLI (Komut Satırı Arayüzü) geliştirilmiştir.

## 💻 Kullanılan Teknolojiler
* **Dil:** Java (OOP)
* **Makine Öğrenmesi Kütüphanesi:** Neuroph (Java Neural Network Framework)
* **Kavramlar:** Artificial Neural Networks (ANN), Multi-Layer Perceptron (MLP), Backpropagation, Momentum, K-Fold Cross Validation, Data Normalization, Hyperparameter Tuning.
