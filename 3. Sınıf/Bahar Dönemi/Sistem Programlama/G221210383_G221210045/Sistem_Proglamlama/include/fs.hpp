#ifndef FS_HPP
#define FS_HPP

#include <ctime>

#define MAX_FILES 64
#define FILENAME_LEN 32
#define BLOCK_SIZE 512
#define DISK_SIZE (1024 * 1024) // 1MB
#define META_SIZE 4096
#define DATA_START META_SIZE

struct FileEntry {
    char filename[FILENAME_LEN];
    int size;
    int start_block;
    time_t created;
    bool valid;
};

class SimpleFS {
public:
    SimpleFS(const char* diskName = "disk.sim");
    ~SimpleFS();

    void format();
    void create(const char* filename);
    void remove(const char* filename);
    void fs_write(const char* filename, const char* data, int size);
    void fs_read(const char* filename, int offset, int size, char* buffer);
    void list();
    void renameFile(const char* old_name, const char* new_name);
    bool exists(const char* filename);
    int size(const char* filename);
    void append(const char* filename, const char* data, int size);
    void truncate(const char* filename, int new_size);
    void copy(const char* src_filename, const char* dest_filename);
    void defragment();
    void backup(const char* backup_filename);
    void restore(const char* backup_filename);
    void cat(const char* filename);
    bool diff(const char* file1, const char* file2);

private:
    int disk_fd;
    FileEntry metadata[MAX_FILES];

    void loadMetadata();
    void saveMetadata();
    int findFreeBlock(int size);
    int findFileIndex(const char* filename);
    void log(const char* message);
};

#endif
