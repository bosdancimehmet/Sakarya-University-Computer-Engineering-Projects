#ifndef HABITAT_H
#define HABITAT_H

#include "Bitki.h"
#include "Bocek.h"
#include "Sinek.h"
#include "Pire.h"

struct HABITAT{
    Canli**matris;
    int satir_sayisi;
    int sutun_sayisi;
	
	void (*basla_Habitat)(struct HABITAT*);
	void (*yemek_Habitat)(struct HABITAT*);
	void (*yazdir_Habitat)(struct HABITAT*);
	void (*delete_Habitat)(struct HABITAT*);
};

typedef struct HABITAT* Habitat;

Habitat new_Habitat(const char*);
void basla_Habitat(const Habitat);
void yemek_Habitat(Habitat);
void yazdir_Habitat(const Habitat);
void delete_Habitat(const Habitat);

#endif