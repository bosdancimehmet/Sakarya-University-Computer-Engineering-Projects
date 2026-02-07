#include "Bocek.h"
#include <stdlib.h>

Bocek new_Bocek(int sayi) {
    Bocek this;
    this = (Bocek)malloc(sizeof(struct BOCEK));
    this->super = new_Canli(sayi);
    this->super->gorunum = &gorunum_Bocek;
    this->delete_Bocek = &delete_Bocek;
    return this;
}

char* gorunum_Bocek() {
    return "C";
}

void delete_Bocek(Bocek this) {
    if (!this) return;
    delete_Canli(this->super);
    free(this);
}