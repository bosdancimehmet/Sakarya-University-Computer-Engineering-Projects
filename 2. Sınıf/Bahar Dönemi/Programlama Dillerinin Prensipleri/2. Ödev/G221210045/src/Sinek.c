#include "Sinek.h"
#include <stdlib.h>
Sinek new_Sinek(int sayi) {
    Sinek this;
    this = (Sinek)malloc(sizeof(struct SINEK));
	if (!this) return NULL;
    this->super = new_Bocek(sayi);
    this->super->super->gorunum = &gorunum_Sinek;
    this->delete_Sinek = &delete_Sinek;
    return this;
}

char* gorunum_Sinek() {
    return "S";
}

void delete_Sinek(Sinek this) {
    if (!this) return;
    delete_Bocek(this->super);
    free(this);
}