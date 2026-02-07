#ifndef SINEK_H
#define SINEK_H

#include "Bocek.h"

// Sinek Bocek'ten kalıtım alacak
struct SINEK {
    Bocek super;
    void (*delete_Sinek)(struct SINEK*);
};

typedef struct SINEK* Sinek;

Sinek new_Sinek(int);
char* gorunum_Sinek();
void delete_Sinek(Sinek);

#endif