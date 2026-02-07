#ifndef BITKI_H
#define BITKI_H

#include "Canli.h"

// Bitki Canli'dan kalıtım alacak
struct BITKI {
    Canli super;
    void (*delete_Bitki)(struct BITKI*);
};

typedef struct BITKI* Bitki;

Bitki new_Bitki(int);
char* gorunum_Bitki();
void delete_Bitki(const Bitki);

#endif