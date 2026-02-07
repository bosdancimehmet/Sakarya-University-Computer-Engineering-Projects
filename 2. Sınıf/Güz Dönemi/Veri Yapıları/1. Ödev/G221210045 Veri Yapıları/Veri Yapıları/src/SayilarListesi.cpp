/** 
* @file: main
* @description: Düğümlerden oluşan bağlı liste burada bulunur ve SayilarListesi.hpp'nin fonksiyon gövdeleri dolduruldu
* @course: veri yapıları 2-B
* @assignment: 1.Ödev
* @date 25.11.2023
* @author Mehmet Bosdancı G221210045
*/
#include "SayilarListesi.hpp"
#include "Dugum.hpp"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
SayilarListesi::SayilarListesi(){
	this->head=NULL;
}
SayilarListesi::~SayilarListesi(){
	while(head!=NULL){
		Dugum* temp =head;
		head=head->next;
		delete temp;
	}
}
void SayilarListesi::ekleDugum(Sayi* value){
	Dugum* yeniDugum = new Dugum(value);
	if(head==NULL){
		head=yeniDugum;
		head->next=NULL;
	}
	else{
		Dugum* temp =head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=yeniDugum;
		yeniDugum->next=NULL;
	}
			
}


void SayilarListesi::ortakYazdir(){
	Dugum* tempDugum = head;
	int basamakAdet;
	while(tempDugum != NULL){
		basamakAdet = tempDugum->sayi->basSayisi();
		//sekilYazdir(basamakAdet);
		//
		cout<<"###########"<<"   ";
		for(int i=0; i<basamakAdet;i++){
		cout<<"*******"<<"   ";
		}
			cout<<endl;
		//
		cout << "#" <<setw(9)<< tempDugum->sayi << "#" ;	
		Basamak* tempBasamak = tempDugum->sayi->getHead();
		
		while (tempBasamak != nullptr) {
			//adresin son 3ünü alma 
			uintptr_t adres = reinterpret_cast<uintptr_t>(tempBasamak);
			int sonUcHane = adres % 1000;
			
            cout << setw(4)<<"*" <<hex <<setw(4) << sonUcHane <<dec<<" *" ;
			tempBasamak = tempBasamak->next;
        }
		
		cout<<endl;	
			//sekilYazdir(basamakAdet);
			//
			cout<<"#---------#"<<"   ";
			for(int i=0; i<basamakAdet;i++){
			cout<<"*******"<<"   ";
			}
			cout<<endl;
			//
            cout << "#";
			
			tempDugum->sayi->yazdirSayi();
			
			cout <<right<<setw(10-tempDugum->sayi->basSayisi())<< "#";
			
			tempBasamak = tempDugum->sayi->getHead();
			//
			while (tempBasamak != NULL) {
            cout << setw(4)<<"*" <<hex <<setw(3) << tempBasamak->data<<" " <<dec<<" *" ;    
                tempBasamak = tempBasamak->next;
            }
			cout << endl;
			//sekilYazdir(basamakAdet);
            //
			cout<<"###########"<<"   ";
			for(int i=0; i<basamakAdet;i++){
			cout<<"*******"<<"   ";
			}
			cout<<endl;
			//
           
			
            cout << endl;
            tempDugum = tempDugum->next;
	}
}	

