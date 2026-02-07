#ifndef BOCEK_H
#define BOCEK_H

#include "Canli.h"

// Böcek Canli'dan kalıtım alacak
struct BOCEK {
    Canli super;
    void (*delete_Bocek)(struct BOCEK*);
};

typedef struct BOCEK* Bocek;

Bocek new_Bocek(int);
char* gorunum_Bocek();
void delete_Bocek(Bocek);

#endif