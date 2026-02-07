#ifndef CANLI_H
#define CANLI_H

struct CANLI {
    char* (*gorunum)();
	char* (*dead)();
    void (*delete_Canli)(struct CANLI*);
	int number;
    char* alive;
};

typedef struct CANLI* Canli;

Canli new_Canli(int);
char* dead();
void delete_Canli(Canli);

#endif