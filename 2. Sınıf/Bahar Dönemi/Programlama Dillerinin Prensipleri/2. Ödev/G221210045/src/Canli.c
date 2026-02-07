#include "Canli.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Canli new_Canli(int number) {
    Canli this = malloc(sizeof(struct CANLI));
    if (!this) return NULL;
    this->dead = &dead;
	this->number = number;
	this->delete_Canli = &delete_Canli;
	this->alive = "y";
    return this;
}

char* dead() {
    return "X";
}

void delete_Canli(Canli this) {
    if (!this) return;
    free(this->alive);
    free(this);
}