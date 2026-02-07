#include "Pire.h"
#include <stdlib.h>
Pire new_Pire(int sayi) {
    Pire this;
    this = (Pire)malloc(sizeof(struct PIRE));
    this->super = new_Bocek(sayi);
    this->super->super->gorunum = &gorunum_Pire;
    this->delete_Pire = &delete_Pire;
    return this;
}

char* gorunum_Pire() {
    return "P";
}

void delete_Pire(const Pire this) {
    if (this == NULL) return;
    delete_Bocek(this->super);
    free(this);
}