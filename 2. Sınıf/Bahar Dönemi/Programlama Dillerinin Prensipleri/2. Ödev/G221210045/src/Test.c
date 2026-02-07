#include "Habitat.h"
#include <stdio.h>
int main(){
    Habitat habitat = new_Habitat("Veri.txt");
    habitat->basla_Habitat(habitat);
    habitat->delete_Habitat(habitat);

    return 0;
}