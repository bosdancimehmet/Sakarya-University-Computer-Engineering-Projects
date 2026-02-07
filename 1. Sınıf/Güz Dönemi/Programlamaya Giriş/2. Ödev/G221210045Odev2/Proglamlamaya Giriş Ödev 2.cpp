/****************************************************************************
**					       SAKARYA ÜNÝVERSÝTESÝ                             *
**			         BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ              *
**				    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ                          *
**				          PROGRAMLAMAYA GÝRÝÞÝ DERSÝ                        *
**                                                                          *
**				ÖDEV NUMARASI…............: 2                               *
**				ÖÐRENCÝ ADI...............: MEHMET BOSDANCI                 *
**				ÖÐRENCÝ NUMARASI..........: G221210045                      *
**				DERS GRUBU…………............: 2.Öðretim B grubu               *
****************************************************************************/

#include<iostream>
#include<locale.h>//setlocale için
#include<iomanip>//setw için
#include<cmath>
using namespace std;


class KarmasikSayi
{
private:
	double reel;
	double sanal;
public:
	void SetReel(double _reel);
	double Getreel();
	void SetSanal(double _sanal);
	double GetSanal();
	void BilgiGoster();
};
KarmasikSayi operator + (KarmasikSayi k1, KarmasikSayi k2);
void KarmasikSayi::SetReel(double _reel)
{
	reel = _reel;
}

double KarmasikSayi::Getreel()
{
	return reel;
}

void KarmasikSayi::SetSanal(double _sanal)
{
	sanal = _sanal;
}

double KarmasikSayi::GetSanal()
{
	return sanal;
}

void KutupsalGosterim(KarmasikSayi obje1, KarmasikSayi obje2)
{
	float R1, R2;
	R1 = pow(obje1.Getreel() * obje1.Getreel() + obje1.GetSanal() * obje1.GetSanal(), 0.5);
	R2 = pow(obje2.Getreel() * obje2.Getreel() + obje2.GetSanal() * obje2.GetSanal(), 0.5);
	cout << left << setw(11) << "R UZUNLUÐU" << left << setw(10) << "\tNOKTASI" << endl;
	cout << left << setw(3) << "K1:" << setw(10) << R1 << "\t(" << obje1.Getreel() << "," << obje1.GetSanal() << ")" << endl;
	cout << left << setw(3) << "K2:" << setw(10) << R2 << "\t(" << obje2.Getreel() << "," << obje2.GetSanal() << ")" << endl;
	float x_ekseniyle_yaptigi_pozitif_aci;
}

KarmasikSayi operator + (KarmasikSayi k1, KarmasikSayi k2)
{
	KarmasikSayi Sonuc;
	Sonuc.SetReel(k1.Getreel() + k2.Getreel());
	Sonuc.SetSanal(k1.GetSanal() + k2.GetSanal());
	return Sonuc;
}

KarmasikSayi operator - (KarmasikSayi k1, KarmasikSayi k2)
{
	KarmasikSayi Sonuc;
	Sonuc.SetReel(k1.Getreel() - k2.Getreel());
	Sonuc.SetSanal(k1.GetSanal() - k2.GetSanal());
	return Sonuc;
}

KarmasikSayi operator * (KarmasikSayi k1, KarmasikSayi k2)
{
	KarmasikSayi Sonuc;
	Sonuc.SetReel((k1.Getreel() * k2.Getreel()) - (k1.GetSanal() * k2.GetSanal()));
	Sonuc.SetSanal((k1.Getreel() * k2.GetSanal()) + (k1.GetSanal() * k2.Getreel()));
	return Sonuc;
}

KarmasikSayi operator / (KarmasikSayi k1, KarmasikSayi k2)
{
	KarmasikSayi Sonuc;
	Sonuc.SetReel(((k1.Getreel() * k2.Getreel()) + (k1.GetSanal() * k2.GetSanal())) / ((k2.Getreel() * k2.Getreel()) + (k2.GetSanal() * k2.GetSanal())));
	Sonuc.SetSanal(((k1.GetSanal() * k2.Getreel()) - (k1.Getreel() * k2.GetSanal())) / ((k2.Getreel() * k2.Getreel()) + (k2.GetSanal() * k2.GetSanal())));
	return Sonuc;
}

KarmasikSayi operator += (KarmasikSayi k1, KarmasikSayi k2)
{
	KarmasikSayi Sonuc;
	Sonuc.SetReel(k1.Getreel() + k2.Getreel());
	Sonuc.SetSanal(k1.GetSanal() + k2.GetSanal());
	Sonuc.BilgiGoster();
	return Sonuc;
}

