#include "Habitat.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Habitat olustur fonksiyonu
Habitat new_Habitat(const char* dosya_adi) {
    Habitat this = malloc(sizeof(struct HABITAT));
    if (!this) return NULL;

    // Dosyayı oku ve matrisi oluştur
    FILE* dosya = fopen(dosya_adi, "r");
    if (!dosya) {
        printf("Dosya acilamadi!");
        exit(1);
    }

    int satir_sayisi = 0;
    int sutun_sayisi = 0;
    char c;
    //satır ve sütun sayılarını belirleme işi
    while ((c = fgetc(dosya)) != EOF) {
        if (c == '\n') {
            satir_sayisi++;
            // Her yeni satırda sütun sayısını sıfırla
            sutun_sayisi = 0;
        } else if (c == ' ') {
            // Boşluk karakterleri sütun sayısını belirlemek için kullanılıyor
            sutun_sayisi++;
        }
    }
    // Son satırın da bitiş karakteri (\n) dir
    // Eğer dosyanın sonunda satır sonu yoksa son satırı da sayıyoruz
    if (c != '\n') {
        satir_sayisi++;
    }
    // En az bir sütun olacak şekilde son sütun sayısını da ekliyoruz
    sutun_sayisi++;
	rewind(dosya); // Dosya imlecini başa al
	this->satir_sayisi = satir_sayisi;
	this->sutun_sayisi = sutun_sayisi;
	// Matrisi oluştur ve doldur
    this->matris = (Canli**)malloc(sizeof(Canli*) * this->satir_sayisi);
    for (int i = 0; i < this->satir_sayisi; i++) {
		this->matris[i] = (Canli*)malloc(sizeof(Canli) * this->sutun_sayisi);
        for (int j = 0; j < this->sutun_sayisi; j++) {
            int num;
            if (fscanf(dosya, "%d", &num) != 1) {
                printf("Dosyadan okuma hatası!\n");
                fclose(dosya);
                delete_Habitat(this);  // Belleği temizle ve çık
                return NULL;
            }
            // Canlı nesnelerini oluştur
            if (num >= 1 && num <= 9) {
				Bitki bitki = new_Bitki(num);
                this->matris[i][j] = bitki->super;
            } else if (num >= 10 && num <= 20) {
				Bocek bocek = new_Bocek(num);
                this->matris[i][j] = bocek->super;
            } else if (num >= 21 && num <= 50) {
				Sinek sinek = new_Sinek(num);
                this->matris[i][j] = sinek->super->super;
            } else if (num >= 51 && num <= 99) {
				Pire pire = new_Pire(num);
                this->matris[i][j] = pire->super->super;
            }
        }
		printf("\n");
    }
    fclose(dosya);
    // İşlevleri oluşturuyoruz
    this->basla_Habitat = &basla_Habitat;
    this->yemek_Habitat = &yemek_Habitat;
    this->yazdir_Habitat = &yazdir_Habitat;
    this->delete_Habitat = &delete_Habitat;
    return this;
}

// Habitat basla fonksiyonu
void basla_Habitat(const Habitat this){
	system("cls");
    yazdir_Habitat(this);
	printf("Devam etmek icin enter'a basiniz...\n");
    getchar(); // Kullanıcının bir tuşa basmasını bekler
    yemek_Habitat(this);
}

