#ifndef PIRE_H
#define PIRE_H

#include "Bocek.h"

// Pire Bocek'ten kalıtım alacak
struct PIRE {
    Bocek super;
    void (*delete_Pire)(struct PIRE*);
};

typedef struct PIRE* Pire;

Pire new_Pire(int);
char* gorunum_Pire();
void delete_Pire(const Pire);

#endif