KarmasikSayi operator -= (KarmasikSayi k1, KarmasikSayi k2)
{
	KarmasikSayi Sonuc;
	Sonuc.SetReel(k1.Getreel() - k2.Getreel());
	Sonuc.SetSanal(k1.GetSanal() - k2.GetSanal());
	Sonuc.BilgiGoster();
	return Sonuc;
}

KarmasikSayi operator *= (KarmasikSayi k1, KarmasikSayi k2)
{
	KarmasikSayi Sonuc;
	Sonuc.SetReel((k1.Getreel() * k2.Getreel()) - (k1.GetSanal() * k2.GetSanal()));
	Sonuc.SetSanal((k1.Getreel() * k2.GetSanal()) + (k1.GetSanal() * k2.Getreel()));
	Sonuc.BilgiGoster();
	return Sonuc;
}

KarmasikSayi operator /= (KarmasikSayi k1, KarmasikSayi k2)
{
	KarmasikSayi Sonuc;
	Sonuc.SetReel(((k1.Getreel() * k2.Getreel()) + (k1.GetSanal() * k2.GetSanal())) / ((k2.Getreel() * k2.Getreel()) + (k2.GetSanal() * k2.GetSanal())));
	Sonuc.SetSanal(((k1.GetSanal() * k2.Getreel()) - (k1.Getreel() * k2.GetSanal())) / ((k2.Getreel() * k2.Getreel()) + (k2.GetSanal() * k2.GetSanal())));
	Sonuc.BilgiGoster();
	return Sonuc;
}

void KarmasikSayi::BilgiGoster()
{
	if (sanal > 0)
	{
		cout << "Sonucunuz:";
		cout << reel << "+" << sanal << "i" << endl;
	}
	else if (sanal < 0)
	{
		cout << reel << sanal << "i" << endl;
	}
	else
	{
		cout << reel << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Turkish");
	KarmasikSayi k1, k2, k3;

	char Secim;
	//dýþarýdan girilen deðerlerin atamasýný yaptým
	double k1_reel, k1_sanal, k2_reel, k2_sanal;
	cout << "Lütfen ilk sayýnýn reel kýsmýný giriniz:";
	cin >> k1_reel;
	k1.SetReel(k1_reel);
	cout << "Lütfen ilk sayýnýn sanal kýsmýný giriniz:";
	cin >> k1_sanal;
	k1.SetSanal(k1_sanal);
	cout << "Lütfen ikinci sayýnýn reel kýsmýný giriniz:";
	cin >> k2_reel;
	k2.SetReel(k2_reel);
	cout << "Lütfen ikinci sayýnýn sanal kýsmýný giriniz:";
	cin >> k2_sanal;
	k2.SetSanal(k2_sanal);



	do
	{

		cout << "+ operatörünü aþýrý yüklemek için 1'e basýn:" << endl;
		cout << "- operatörünü aþýrý yüklemek için 2'ye basýn:" << endl;
		cout << "* operatörünü aþýrý yüklemek için 3'e basýn:" << endl;
		cout << "/ operatörünü aþýrý yüklemek için 4'e basýn:" << endl;
		cout << "+= operatörünü aþýrý yüklemek için 5'e basýn:" << endl;
		cout << "-= operatörünü aþýrý yükleek için 6'ya basýn:" << endl;
		cout << "*= operatörünü aþýrý yüklemek için 7'ye basýn:" << endl;
		cout << "/= operatörünü aþýrý yüklemek için 8'e basýn:" << endl;
		cout << "Kutupsal gösterim için 9'a basýn:" << endl;
		int menusecenek;
		cin >> menusecenek;

		if (menusecenek == 1)
		{
			k3 = k1 + k2;
			k3.BilgiGoster();
		}

		else if (menusecenek == 2)
		{
			k3 = k1 - k2;
			k3.BilgiGoster();
		}
		else if (menusecenek == 3)
		{
			k3 = k1 * k2;
			k3.BilgiGoster();
		}
		else if (menusecenek == 4)
		{
			k3 = k1 / k2;
			k3.BilgiGoster();
		}
		else if (menusecenek == 5)
		{
			k1 += k2;
		}
		else if (menusecenek == 6)
		{
			k1 -= k2;
		}
		else if (menusecenek == 7)
		{
			k1 *= k2;
		}
		else if (menusecenek == 8)
		{
			k1 /= k2;
		}
		else if (menusecenek == 9)
		{
			KutupsalGosterim(k1, k2);
		}
		else
		{
			cout << "Hatalý giriþ!!!";
		}

		do
		{

			cout << "Devam etmek istiyor musunuz?[E/H]" << endl;
			cin >> Secim;

		} while (!(Secim == 'e' || Secim == 'E' || Secim == 'h' || Secim == 'H'));

	} while (Secim == 'e' || Secim == 'E');
}
