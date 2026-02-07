#ifndef SAYI_HPP
#define SAYI_HPP
#include "Basamak.hpp"
//Basamak node'larına ait bağlı liste
class Sayi
{
	public:
		Basamak* head;//Sayi listesinin ilk düğümü
		Sayi();//kurucu
		~Sayi();//yıkıcı
		void yazdirSayi();
		void ekleTekerTeker(int sayi);
		Basamak* getHead();
		int basSayisi() const;
		void TersCevir(); 
		int BasamaklarinDegeriniAl ();
};
#endif
