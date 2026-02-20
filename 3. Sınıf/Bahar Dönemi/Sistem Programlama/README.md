# 💾 SimpleFS: Sanal Dosya Sistemi Simülatörü (Virtual File System)

Bu proje, Sakarya Üniversitesi Sistem Programlama dersi kapsamında C++ ile geliştirilmiş; işletim sistemlerinin dosya yönetim mimarisini, metadata mantığını ve düşük seviyeli giriş/çıkış (I/O) işlemlerini simüle eden bir sanal dosya sistemidir.

## 🎯 Projenin Amacı
Yüksek seviyeli kütüphaneler kullanmak yerine, doğrudan POSIX sistem çağrıları (System Calls) aracılığıyla; tek bir fiziksel dosya (`disk.sim`) üzerinde sektörel bazda okuma/yazma işlemleri yaparak eksiksiz bir disk ve dosya yönetimi algoritması (File System) kurgulamaktır.

## ⚙️ Özellikler ve Teknik Detaylar
* **Düşük Seviyeli Sistem Çağrıları:** C++ standart dosya akışları (fstream) yerine, doğrudan işletim sistemi çekirdeği ile haberleşen `open`, `read`, `write`, `lseek`, `close` ve `ftruncate` fonksiyonları kullanılmıştır.
* **Metadata ve Veri Blokları Yönetimi:** Sanal disk (`disk.sim`) yapılandırılarak, ilk 4 KB'lık alanı dosyaların isim, boyut ve başlangıç adreslerini tutan "Metadata" (Üstveri) alanı olarak tahsis edilmiş, geri kalan alan ise gerçek verilerin (Data Blocks) yazılması için ayrılmıştır.
* **Kapsamlı FS Komutları:** 
  * Dosya oluşturma, silme, isimlendirme ve boyut kısaltma (`truncate`).
  * Belirli bir offset (konum) üzerinden bayt bazlı okuma ve yazma işlemleri.
  * Sanal diski sıfırlama (`format`) ve dosyaları listeleme (`ls`).
* **Gelişmiş Terminal Simülasyonları:** İki dosyanın bayt bazlı karşılaştırması (`diff`), dosya içeriğini konsola basma (`cat`), tüm sanal diskin yedeğini alma (`backup`) ve yedekten dönme (`restore`) gibi ekstra modüller tasarlanmıştır.

## 💻 Kullanılan Teknolojiler
* **Dil:** C++
* **Kavramlar:** Operating System Concepts, Virtual File Systems (VFS), POSIX System Calls, Metadata Management, Low-Level File I/O, Pointers & Memory Offset.

**Not :** Detaylı ekran çıktıları ve tanıtımlar rapor dosyasında bulunmaktadır, inceleyebilirsiniz. 
