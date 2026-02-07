/** 
* @file: main
* @description: gereken fonksiyonları mainde çağırdım
* @course: veri yapıları 2-B
* @assignment: 1.Ödev
* @date 25.11.2023
* @author Mehmet Bosdancı G221210045
*/
#include<iostream>
#include <fstream>
#include <cctype>//isdigit için gerekli
#include <string>
#include "Sayi.hpp"
#include "SayilarListesi.hpp"
using namespace std;
int main()
{
	
	SayilarListesi liste ;
	
	ifstream dosyaoku("Sayilar.txt", ios::in);//dosyayı okuma modunda aç
	char karakter;
    string sayiMetni;
	
    while (dosyaoku.get(karakter)) {
        if (isdigit(karakter)) {
            // Eğer karakter bir rakam ise sayı metni üzerine ekle yaparız
            sayiMetni += karakter;
        } else if (!sayiMetni.empty()) {
            // Eğer sayiMetni boş değilse bir tamsayı vardır
			Sayi* say = new Sayi();
            int sayi = stoi(sayiMetni);
			say->ekleTekerTeker(sayi);
			liste.ekleDugum(say);
            sayiMetni=""; // Sayi metnini temizle	
        }
    }

    // Dosyadan kalan son sayıyı ele almak için
	
    if (!sayiMetni.empty()) {
        Sayi* say = new Sayi();
        int sayi = stoi(sayiMetni);
		say->ekleTekerTeker(sayi);
		liste.ekleDugum(say);
    }

    dosyaoku.close();
	
	
	liste.ortakYazdir();
	while(1){
		cout<<"1.Tek basamaklari basa al"<<endl<<"2.Basamaklari tersle"<<endl<<"3.En buyuk cikar"<<endl<<"4.Cikis"<<endl;
		char secim;
		cin>>secim;
		if(secim == '1'){
			liste.tekleriBasaAl();
			liste.ortakYazdir();
		}
		if(secim == '2'){
			cout<<endl;	
			liste.ortakYazdir(true);
		}
		if(secim =='3'){
			liste.enBuyukCikar();
			liste.ortakYazdir();
		}
		if(secim == '4'){
			exit(0);
		}
	}
	return 0;
}