// Habitat yemek fonksiyonu
void yemek_Habitat(Habitat this) {
    int hayatta_kalan_sayisi = this->satir_sayisi * this->sutun_sayisi;
	Canli* canli1=NULL;
	Canli* canli2=NULL;
	while (hayatta_kalan_sayisi > 1) {
		canli1=NULL;
		canli2=NULL;
		int canli1Bulundu = 0;
		int canli2Bulundu = 0;
		//canli1 bulma işlemi
		for (int i = 0; i < this->satir_sayisi; i++) {
			for (int j = 0; j < this->sutun_sayisi; j++) {
				if (strcmp(this->matris[i][j]->alive, "y") == 0) {
					canli1 = &this->matris[i][j];
					canli1Bulundu = 1;
					break; // İlk uygun canlıyı bulduğunuzda döngüden çıksın
				}
			}
			if (canli1Bulundu) {
				break; // canli1 bulunduğunda dıştaki döngüden de çıksın
			}
		}
		//canli2 bulma işlemi
		for (int i = 0; i < this->satir_sayisi; i++) {
			for (int j = 0; j < this->sutun_sayisi; j++) {
					if(strcmp(this->matris[i][j]->alive, "y") == 0){
						if((this->matris[i][j]) != *canli1){
							canli2 = &this->matris[i][j];
						canli2Bulundu = 1;
						break; // İkinci uygun canlıyı bulduğunda döngüden çıksın
						}
					}
			}
			if (canli2Bulundu) {
				break; 
			}
		}
		
		//Bitki Pireyi yer
		if (strcmp((*canli1)->gorunum(), "B") == 0 && strcmp((*canli2)->gorunum(), "P") == 0) {
			(*canli2)->alive = "n";
		}
		else if (strcmp((*canli1)->gorunum(), "P") == 0 && strcmp((*canli2)->gorunum(), "B") == 0) {
			(*canli1)->alive = "n";
		}
		
		//Böcek Bitkiyi yer
		else if (strcmp((*canli1)->gorunum(), "C") == 0 && strcmp((*canli2)->gorunum(), "B") == 0) {
			(*canli2)->alive = "n";
		}
		else if (strcmp((*canli1)->gorunum(), "B") == 0 && strcmp((*canli2)->gorunum(), "C") == 0) {
			(*canli1)->alive = "n";
		}
		
		//Sinek Pireyi yer
		else if (strcmp((*canli1)->gorunum(), "S") == 0 && strcmp((*canli2)->gorunum(), "P") == 0) {
			(*canli2)->alive = "n";
		}
		else if (strcmp((*canli1)->gorunum(), "P") == 0 && strcmp((*canli2)->gorunum(), "S") == 0) {
			(*canli1)->alive = "n";
		}
		
		//Bitki sineği yer
		else if (strcmp((*canli1)->gorunum(), "B") == 0 && strcmp((*canli2)->gorunum(), "S") == 0) {
			(*canli2)->alive = "n";
		}
		else if (strcmp((*canli1)->gorunum(), "S") == 0 && strcmp((*canli2)->gorunum(), "B") == 0) {
			(*canli1)->alive = "n";
		}
		
		//Sinek Böceği yer
		else if (strcmp((*canli1)->gorunum(), "S") == 0 && strcmp((*canli2)->gorunum(), "C") == 0) {
			(*canli2)->alive = "n";
		}
		else if (strcmp((*canli1)->gorunum(), "C") == 0 && strcmp((*canli2)->gorunum(), "S") == 0) {
			(*canli1)->alive = "n";
		}
		
		//Böcek Pireyi yer
		else if (strcmp((*canli1)->gorunum(), "C") == 0 && strcmp((*canli2)->gorunum(), "P") == 0) {
			(*canli2)->alive = "n";
		}
		else if (strcmp((*canli1)->gorunum(), "P") == 0 && strcmp((*canli2)->gorunum(), "C") == 0) {
			(*canli1)->alive = "n";
		}
		
		//Bitki Bitkiyle karşılaşırsa sayısal değeri büyük olan kazanır
		else if (strcmp((*canli1)->gorunum(), "B") == 0 && strcmp((*canli2)->gorunum(), "B") == 0) {
			if(!((*canli1)->number > (*canli2)->number)){
				(*canli1)->alive = "n";
			}
			else if(!((*canli1)->number < (*canli2)->number)){
				(*canli2)->alive = "n";
			}
			else{
				(*canli2)->alive = "n";
			}	
		}
		//Böcek Böcekle karşılaşırsa sayısal değeri büyük olan kazanır
		else if (strcmp((*canli1)->gorunum(), "C") == 0 && strcmp((*canli2)->gorunum(), "C") == 0) {
			if(!((*canli1)->number > (*canli2)->number)){
				(*canli1)->alive = "n";
			}
			else if(!((*canli1)->number < (*canli2)->number)){
				(*canli2)->alive = "n";
			}
			else{
				(*canli2)->alive = "n";
			}	
		}
		//Sinek Sinekle karşılaşırsa sayısal değeri büyük olan kazanır
		else if (strcmp((*canli1)->gorunum(), "S") == 0 && strcmp((*canli2)->gorunum(), "S") == 0) {
			if(!((*canli1)->number > (*canli2)->number)){
				(*canli1)->alive = "n";
			}
			else if(!((*canli1)->number < (*canli2)->number)){
				(*canli2)->alive = "n";
			}
			else{
				(*canli2)->alive = "n";
			}	
		}
		//Pire Pireyle karşılaşırsa sayısal değeri büyük olan kazanır
		else if (strcmp((*canli1)->gorunum(), "P") == 0 && strcmp((*canli2)->gorunum(), "P") == 0) {
			if(!((*canli1)->number > (*canli2)->number)){
				(*canli1)->alive = "n";
			}
			else if(!((*canli1)->number < (*canli2)->number)){
				(*canli2)->alive = "n";
			}
			else{
				(*canli2)->alive = "n";
			}	
		}
		hayatta_kalan_sayisi--;
		yazdir_Habitat(this);
		system("cls");
	}
	
		yazdir_Habitat(this);
		printf("\nKazanan: ");
		int yatay = 0;
		int dusey = 0;
		for(int i = 0; i < this->satir_sayisi; i++){
			for(int j = 0; j < this->sutun_sayisi; j++){
				if (this->matris[i][j] != NULL) {
					if(strcmp(this->matris[i][j]->alive, "y") == 0){
						printf("%s ", this->matris[i][j]->gorunum());
						dusey = i;
						yatay = j;
					}
				}
			}
		}
		printf(": (%d,%d)",dusey,yatay);
}



