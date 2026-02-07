#include "fs.hpp"
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <iostream>
#include <sys/stat.h>
#include <ctime>
#include <fstream>

using namespace std;

SimpleFS::SimpleFS(const char* diskName) {
    disk_fd = open(diskName, O_RDWR | O_CREAT, 0666);
    if (disk_fd < 0) {
        cerr << "Disk dosyası açılamadı!" << endl;
        exit(1);
    }
    loadMetadata();
}

SimpleFS::~SimpleFS() {
    saveMetadata();
    close(disk_fd);
}

void SimpleFS::loadMetadata() {
    lseek(disk_fd, 0, SEEK_SET);
    ssize_t res = read(disk_fd, metadata, sizeof(metadata));  // Burada metadata okunuyor
    if (res < (ssize_t)sizeof(metadata)) {
        memset(metadata, 0, sizeof(metadata)); // Disk boş veya ilk kez formatlanıyor
    }
}

void SimpleFS::saveMetadata() {
    lseek(disk_fd, 0, SEEK_SET);
    write(disk_fd, metadata, sizeof(metadata));  // Burada metadata diske yazılıyor
}

void SimpleFS::format() {
    ftruncate(disk_fd, DISK_SIZE);
    memset(metadata, 0, sizeof(metadata));
    saveMetadata();

    char zeroBlock[BLOCK_SIZE] = {0};
    for (int i = 0; i < (DISK_SIZE - META_SIZE) / BLOCK_SIZE; ++i) {
        lseek(disk_fd, META_SIZE + i * BLOCK_SIZE, SEEK_SET);
        write(disk_fd, zeroBlock, BLOCK_SIZE);
    }
    cout << "Disk formatlandı." << endl;
    log("Disk formatlandı.");
}

int SimpleFS::findFileIndex(const char* filename) {
    for (int i = 0; i < MAX_FILES; ++i) {
        if (metadata[i].valid && strcmp(metadata[i].filename, filename) == 0) {
            return i;
        }
    }
    return -1;
}

int SimpleFS::findFreeBlock(int size) {
    int numBlocks = size / BLOCK_SIZE + (size % BLOCK_SIZE != 0);
    int usedBlocks[(DISK_SIZE - META_SIZE) / BLOCK_SIZE] = {0};
    for (int i = 0; i < MAX_FILES; ++i) {
        if (metadata[i].valid) {
            int blocksUsed = metadata[i].size / BLOCK_SIZE + (metadata[i].size % BLOCK_SIZE != 0);
            for (int j = 0; j < blocksUsed; ++j) {
                usedBlocks[metadata[i].start_block + j] = 1;
            }
        }
    }
    int totalBlocks = (DISK_SIZE - META_SIZE) / BLOCK_SIZE;
    for (int i = 0; i <= totalBlocks - numBlocks; ++i) {
        bool free = true;
        for (int j = 0; j < numBlocks; ++j) {
            if (usedBlocks[i + j]) {
                free = false;
                break;
            }
        }
        if (free) return i;
    }
    return -1;
}

void SimpleFS::create(const char* filename) {
    if (strlen(filename) >= FILENAME_LEN || findFileIndex(filename) != -1) {
        cout << "Dosya oluşturulamadı: geçersiz veya zaten mevcut." << endl;
        return;
    }

    for (int i = 0; i < MAX_FILES; ++i) {
        if (!metadata[i].valid) {
            metadata[i].start_block = findFreeBlock(1);
            if (metadata[i].start_block == -1) {
                cout << "Yeterli alan yok!" << endl;
                return;
            }
            strncpy(metadata[i].filename, filename, FILENAME_LEN - 1);
            metadata[i].filename[FILENAME_LEN - 1] = '\0';
            metadata[i].size = 0;
            metadata[i].created = time(nullptr);
            metadata[i].valid = true;
            saveMetadata();
            cout << "Dosya oluşturuldu: " << filename << endl;
            log(("Dosya oluşturuldu: " + string(filename)).c_str());
            return;
        }
    }
    cout << "Yeterli alan yok!" << endl;
}

void SimpleFS::remove(const char* filename) {
    int idx = findFileIndex(filename);
    if (idx == -1) {
        cout << "Dosya bulunamadı." << endl;
        return;
    }
    metadata[idx].valid = false;
    saveMetadata();
    cout << "Dosya silindi: " << filename << endl;
    log(("Dosya silindi: " + string(filename)).c_str());
}

void SimpleFS::fs_write(const char* filename, const char* data, int size) {
    int idx = findFileIndex(filename);
    if (idx == -1) {
        cout << "Dosya bulunamadı." << endl;
        return;
    }
    int block = metadata[idx].start_block;
    lseek(disk_fd, META_SIZE + block * BLOCK_SIZE, SEEK_SET);
    write(disk_fd, data, size);
    metadata[idx].size = size;
    saveMetadata();
    cout << "Yazma tamamlandı." << endl;
}