void SayilarListesi::ortakYazdir(bool tersCevirilmis) {
        Dugum* tempDugum = head;
		int basamakAdet;
		
        while (tempDugum != NULL) {
			
            basamakAdet=tempDugum->sayi->basSayisi();
			
			//yazdir(basamakadeti);
			//
			cout<<"###########"<<"   ";
			for(int i=0; i<basamakAdet;i++){
			cout<<"*******"<<"   ";
			}
			cout<<endl;
			//
			
            cout << "#" <<setw(9)<< tempDugum->sayi << "#" ;
			//
			
			if (tersCevirilmis) {
                tempDugum->sayi->TersCevir();
            }
			
			Basamak* tempBasamak = tempDugum->sayi->getHead();
			
			 while (tempBasamak != NULL) {
                uintptr_t adres = reinterpret_cast<uintptr_t>(tempBasamak);
				int sonUcHane = adres % 1000;
			
				cout << setw(4)<<"*" <<hex <<setw(4) << sonUcHane <<dec<<" *" ;
                tempBasamak = tempBasamak->next;
            }
			
			cout<<endl;
			
			//sekilYazdir(basamakAdet);
			//
			cout<<"#---------#"<<"   ";
			for(int i=0; i<basamakAdet;i++){
			cout<<"*******"<<"   ";
			}
			cout<<endl;
			//
            cout << "#";
			
			tempDugum->sayi->yazdirSayi();
			
			cout <<right<<setw(10-tempDugum->sayi->basSayisi())<< "#";
			
			tempBasamak = tempDugum->sayi->getHead();
			//
			
			while (tempBasamak != NULL) {
				cout << setw(4)<<"*" <<hex <<setw(3) << tempBasamak->data<<" " <<dec<<" *" ;
                tempBasamak = tempBasamak->next;
            }
			cout << endl;
			
            //sekilYazdir(basamakAdet);
			//
			cout<<"###########"<<"   ";
			for(int i=0; i<basamakAdet;i++){
			cout<<"*******"<<"   ";
			}
			cout<<endl;
			//

            cout << endl;
            tempDugum = tempDugum->next;
        }
}

//
//
void SayilarListesi::tekleriBasaAl() {
    Dugum* tempDugum = head;
    while (tempDugum != NULL) {
        Basamak* tempBasamak = tempDugum->sayi->getHead();
        Basamak* tekBasamaklar = NULL;
        Basamak* ciftBasamaklar = NULL;
        Basamak* sonTekBasamak = NULL;
        Basamak* sonCiftBasamak = NULL;

        while (tempBasamak != NULL) {
            Basamak* temp = tempBasamak;
            tempBasamak = tempBasamak->next;
            temp->next = NULL;

            if (temp->data % 2 == 1) {
                if (tekBasamaklar == NULL) {
                    tekBasamaklar = temp;
                    sonTekBasamak = temp;
                } else {
                    sonTekBasamak->next = temp;
                    sonTekBasamak = temp;
                }
            } else {
                if (ciftBasamaklar == nullptr) {
                    ciftBasamaklar = temp;
                    sonCiftBasamak = temp;
                } else {
                    sonCiftBasamak->next = temp;
                    sonCiftBasamak = temp;
                }
            }
        }

        if (tekBasamaklar != NULL) {
            sonTekBasamak->next = ciftBasamaklar;
            tempDugum->sayi->head = tekBasamaklar;
			
        } else {
            tempDugum->sayi->head = ciftBasamaklar;
        }

        tempDugum = tempDugum->next;
    }
}



void SayilarListesi::enBuyukCikar() {
    if (head == NULL) {
        cout << "Liste bos." << endl;
        return;
    }

    Dugum* enBuyukDugum = head;
    Dugum* simdikiDugum = head->next;
    int enBuyukDeger = enBuyukDugum->sayi->BasamaklarinDegeriniAl();

    while (simdikiDugum != NULL) {
        int sayiDegeri = simdikiDugum->sayi->BasamaklarinDegeriniAl();

        if (sayiDegeri > enBuyukDeger) {
            enBuyukDeger = sayiDegeri;
            enBuyukDugum = simdikiDugum;
        }

        simdikiDugum = simdikiDugum->next;
    }

    if (enBuyukDugum == head) {
        head = enBuyukDugum->next;
    } else {
        Dugum* oncekiDugum = head;
        while (oncekiDugum->next != enBuyukDugum) {
            oncekiDugum = oncekiDugum->next;
        }
        oncekiDugum->next = enBuyukDugum->next;
    }

    int silinenDeger = enBuyukDeger; // Silinen değeri kaydetme
    cout << "En buyuk sayi degeri olan dugum silindi. Silinen Deger: " << silinenDeger << endl;
    delete enBuyukDugum;

}