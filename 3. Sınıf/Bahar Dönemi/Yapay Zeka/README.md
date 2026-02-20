# 🤖 İlgi Alanı Geliştirme Asistanı (AI Interest Explorer Agent)

Bu proje, Sakarya Üniversitesi Yapay Zeka dersi kapsamında geliştirilmiş; Langflow tabanlı bir Büyük Dil Modeli (LLM) akışını, Python ile özel olarak tasarlanmış bağımsız bir masaüstü arayüzü (GUI) ile entegre eden akıllı bir kişisel öğrenme asistanıdır.

## 🎯 Projenin Amacı
Kullanıcıların yeni ilgi alanlarını veya yetenekleri keşfetmelerine yardımcı olmak; bu alanlarda sistemli bir öğrenme rotası çizerek güvenilir kaynaklara (linklere) yönlendiren otonom bir yapay zeka rehberi (AI Agent) oluşturmaktır.

## ⚙️ Özellikler ve Teknik Detaylar
* **Gelişmiş LLM Akışı (Flow Architecture):** Uygulamanın arka planındaki AI zekası, Langflow üzerinde sürükle-bırak yöntemiyle kurgulanmış en az 12 düğümlük (node) karmaşık bir prompt zinciriyle sağlanmaktadır.
* **Bağımsız Masaüstü Arayüzü:** Yapay zeka aracının varsayılan arayüzü yerine, Python `tkinter` kütüphanesi kullanılarak `threading` (çoklu iş parçacığı) destekli, asenkron ve donma yapmayan özel bir chat (sohbet) arayüzü geliştirilmiştir.
* **REST API Entegrasyonu:** Masaüstü istemcisi (Client), Langflow sunucusu ile `requests` kütüphanesi üzerinden HTTP API aracılığıyla JSON formatında haberleşmektedir.
* **Dinamik Veri ve Link İşleme:** LLM'den dönen yanıtlar içerisindeki URL/Link formatındaki metinler, Düzenli İfadeler (Regex) kullanılarak ayrıştırılır ve arayüz üzerinde tıklanabilir (clickable) hiperlinklere dönüştürülür (`webbrowser` entegrasyonu).

## 💻 Kullanılan Teknolojiler
* **Yapay Zeka & Agent:** Langflow, LLM APIs (NVIDIA NIM vb.)
* **Geliştirme Dili:** Python 3 (OOP)
* **Arayüz & Kütüphaneler:** Tkinter (GUI), Threading, Requests (REST API), Regular Expressions (Re).

## 📸 Ekran Görüntüleri ve Akış Diyagramı
<img width="1065" height="758" alt="Ekran görüntüsü 2026-02-20 193841" src="https://github.com/user-attachments/assets/663017c4-7f49-4c6d-b768-4ec5c860361d" />
<img width="1063" height="542" alt="Ekran görüntüsü 2026-02-20 193826" src="https://github.com/user-attachments/assets/fc016287-3a1b-4462-846f-e67dd1c6cf75" />
<img width="1065" height="563" alt="Ekran görüntüsü 2026-02-20 193908" src="https://github.com/user-attachments/assets/8294c6d7-cfba-48f4-b652-0020db92326f" />

Detaylar rapor dosyasında bulunmaktadır.
