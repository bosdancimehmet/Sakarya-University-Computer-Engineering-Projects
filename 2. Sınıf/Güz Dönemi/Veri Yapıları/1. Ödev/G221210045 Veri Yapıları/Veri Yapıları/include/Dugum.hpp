#ifndef DUGUM_HPP
#define DUGUM_HPP
#include "Sayi.hpp"
class Dugum
{
	public:
		Sayi* sayi;//bir bağlı listenin adresini içeriyor
		Dugum* next;//Bir sonraki Dugum node'unun adresini tutar
		Dugum(Sayi* value);//kurucu
};

#endif