void SimpleFS::fs_read(const char* filename, int offset, int size, char* buffer) {
    int idx = findFileIndex(filename);
    if (idx == -1) {
        cout << "Dosya bulunamadı." << endl;
        return;
    }
    if (offset + size > metadata[idx].size) {
        cout << "Geçersiz okuma boyutu." << endl;
        return;
    }
    int block = metadata[idx].start_block;
    lseek(disk_fd, META_SIZE + block * BLOCK_SIZE + offset, SEEK_SET);
    read(disk_fd, buffer, size);
    buffer[size] = '\0';
}

void SimpleFS::list() {
    cout << "Diskteki dosyalar:" << endl;
    for (int i = 0; i < MAX_FILES; ++i) {
        if (metadata[i].valid) {
            cout << metadata[i].filename << "\t" << metadata[i].size << " bytes" << endl;
        }
    }
}

void SimpleFS::renameFile(const char* old_name, const char* new_name) {
    int idx = findFileIndex(old_name);
    if (idx == -1) {
        cout << "Dosya bulunamadı." << endl;
        return;
    }
    strncpy(metadata[idx].filename, new_name, FILENAME_LEN - 1);
    metadata[idx].filename[FILENAME_LEN - 1] = '\0';
    saveMetadata();
    cout << "Dosya ismi değiştirildi." << endl;
}

bool SimpleFS::exists(const char* filename) {
    return findFileIndex(filename) != -1;
}

int SimpleFS::size(const char* filename) {
    int idx = findFileIndex(filename);
    return idx != -1 ? metadata[idx].size : -1;
}

void SimpleFS::append(const char* filename, const char* data, int size) {
    int idx = findFileIndex(filename);
    if (idx == -1) return;
    int block = metadata[idx].start_block;
    lseek(disk_fd, META_SIZE + block * BLOCK_SIZE + metadata[idx].size, SEEK_SET);
    write(disk_fd, data, size);
    metadata[idx].size += size;
    saveMetadata();
}

void SimpleFS::truncate(const char* filename, int new_size) {
    int idx = findFileIndex(filename);
    if (idx == -1 || new_size > metadata[idx].size) return;
    metadata[idx].size = new_size;
    saveMetadata();
}

void SimpleFS::copy(const char* src, const char* dest) {
    int idx = findFileIndex(src);
    if (idx == -1) {
        cout << "Kaynak dosya bulunamadı." << endl;
        return;
    }

    create(dest);
    int dest_idx = findFileIndex(dest);
    if (dest_idx == -1) {
        cout << "Hedef dosya oluşturulamadı." << endl;
        return;
    }

    int size = metadata[idx].size;
    char* buf = new char[size];

    // Kaynak dosyadan oku
    fs_read(src, 0, size, buf);
    // Hedef dosyaya yaz
    fs_write(dest, buf, size);

    delete[] buf;
}

void SimpleFS::defragment() {
    // Basitleştirilmiş defragment
    cout << "Defragment yapılmadı (şu anda desteklenmiyor)." << endl;
}

void SimpleFS::backup(const char* backup_filename) {
    ifstream src("disk.sim", ios::binary);
    if (!src) {
        cerr << "Yedekleme başarısız: disk.sim dosyası açılamadı." << endl;
        return;
    }

    ofstream dest(backup_filename, ios::binary);
    if (!dest) {
        cerr << "Yedekleme başarısız: Hedef dosya açılamadı." << endl;
        return;
    }

    dest << src.rdbuf();
    cout << "Yedekleme tamamlandı: " << backup_filename << endl;
}

void SimpleFS::restore(const char* backup_filename) {
    ifstream src(backup_filename, ios::binary);
    if (!src) {
        cerr << "Geri yükleme başarısız: Yedek dosyası açılamadı." << endl;
        return;
    }

    ofstream dest("disk.sim", ios::binary);
    if (!dest) {
        cerr << "Geri yükleme başarısız: disk.sim dosyası yazılamadı." << endl;
        return;
    }

    dest << src.rdbuf();
    cout << "Geri yükleme tamamlandı." << endl;
}

void SimpleFS::cat(const char* filename) {
    int size = this->size(filename);
    if (size <= 0) return;
    char* buf = new char[size + 1];
    fs_read(filename, 0, size, buf);
    cout << buf << endl;
    delete[] buf;
}

bool SimpleFS::diff(const char* f1, const char* f2) {
    int s1 = size(f1), s2 = size(f2);
    if (s1 != s2) return false;

    char* b1 = new char[s1];
    char* b2 = new char[s2];
    fs_read(f1, 0, s1, b1);
    fs_read(f2, 0, s2, b2);

    bool equal = memcmp(b1, b2, s1) == 0;

    delete[] b1;
    delete[] b2;
    return equal;
}

void SimpleFS::log(const char* message) {
    ofstream logFile("fs.log", ios::app);
    time_t now = time(nullptr);
    logFile << "[" << ctime(&now) << "] " << message << endl;
}
