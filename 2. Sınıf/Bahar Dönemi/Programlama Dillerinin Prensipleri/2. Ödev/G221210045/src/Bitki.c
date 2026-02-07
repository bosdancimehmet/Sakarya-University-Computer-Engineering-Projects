#include "Bitki.h"
#include <stdlib.h>
Bitki new_Bitki(int sayi) {
	Bitki this;
	this = (Bitki)malloc(sizeof(struct BITKI));
    if (!this) return NULL;
    this->super = new_Canli(sayi);
	this->super->gorunum = &gorunum_Bitki;
    this->delete_Bitki = &delete_Bitki;
    return this;
}

char* gorunum_Bitki() {
    return "B";
}

void delete_Bitki(Bitki this) {
    if (!this) return;
    delete_Canli(this->super);
    free(this);
}