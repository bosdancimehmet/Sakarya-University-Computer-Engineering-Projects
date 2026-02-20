
# 🐧 Linux Özel Kabuk (Custom Shell) Geliştirimi

Bu proje, Sakarya Üniversitesi İşletim Sistemleri dersi kapsamında C programlama dili ile Linux ortamında geliştirilmiş; süreç (process) yönetimi, giriş/çıkış (I/O) yönlendirmesi ve süreçler arası iletişim (IPC) yeteneklerine sahip bir komut satırı yorumlayıcısıdır (Shell).

## 🎯 Projenin Amacı
Kullanıcıdan gelen komutları ayrıştırarak (parsing), Linux POSIX sistem çağrıları (System Calls) aracılığıyla çekirdek (kernel) seviyesinde işletmek ve standart bir terminalin (Bash, Zsh vb.) sunduğu temel donanım/süreç yönetim özelliklerini sıfırdan inşa etmektir.

## ⚙️ Özellikler ve Teknik Detaylar
* **Modüler Mimari:** Kod tabanı tek bir dosyaya sıkıştırılmamış; komut ayrıştırma, komut çalıştırma, boru (pipe) işlemleri ve sinyal yakalama gibi işlevler ayrı `.c` ve `.h` başlık dosyalarında modüler olarak tasarlanmıştır.
* **Süreç Yönetimi (Process Management):** Kullanıcı komutları `fork()` ile yeni çocuk süreçler oluşturularak ve `execvp()` ile çalıştırılarak ana kabuğun çökmesi engellenmiştir.
* **Arka Plan İşlemleri ve Sinyal Yakalama:** Sonuna `&` eklenen komutlar arka planda çalıştırılır. İşletim sisteminden gelen `SIGCHLD` sinyalleri `sigaction` ile asenkron olarak yakalanıp (`WNOHANG`), zombi (zombie) süreçlerin oluşması engellenmiş ve çıkış kodları (`WEXITSTATUS`) başarıyla ekrana yazdırılmıştır.
* **Giriş/Çıkış Yönlendirmesi (I/O Redirection):** `<` ve `>` operatörleri ile dosyadan okuma ve dosyaya yazma işlemleri `dup2()` kullanılarak standart girdi/çıktı (stdin/stdout) yönlendirilmesiyle sağlanmıştır.
* **Boru Hattı (Piping):** `|` operatörü ile birbirine bağlanan komutlar arasında isimsiz borular (`pipe()`) oluşturularak bir sürecin çıktısı diğer sürecin girdisi haline getirilmiştir.
* **Ardışık Çalıştırma:** `;` ile ayrılan birden fazla komut dizisi sırayla ayrıştırılıp çalıştırılabilir. `quit` komutu ise tüm arka plan süreçlerinin bitmesini bekleyerek güvenli bir çıkış sağlar.

## 💻 Kullanılan Teknolojiler ve Konseptler
* **Dil & Ortam:** C, Linux / UNIX
* **Sistem Çağrıları (POSIX APIs):** `fork`, `execvp`, `waitpid`, `pipe`, `dup2`, `open`, `close`, `sigaction`, `pause`
* **Kavramlar:** Process Creation, Inter-Process Communication (IPC), I/O Redirection, Signal Handling.