// Habitat yazdir fonksiyonu
void yazdir_Habitat(const Habitat this){
	printf("\n");
    // Matrisi ekrana yazdırıyoruz
    for(int i = 0; i < this->satir_sayisi; i++){
        for(int j = 0; j < this->sutun_sayisi; j++){
            if (this->matris[i][j] != NULL) {
				if(strcmp(this->matris[i][j]->alive, "y") == 0){
					printf("%s ", this->matris[i][j]->gorunum());
				}
				else if(strcmp(this->matris[i][j]->alive, "n") == 0){
					printf("%s ", this->matris[i][j]->dead());
				}
            } else {
                printf("NULL ");
            }
        }
        printf("\n");
    }
}

// Habitat yıkıcı fonksiyonu
void delete_Habitat(const Habitat this) {
    if (this == NULL) return;
	Bitki bitki = new_Bitki(5);
	Bocek bocek = new_Bocek(15);
	Sinek sinek = new_Sinek(30);
	Pire pire = new_Pire(60);
    for (int i = 0; i < this->satir_sayisi; i++) {
		for(int j = 0; j < this->sutun_sayisi; j++){
			if(this->matris[i][j] == NULL){
				if (strcmp(this->matris[i][j]->gorunum(), "B") == 0) {
					bitki->super = this->matris[i][j];
					delete_Bitki(bitki);
				}
				else if (strcmp(this->matris[i][j]->gorunum(), "C") == 0) {
					bocek->super = this->matris[i][j];
					delete_Bocek(bocek);
				}
				else if (strcmp(this->matris[i][j]->gorunum(), "S") == 0) {
					sinek->super->super = this->matris[i][j];
					delete_Sinek(sinek);
				}
				else if (strcmp(this->matris[i][j]->gorunum(), "P") == 0) {
					pire->super->super = this->matris[i][j];
					delete_Pire(pire);
				}
				delete_Canli(this->matris[i][j]);
			}
			
			
		}
    }
    free(sinek);
    free(pire);
    free(bocek);
	free(bitki);
    free(this->matris);
    free(this);

}