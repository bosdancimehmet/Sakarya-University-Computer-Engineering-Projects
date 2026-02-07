#ifndef SAYILARLISTESI_HPP
#define SAYILARLISTESI_HPP
#include "Dugum.hpp"
class SayilarListesi
{
	private:
		Dugum* head;//SayilarListesi bağlı listesinin ilk node'u
	public:
		SayilarListesi();
		~SayilarListesi();
		void ekleDugum(Sayi* value);
		void ortakYazdir();
		void ortakYazdir(bool tersCevrilmis);
		void tekleriBasaAl();
		void enBuyukCikar();
};
#endif
