/** 
* @file: Sayi
* @description: Sayi.hpp'nin fonksiyon gövdeleri dolduruldu
* @course: veri yapıları 2-B
* @assignment: 1.Ödev
* @date 25.11.2023
* @author Mehmet Bosdancı G221210045
*/
#include "Sayi.hpp"
#include <iostream>
#include <iomanip>
using namespace std;
Sayi::Sayi(){
	this->head = NULL;
}
Sayi::~Sayi(){	
	while(head!=NULL){
		Basamak* temp =head;
		head=head->next;
		delete temp;
	}
}

void Sayi::ekleTekerTeker(int sayi){
	int rakamlar;
	string sayiMetni=to_string(sayi);
	for(int i=0;i<sayiMetni.length();i++){		
		rakamlar = sayiMetni[i]-'0';
		Basamak* yeniBasamak = new Basamak(rakamlar);
		if(head==NULL){
		head=yeniBasamak;
		yeniBasamak->next=NULL;
	}
	else{
		Basamak* temp =head;
		while(temp->next!=NULL){		
			temp=temp->next;	
		}
			temp->next=yeniBasamak;
			yeniBasamak->next=NULL;
		}
			
	}	
		
}
void Sayi::yazdirSayi() {
    Basamak* temp = head;
    while (temp != NULL) {
        cout<< temp->data;
		
        temp = temp->next;
    } 
}	
Basamak* Sayi::getHead(){
	return this->head;
}
int Sayi::basSayisi() const {
        int basSayisi = 0;
        Basamak* tempBasamak = head;

        while (tempBasamak != NULL) {
            basSayisi++;
            tempBasamak = tempBasamak->next;
        }

        return basSayisi;
    }
	
	
void Sayi::TersCevir() {
		Basamak* onceki = NULL;
		Basamak* simdiki = head;
		Basamak* sonraki = NULL;

		while (simdiki != NULL) {
        sonraki = simdiki->next;
        simdiki->next = onceki;
        onceki = simdiki;
        simdiki = sonraki;
		}

		head = onceki;
}	

int Sayi::BasamaklarinDegeriniAl() {
    int deger = 0;
    Basamak* tempBasamak = head;

    // basamakları düz sırada alma
    while (tempBasamak != NULL) {
        deger = deger * 10 + tempBasamak->data;
        tempBasamak = tempBasamak->next;
    }

    return deger;
}