#include "fs.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void showMenu() {
    cout << "\n=== SimpleFS Dosya Sistemi ===\n";
    cout << "1. Format\n";
    cout << "2. Dosya oluştur\n";
    cout << "3. Dosya sil\n";
    cout << "4. Dosyaya yaz\n";
    cout << "5. Dosyadan oku\n";
    cout << "6. Dosya listesini göster\n";
    cout << "7. Dosya ismini değiştir\n";
    cout << "8. Dosya var mı?\n";
    cout << "9. Dosya boyutu\n";
    cout << "10. Dosyaya ekle\n";
    cout << "11. Dosyayı kısalt (truncate)\n";
    cout << "12. Dosya kopyala\n";
    cout << "13. Dosya içeriğini göster (cat)\n";
    cout << "14. İki dosya aynı mı? (diff)\n";
    cout << "15. Yedek al\n";
    cout << "16. Yedekten geri yükle\n";
    cout << "0. Çıkış\n";
    cout << "Seçiminiz: ";
}

int main() {
    SimpleFS fs("disk.sim");

    int secim;
    string filename, data, newname, filename2;
    int offset, size;

    do {
        showMenu();
        cin >> secim;
        cin.ignore(); // newline karakterini yut

        switch (secim) {
            case 1:
                fs.format();
                break;

            case 2:
                cout << "Dosya adı: ";
                getline(cin, filename);
                fs.create(filename.c_str());
                break;

            case 3:
                cout << "Dosya adı: ";
                getline(cin, filename);
                fs.remove(filename.c_str());
                break;

            case 4:
                cout << "Dosya adı: ";
                getline(cin, filename);
                cout << "Yazılacak veri: ";
                getline(cin, data);
                fs.fs_write(filename.c_str(), data.c_str(), data.size());
                break;

            case 5:
                cout << "Dosya adı: ";
                getline(cin, filename);
                cout << "Offset: ";
                cin >> offset;
                cout << "Boyut: ";
                cin >> size;
                cin.ignore();
                {
                    char* buffer = new char[size + 1];
                    fs.fs_read(filename.c_str(), offset, size, buffer);
                    buffer[size] = '\0'; // string sonlandırıcı ekle
                    cout << "Okunan veri: " << buffer << endl;
                    delete[] buffer;
                }
                break;

            case 6:
                fs.list();
                break;

            case 7:
                cout << "Eski isim: ";
                getline(cin, filename);
                cout << "Yeni isim: ";
                getline(cin, newname);
                fs.renameFile(filename.c_str(), newname.c_str());
                break;

            case 8:
                cout << "Dosya adı: ";
                getline(cin, filename);
                cout << (fs.exists(filename.c_str()) ? "Dosya var." : "Dosya yok.") << endl;
                break;

            case 9:
                cout << "Dosya adı: ";
                getline(cin, filename);
                cout << "Boyut: " << fs.size(filename.c_str()) << " bytes\n";
                break;

            case 10:
                cout << "Dosya adı: ";
                getline(cin, filename);
                cout << "Eklenecek veri: ";
                getline(cin, data);
                fs.append(filename.c_str(), data.c_str(), data.size());
                break;

            case 11:
                cout << "Dosya adı: ";
                getline(cin, filename);
                cout << "Yeni boyut: ";
                cin >> size;
                cin.ignore();
                fs.truncate(filename.c_str(), size);
                break;

            case 12:
                cout << "Kaynak dosya: ";
                getline(cin, filename);
                cout << "Hedef dosya: ";
                getline(cin, filename2);
                fs.copy(filename.c_str(), filename2.c_str());
                break;

            case 13:
                cout << "Dosya adı: ";
                getline(cin, filename);
                fs.cat(filename.c_str());
                break;

            case 14:
                cout << "Birinci dosya: ";
                getline(cin, filename);
                cout << "İkinci dosya: ";
                getline(cin, filename2);
                cout << (fs.diff(filename.c_str(), filename2.c_str()) ? "Dosyalar aynı." : "Dosyalar farklı.") << endl;
                break;

            case 15:
                cout << "Yedek dosya adı: ";
                getline(cin, filename);
                fs.backup(filename.c_str());
                break;

            case 16:
                cout << "Yedek dosya adı: ";
                getline(cin, filename);
                fs.restore(filename.c_str());
                fs = SimpleFS("disk.sim");
                break;

            case 0:
                cout << "Çıkılıyor...\n";
                break;

            default:
                cout << "Geçersiz seçim.\n";
                break;
        }

    } while (secim != 0);

    return 0;
}
