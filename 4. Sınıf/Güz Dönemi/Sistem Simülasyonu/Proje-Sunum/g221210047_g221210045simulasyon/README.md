# 🚑 Ambulans Çağrı Merkezi: İstatistiksel Modelleme ve Sistem Simülasyonu

Bu proje, Sakarya Üniversitesi Sistem Simülasyonu dersi kapsamında; gerçek dünya verileri (İran Acil Çağrı Merkezi Veri Seti) kullanılarak çağrı geliş sıklıklarının ve operatör hizmet sürelerinin istatistiksel olarak analiz edildiği ve baştan sona simüle edildiği bir matematiksel modelleme çalışmasıdır.

## 🎯 Projenin Amacı
Karmaşık kuyruk sistemlerinin (Queueing Systems) çalışma mantığını anlamak; gerçek verilerin hangi olasılık dağılımlarına uyduğunu istatistiksel testlerle kanıtlamak ve elde edilen parametrelerle geleceğe yönelik bir sistem simülasyonu (Müşteri bekleme süresi, sistemde kalma süresi vb.) inşa etmektir.

## ⚙️ Uygulanan Metodolojiler ve Analizler
* **Veri Madenciliği ve Dağılım Tespiti:** Çağrı varış süreleri analiz edilerek $\lambda=0,2374$ parametreli **Üstel Dağılım** karakteristiği gösterdiği, operatör hizmet sürelerinin ise $\mu=2,79$ ortalama ile **Normal Dağılım** gösterdiği tespit edilmiştir.
* **Hipotez ve Uygunluk Testleri:** Tahmin edilen istatistiksel dağılımların doğruluğu, %95 güven aralığında **Ki-Kare (Chi-Square) Uygunluk Testi** ile test edilmiş ve kabul (H0) edilmiştir.
* **Rastgele Sayı Üretimi ve Denetimi:** Simülasyon için gerekli olan sözde rastgele sayılar (Pseudo-random numbers) özel parametrelerle ($X_0=7, a=12, c=19, m=100$) üretilmiş ve bu sayıların homojen dağılıp dağılmadığı **Kolmogorov-Smirnov (K-S) Testi** ile doğrulanmıştır.
* **Kuyruk Teorisi Simülasyonu:** Doğrulanan rastgele sayılar ve dağılım fonksiyonları (Ters Dönüşüm Yöntemi vb.) kullanılarak; çağrıların sisteme geliş anları, servise başlama bitiş süreleri ve bekleme süreleri dinamik olarak yeniden üretilerek sistemin genel performansı simüle edilmiştir.

## 💻 Kullanılan Yöntemler ve Araçlar
* **Kavramlar:** System Simulation, Queueing Theory, Probability Distributions (Exponential & Normal), Hypothesis Testing (Chi-Square, K-S Test), Random Number Generation (LCG).
* **Araçlar:** Veri analizi ve modelleme süreçleri elektronik tablo (Excel) algoritmaları üzerinden yürütülmüştür.

## 📸 Analiz Grafikleri ve Simülasyon Tabloları
<img width="817" height="481" alt="Ekran görüntüsü 2026-02-21 203440" src="https://github.com/user-attachments/assets/171eaf7c-597b-42c8-a728-215ad6832803" />
<img width="839" height="489" alt="Ekran görüntüsü 2026-02-21 203453" src="https://github.com/user-attachments/assets/a21353af-a8d0-482e-ad02-f09ecc2607d1" />
<img width="887" height="496" alt="Ekran görüntüsü 2026-02-21 203516" src="https://github.com/user-attachments/assets/4e2d9cfb-d478-45da-b4c4-8cd22ab0e7f1" />
<img width="599" height="286" alt="Ekran görüntüsü 2026-02-21 203528" src="https://github.com/user-attachments/assets/73255afb-7a9c-4dbd-8679-9050d663923a" />
<img width="1142" height="403" alt="Ekran görüntüsü 2026-02-21 203546" src="https://github.com/user-attachments/assets/8557cbcf-582f-4449-b35c-05bce4f820ec" />
