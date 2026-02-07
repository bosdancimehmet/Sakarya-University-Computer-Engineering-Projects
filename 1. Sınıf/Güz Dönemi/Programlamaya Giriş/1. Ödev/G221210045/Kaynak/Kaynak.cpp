/***************************************************************************************************
**                                                                                                **
**                                   SAKARYA  ÜNÝVERSÝTESÝ                                        **
**                          BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ                             **
**                                BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ                                  **
**                                   PROGLAMLAMAYA GÝRÝÞ DERSÝ                                    **  
**                                       ÖDEV NUMARASI...:  1                                     **
**                                       ÖÐRENCÝ ADI.....:  MEHMET BOSDANCI                       **
**                                       ÖÐRENCÝ NUMARASI:  G221210045                            **
**                                       DERS GRUBU......:  2.ÖÐRETÝM B GRUBU                     **
**                                                                                                **
***************************************************************************************************/


#include<iostream>//giriþ çýkýþ kütüphanesi
#include<iomanip>//setw kullanýmý için
#include<locale.h>//türkçe karakterler için
#include<ctime>//srand için
#include<string>//stringler için

using namespace std;


struct Ogrenci
{
	string Adi;
	string SoyAdi;
	int No;
	int KisaSinav1;
	int KisaSinav2;
	int Odev1;
	int Odev2;
	int Proje;
	int Vize;
	int final;

};

Ogrenci RastgeleOgrenciler[100];

struct Tarih
{
	string Gun;
	string Ay;
	int Yýl;

};

//isim havuzumuz
string AdDizisi[30]
{ "Ali","Ayþe","Ahmet","Mehmet","Emre","Halil","Ýbrahim","Ethem","Fatma","Nevin",
 "Ýrem","Özge","Batuhan","Zeki","Musa","Melek","Hüseyin","Niyazi","Celal","Neþat",
 "Necati","Polat","Elif","Ýlker","Önder","Murat","Eda","Loya","Ecemþah","Emine" };

//soyisim havuzumuz
string SoyadDizisi[30]
{ "Yýlmaz","Toprak","Su","Demir","Þenses","Mutlu","Þahin","Dönmez","Çalýk","Bozkurt",
  "Arslan","Bayýr","Duman","Koçyiðit","Özkan","Keskin","Bayrak","Martý","Çaðlayan","Çicek",
  "Kaplan","Üstün","Tiryaki","Baðrýaçýk","Doðan","Güven","Koç","Göktepe","Özen","Yýldýrým" };


//yýliçi notunu hesaplayan fonksiyon
int YilÝciNotHesabi(int i) 
{

	int YilÝciNotu = (RastgeleOgrenciler[i].Vize * 0.5) + (RastgeleOgrenciler[i].KisaSinav1 * 7 / 100) + (RastgeleOgrenciler[i].KisaSinav2 * 7 / 100) +
		(RastgeleOgrenciler[i].Odev1 * 0.1) + (RastgeleOgrenciler[i].Odev2 * 0.1) + (RastgeleOgrenciler[i].Proje * 0.16);

	return YilÝciNotu;

}
//baþarý notunu hesaplayan fonksiyon
float BasariNotuHesabi(int i)
{
	
	float BasariNotu = ((RastgeleOgrenciler[i].Vize * 0.5) + (RastgeleOgrenciler[i].KisaSinav1 * 0.07) + (RastgeleOgrenciler[i].KisaSinav2 * 0.07) +
		(RastgeleOgrenciler[i].Odev1 * 0.1) + (RastgeleOgrenciler[i].Odev2 * 0.1) + (RastgeleOgrenciler[i].Proje * 0.16)) * 0.55 + (RastgeleOgrenciler[i].final) * 0.45;
	return BasariNotu;
}



//en büyük baþarý notunun kime ait olduðunu gösteren fonksiyon
void fonksiyon1(int DonguDegeri)
{
	int EnBuyukNot = BasariNotuHesabi(0);
	string NotKimeAitAd, NotKimeAitSoyad;
	for (int i = 0; i < DonguDegeri; i++)
	{

		if (BasariNotuHesabi(i) >= EnBuyukNot)

		{
			EnBuyukNot = BasariNotuHesabi(i);
			NotKimeAitAd = RastgeleOgrenciler[i].Adi;
			NotKimeAitSoyad = RastgeleOgrenciler[i].SoyAdi;
		}


	}

	cout << "En büyük baþarý notu " << NotKimeAitAd << " " << NotKimeAitSoyad << "'e" << " aittir ve BAÞARI NOTU:" << EnBuyukNot << "'idir" << endl;
}

//en küçük baþarý notunun kime ait olduðunu gösteren fonsiyon
void fonksiyon2(int DonguDegeri)
{

	int EnKücükNot = BasariNotuHesabi(0);
	string NotKimeAitAd, NotKimeAitSoyad;

	for (int i = 0; i < DonguDegeri; i++)
	{

		if (BasariNotuHesabi(i) <= EnKücükNot)
		{

			EnKücükNot = BasariNotuHesabi(i);
			NotKimeAitAd = RastgeleOgrenciler[i].Adi;
			NotKimeAitSoyad = RastgeleOgrenciler[i].SoyAdi;

		}

	}

	cout << "En küçük baþarý notu " << NotKimeAitAd << " " << NotKimeAitSoyad << "'e" << " aittir ve BAÞARI NOTU:" << EnKücükNot << "'idir" << endl;

}

//sýnýfýn baþarý not ortalamasýný hesaplayan fonksiyon
void fonksiyon3(int DonguDegeri)
{

	int BasariNotToplamlari = 0;
	int BasariNotOrtalamasi;
	for (int i = 0; i < DonguDegeri; i++)
	{

		BasariNotToplamlari += BasariNotuHesabi(i);

	}
	BasariNotOrtalamasi = BasariNotToplamlari / DonguDegeri;
	cout << "Sýnýfýn baþarý not ortalamasý " << BasariNotOrtalamasi << "'idir" << endl;

}

//standart sapmayý hesaplayan fonksiyon
void fonksiyon4(int DonguDegeri)
{

	int BasariNotToplamlari = 0;
	int BasariNotOrtalamasi;
	for (int i = 0; i < DonguDegeri; i++)
	{

		BasariNotToplamlari += BasariNotuHesabi(i);

	}
	BasariNotOrtalamasi = BasariNotToplamlari / DonguDegeri;

	int StandartSapma = 0;
	for (int i = 0; i < DonguDegeri; i++)
	{

		StandartSapma += pow((pow((BasariNotOrtalamasi - BasariNotuHesabi(i)), 2)) / DonguDegeri, 0.5);

	}
	cout << "Standart sapmamýzýn deðeri " << StandartSapma << "'idir" << endl;


}

//notu belli bir aralýkta olan kiþileri yazdýran fonksiyon
void fonksiyon5(int DonguSayisi)
{

	float AltDeger, UstDeger;
	do
	{
		cout << "Lütfen sýralamak istediðiniz aralýðýn alt deðeri giriniz:";
		cin >> AltDeger;
		cout << "Lütfen sýralamak istediðiniz aralýðýn üst deðerini giriniz:";
		cin >> UstDeger;
	} while (!(AltDeger < UstDeger));

	cout << setw(10) << left << "ADI" << setw(10) << left << "SOYADI" << setw(10) << left << "BAÞARI NOTU" << endl;

	for (int i = 0; i < DonguSayisi; i++)
	{

		if (BasariNotuHesabi(i) >= AltDeger && BasariNotuHesabi(i) <= UstDeger)
		{
			if (i == 20 || i == 40 || i == 60 || i == 80)
			{

				system("pause");

			}
			cout << setw(10) << left << RastgeleOgrenciler[i].Adi << setw(10) << left << RastgeleOgrenciler[i].SoyAdi << setw(10) << left << BasariNotuHesabi(i) << endl;

		}

	}


}

//notu belli bir deðerin altýndaki öðrencileri yazdýran fonksiyon 
void fonksiyon6(int DonguSayisi)
{
	int SinirDegeri;
	do
	{
		cout << "Lütfen belirlemek istediðiniz deðerin altýnda bulunan öðrencileri sýralamak için bir deðer giriniz:";

		cin >> SinirDegeri;
	} while (!(SinirDegeri >= 0 && SinirDegeri <= 100));

	cout << setw(10) << left << "ADI" << setw(10) << left << "SOYADI" << setw(10) << left << "BAÞARI NOTU" << endl;

	for (int i = 0; i < DonguSayisi; i++)
	{

		if (BasariNotuHesabi(i) <= SinirDegeri)
		{

			if (i == 20 || i == 40 || i == 60 || i == 80)
			{

				system("pause");

			}

			
			cout << setw(10) << left << RastgeleOgrenciler[i].Adi << setw(10) << left << RastgeleOgrenciler[i].SoyAdi << setw(10) << left << BasariNotuHesabi(i) << endl;


		}

	}
}

//notu belli bir deðerin üstünde olan öðrencileri yazdýran fonksiyon
void fonksiyon7(int DonguSayisi)
{
	int SinirDegeri;
	do
	{
		cout << "Lütfen belirlemek istediðiniz deðerin üstünde bulunan öðrencileri sýralamak için bir deðer giriniz:";

		cin >> SinirDegeri;
	} while (!(SinirDegeri >= 0 && SinirDegeri <= 100));

	cout << setw(10) << left << "ADI" << setw(10) << left << "SOYADI" << setw(10) << left << "BAÞARI NOTU" << endl;

	for (int i = 0; i < DonguSayisi; i++)
	{

		if (BasariNotuHesabi(i) >= SinirDegeri)
		{

			if (i == 20 || i == 40 || i == 60 || i == 80)
			{

				system("pause");

			}

			{
				cout << setw(10) << left << RastgeleOgrenciler[i].Adi << setw(10) << left << RastgeleOgrenciler[i].SoyAdi << setw(10) << left << BasariNotuHesabi(i) << endl;
			}

		}

	}
}

// manuel girilen listedeki kiþilerin adlarýný soyadlarý ve notlarýný yazdýran fonksiyon
void fomksiyon0(int StudentSayisi)
{

	cout << "ADI" << "\t" << setw(10) << left << "SOYADI" << "\t" << setw(5) << left << "Kýsa Sýnav1\t" << setw(5) << left
		<< "Kýsa Sýnav2\t" << setw(5) << left << "Ödev1\t" << setw(5) << left << "Ödev2\t" << setw(5) << left << "Proje\t"
		<< setw(5) << left << "Vize\t" << setw(5) << left << "Final\t" << setw(5) << left << "YILÝÇÝNOTU    " << setw(3) << left << "BAÞARINOTU" << endl;

	for (int i = 0; i < StudentSayisi; i++)
	{
		if (i == 20 || i == 40 || i == 60 || i == 80)
		{
			cout << endl;

			system("pause");
			system("cls");

			cout << "ADI" << "\t" << setw(10) << left << "SOYADI" << "\t" << setw(5) << left << "Kýsa Sýnav1\t" << setw(5) << left
				<< "Kýsa Sýnav2\t" << setw(5) << left << "Ödev1\t" << setw(5) << left << "Ödev2\t" << setw(5) << left << "Proje\t"
				<< setw(5) << left << "Vize\t" << setw(5) << left << "Final\t" << setw(5) << left << "YILÝÇÝNOTU    " << setw(3) << left << "BAÞARINOTU" << endl;
		}

		cout << RastgeleOgrenciler[i].Adi << "\t" << setw(10) << left << RastgeleOgrenciler[i].SoyAdi << "\t"
			<< setw(5) << left << RastgeleOgrenciler[i].KisaSinav1 << "\t\t" << setw(5) << left << RastgeleOgrenciler[i].KisaSinav2 << "\t\t" << setw(5) << left << RastgeleOgrenciler[i].Odev1
			<< "\t" << setw(5) << left << RastgeleOgrenciler[i].Odev2 << "\t" << setw(5) << left << RastgeleOgrenciler[i].Proje << "\t" << setw(5) << left << RastgeleOgrenciler[i].Vize
			<< "\t" << setw(5) << left << RastgeleOgrenciler[i].final << "\t" << setw(5) << left << YilÝciNotHesabi(i) << "\t\t" << setw(5) << left << BasariNotuHesabi(i) << endl;
	}

}

void NottanHarfe(int DönguSayisi )
{

	cout << setw(10) << left << "ADI" << setw(10) << left << "SOYADI" << setw(10) << left << "BAÞARI NOTU\t" <<setw(10)<<left<<"HARF KARÞILIÐI" << endl;

	for(int i =0;i<DönguSayisi ;i++)
	{
		if (i == 20 || i == 40 || i == 60 || i == 80)
		{
			system("pause");
		}
		if (BasariNotuHesabi(i) >= 0 && BasariNotuHesabi(i) <= 39)
		{
			cout << setw(10) << left << RastgeleOgrenciler[i].Adi << setw(10) << left << RastgeleOgrenciler[i].SoyAdi << setw(10) << left << BasariNotuHesabi(i) << "\t" << setw(10) << left << "FF" << endl;
		}
		
		else if (BasariNotuHesabi(i) >= 40 && BasariNotuHesabi(i) <= 49)
		{
			cout << setw(10) << left << RastgeleOgrenciler[i].Adi << setw(10) << left << RastgeleOgrenciler[i].SoyAdi << setw(10) << left << BasariNotuHesabi(i)<<"\t" << setw(10) << left << "FD" << endl;
		}

		else if (BasariNotuHesabi(i) >= 50 && BasariNotuHesabi(i) <= 57)
		{
			cout << setw(10) << left << RastgeleOgrenciler[i].Adi << setw(10) << left << RastgeleOgrenciler[i].SoyAdi << setw(10) << left << BasariNotuHesabi(i) <<"\t" << setw(10) << left << "DD" << endl;
		}

		else if (BasariNotuHesabi(i) >= 58 && BasariNotuHesabi(i) <= 64)
		{
			cout << setw(10) << left << RastgeleOgrenciler[i].Adi << setw(10) << left << RastgeleOgrenciler[i].SoyAdi << setw(10) << left << BasariNotuHesabi(i)<<"\t" << setw(10) << left << "DC" << endl;

		}

		else if (BasariNotuHesabi(i) >= 65 && BasariNotuHesabi(i) <= 74)
		{
			cout << setw(10) << left << RastgeleOgrenciler[i].Adi << setw(10) << left << RastgeleOgrenciler[i].SoyAdi << setw(10) << left << BasariNotuHesabi(i) <<"\t" << setw(10) << left << "CC" << endl;

		}

		else if (BasariNotuHesabi(i) >= 75 && BasariNotuHesabi(i) <= 79)
		{
			cout << setw(10) << left << RastgeleOgrenciler[i].Adi << setw(10) << left << RastgeleOgrenciler[i].SoyAdi << setw(10) << left << BasariNotuHesabi(i)<<"\t" << setw(10) << left << "CB" << endl;
		}

		else if (BasariNotuHesabi(i) >= 80 && BasariNotuHesabi(i) <= 84)
		{
			cout << setw(10) << left << RastgeleOgrenciler[i].Adi << setw(10) << left << RastgeleOgrenciler[i].SoyAdi << setw(10) << left << BasariNotuHesabi(i) <<"\t" << setw(10) << left << "BB" << endl;
		}

		else if (BasariNotuHesabi(i) >= 85 && BasariNotuHesabi(i) <= 89)
		{
			cout << setw(10) << left << RastgeleOgrenciler[i].Adi << setw(10) << left << RastgeleOgrenciler[i].SoyAdi << setw(10) << left << BasariNotuHesabi(i) <<"\t" << setw(10) << left << "BA" << endl;
		}

		else if (BasariNotuHesabi(i) >= 90 && BasariNotuHesabi(i) <= 100)
		{
			cout << setw(10) << left << RastgeleOgrenciler[i].Adi << setw(10) << left << RastgeleOgrenciler[i].SoyAdi << setw(10) << left << BasariNotuHesabi(i) <<"\t" << setw(10) << left << "AA" << endl;
		}

	}
	
}


int main()
{

	setlocale(LC_ALL, "Turkish");
	
	char Secim;
	//notlarý fonksiyondan ayrý bir þekilde tanýmlamamýn sebebi menüden direkt 5 i seçersem (baþarý notu belli bir aralýkta olanlarý sýralamak)
	//henüz öðrencilerin not atamasý olmadýðý için notlarýn hepsine 0 yazýyordu bu yüzden not atamasýný burda tekrardan yaptým.
	for (int i = 0; i < 100; i++)
	{
		RastgeleOgrenciler[i].Adi = AdDizisi[rand() % 30];
		RastgeleOgrenciler[i].SoyAdi = SoyadDizisi[rand() % 30];
	}

	for (int i = 0; i < 10; i++)
	{

		RastgeleOgrenciler[i].KisaSinav1 = rand() % 41;
		RastgeleOgrenciler[i].KisaSinav2 = rand() % 41;
		RastgeleOgrenciler[i].Odev1 = rand() % 41;
		RastgeleOgrenciler[i].Odev2 = rand() % 41;
		RastgeleOgrenciler[i].Proje = rand() % 41;
		RastgeleOgrenciler[i].Vize = rand() % 41;
		RastgeleOgrenciler[i].final = rand() % 41;

	}
	for (int i = 10; i < 60; i++)
	{

		RastgeleOgrenciler[i].KisaSinav1 = rand() % 31 + 40;
		RastgeleOgrenciler[i].KisaSinav2 = rand() % 31 + 40;
		RastgeleOgrenciler[i].Odev1 = rand() % 31 + 40;
		RastgeleOgrenciler[i].Odev2 = rand() % 31 + 40;
		RastgeleOgrenciler[i].Proje = rand() % 31 + 40;
		RastgeleOgrenciler[i].Vize = rand() % 31 + 40;
		RastgeleOgrenciler[i].final = rand() % 31 + 40;

	}

	for (int i = 60; i < 75; i++)
	{

		RastgeleOgrenciler[i].KisaSinav1 = rand() % 11 + 70;
		RastgeleOgrenciler[i].KisaSinav2 = rand() % 11 + 70;
		RastgeleOgrenciler[i].Odev1 = rand() % 11 + 70;
		RastgeleOgrenciler[i].Odev2 = rand() % 11 + 70;
		RastgeleOgrenciler[i].Proje = rand() % 11 + 70;
		RastgeleOgrenciler[i].Vize = rand() % 11 + 70;
		RastgeleOgrenciler[i].final = rand() % 11 + 70;

	}

	for (int i = 75; i < 100; i++)
	{

		RastgeleOgrenciler[i].KisaSinav1 = rand() % 21 + 80;
		RastgeleOgrenciler[i].KisaSinav2 = rand() % 21 + 80;
		RastgeleOgrenciler[i].Odev1 = rand() % 21 + 80;
		RastgeleOgrenciler[i].Odev2 = rand() % 21 + 80;
		RastgeleOgrenciler[i].Proje = rand() % 21 + 80;
		RastgeleOgrenciler[i].Vize = rand() % 21 + 80;
		RastgeleOgrenciler[i].final = rand() % 21 + 80;

	}

    do
	{
		int Secenek;

		

		cout << "Diziyi rastgele yazdirmak icin 1'e:" << endl;
		cout << "Diziyi kendiniz olusturmak icin 2'ye basin:" << endl;
		cin >> Secenek;
		srand(time(NULL));

		switch (Secenek)
		{
		case 1:
			//menümüz
			cout << "Sýnýf listesi ve sýnav puanlarýnýn yazdýrýlmasý için 0'a basýn:" << endl;
			cout << "Sýnýfýn en yüksek baþarý notunu hesaplamak için 1'e basýn:" << endl;
			cout << "Sýnýfýn en düþük baþarý notunu hesaplamak için 2'ye basýn:" << endl;
			cout << "Sýnýfýn baþarý notu ortalamasýný hesaplamak için 3'e basýn:" << endl;
			cout << "Sýnýfýn standart sapmasýný hesaplamak için 4'e basýn:" << endl;
			cout << "Baþarý notunu belli bir aralýkta olanlarý sýralamak için 5'e basýn:" << endl;
			cout << "Baþarý notu belli bir deðerin altýnda olan öðrencileri sýralamak için 6'ya basýn:" << endl;
			cout << "Baþarý notu belli bir deðerin üstünde olan öðrencileri sýralamak için 7'ye basýn:" << endl;
			cout << "Baþarý notunun harf karþýlýðýný görmek için 8'e basýn:" << endl;
			int MenüSecim;

			cin >> MenüSecim;

			if (MenüSecim == 0)
			{
				fomksiyon0(100);
				break;
			}

			else if (MenüSecim == 1)
			{
				fonksiyon1(100);
			}

			else if (MenüSecim == 2)
			{
				fonksiyon2(100);
			}

			else if (MenüSecim == 3)
			{
				fonksiyon3(100);
			}

			else if (MenüSecim == 4)
			{
				fonksiyon4(100);
			}

			else if (MenüSecim == 5)
			{
				fonksiyon5(100);
			}

			else if (MenüSecim == 6)
			{
				fonksiyon6(100);
			}

			else if (MenüSecim == 7)
			{
				fonksiyon7(100);
			}

			else if (MenüSecim == 8)
			{
				NottanHarfe(100);
			}

			else
				cout << "Hatalý giriþ yaptýnýz!!!"<<endl;

			break;


		case 2:

			cout << "Lütfen kaç öðrenci gireceðinizi seçiniz:";

			int StudentSayisi;

			cin >> StudentSayisi;

			cout << "Lütfen öðrencilerin adýný giriniz:" << endl;
			for (int i = 0; i < StudentSayisi; i++)
			{
				cin >> RastgeleOgrenciler[i].Adi;

			}
			cout << "Lütfen öðrencilerin soyadýný giriniz:" << endl;
			for (int i = 0; i < StudentSayisi; i++)
			{
				cin >> RastgeleOgrenciler[i].SoyAdi;
			}
			
			cout << "Lütfen öðrencilerin birinci kýsa sýnavýný giriniz:"<<endl;
			for (int i = 0; i < StudentSayisi; i++)
			{
				int kisaSinav1;
				//girilen notun sýfýr ile yüz arasýnda olup olmadýðýný konrol eden yapý
				do
				{
					cin >> kisaSinav1;
					if((kisaSinav1 >= 0 && kisaSinav1 <= 100))
					{
						RastgeleOgrenciler[i].KisaSinav1 = kisaSinav1;
					}

					else if (!(kisaSinav1 >= 0 && kisaSinav1 <= 100))
					{

						cout << "Lütfen 0 ile 100 arasýnda sayý giriniz!!!" << endl;

					}

				} while (!((kisaSinav1 >= 0 && kisaSinav1 <= 100)));
			}
			cout << "Lütfen öðrencilerin ikinci kýsa sýnavýný giriniz:" << endl;
			for (int i = 0; i < StudentSayisi; i++)
			{
				int kisaSinav2;
				//girilen notun sýfýr ile yüz arasýnda olup olmadýðýný konrol eden yapý
				do
				{
					cin >> kisaSinav2;
					if (kisaSinav2 >= 0 && kisaSinav2 <= 100)
					{
						RastgeleOgrenciler[i].KisaSinav2 = kisaSinav2;
					}

					else if (!(kisaSinav2 >= 0 && kisaSinav2 <= 100))
					{

						cout << "Lütfen 0 ile 100 arasýnda sayý giriniz!!!" << endl;

					}


				} while (!(kisaSinav2 >= 0 && kisaSinav2 <= 100));

			}
			cout << "Lütfen birinci ödev puanýný giriniz:" << endl;
			for (int i = 0; i < StudentSayisi; i++)
			{

				int Odev1;
				//girilen notun sýfýr ile yüz arasýnda olup olmadýðýný konrol eden yapý
				do
				{
					cin >> Odev1;
					if (Odev1 >= 0 && Odev1 <= 100)
					{
						RastgeleOgrenciler[i].Odev1 = Odev1;
					}

					else if (!(Odev1 >= 0 && Odev1 <= 100))
					{

						cout << "Lütfen 0 ile 100 arasýnda sayý giriniz!!!" << endl;

					}


				} while (!(Odev1 >= 0 && Odev1 <= 100));
			}
			cout << "Lütfen ikinci ödev puanýný giriniz:" << endl;
			for (int i = 0; i < StudentSayisi; i++)
			{

				int Odev2;
				//girilen notun sýfýr ile yüz arasýnda olup olmadýðýný konrol eden yapý
				do
				{
					cin >> Odev2;
					if (Odev2 >= 0 && Odev2 <= 100)
					{
						RastgeleOgrenciler[i].Odev2 = Odev2;
					}

					else if (!(Odev2 >= 0 && Odev2 <= 100))
					{

						cout << "Lütfen 0 ile 100 arasýnda sayý giriniz!!!" << endl;

					}


				} while (!(Odev2 >= 0 && Odev2 <= 100));
			}

			cout << "Lütfen proje notunu giriniz:" << endl;
			for (int i = 0; i < StudentSayisi; i++)
			{

				int Proje;
				//girilen notun sýfýr ile yüz arasýnda olup olmadýðýný konrol eden yapý
				do
				{
					cin >> Proje;
					if (Proje >= 0 && Proje <= 100)
					{
						RastgeleOgrenciler[i].Proje = Proje;
					}

					else if (!(Proje >= 0 && Proje <= 100))
					{

						cout << "Lütfen 0 ile 100 arasýnda sayý giriniz!!!" << endl;

					}


				} while (!(Proje >= 0 && Proje <= 100));

			}

			cout << "Lütfen vize notunu giriniz:" << endl;
			for (int i = 0; i < StudentSayisi; i++)
			{

				int Vize;
				//girilen notun sýfýr ile yüz arasýnda olup olmadýðýný konrol eden yapý
				do
				{
					cin >> Vize;
					if (Vize >= 0 && Vize <= 100)
					{
						RastgeleOgrenciler[i].Vize = Vize;
					}

					else if (!(Vize >= 0 && Vize <= 100))
					{

						cout << "Lütfen 0 ile 100 arasýnda sayý giriniz!!!" << endl;

					}


				} while (!(Vize >= 0 && Vize <= 100));
			}

			cout << "Lütfen final notunu giriniz:" << endl;
			for (int i = 0; i < StudentSayisi; i++)
			{

				int Final;
				//girilen notun sýfýr ile yüz arasýnda olup olmadýðýný konrol eden yapý
				do
				{
					cin >> Final;
					if (Final >= 0 && Final <= 100)
					{
						RastgeleOgrenciler[i].final = Final;
					}

					else if (!(Final >= 0 && Final <= 100))
					{

						cout << "Lütfen 0 ile 100 arasýnda sayý giriniz!!!" << endl;

					}


				} while (!(Final >= 0 && Final <= 100));
			}




			//menümüz
			cout << "Sýnýf listesi ve sýnav puanlarýnýn yazdýrýlmasý için 0'a basýn:" << endl;
			cout << "Sýnýfýn en yüksek baþarý notunu hesaplamak için 1'e basýn:" << endl;
			cout << "Sýnýfýn en düþük baþarý notunu hesaplamak için 2'ye basýn:" << endl;
			cout << "Sýnýfýn baþarý notu ortalamasýný hesaplamak için 3'e basýn:" << endl;
			cout << "Sýnýfýn standart sapmasýný hesaplamak için 4'e basýn:" << endl;
			cout << "Baþarý notunu belli bir aralýkta olanlarý sýralamak için 5'e basýn:" << endl;
			cout << "Baþarý notu belli bir deðerin altýnda olan öðrencileri sýralamak için 6'ya basýn:" << endl;
			cout << "Baþarý notu belli bir deðerin üstünde olan öðrencileri sýralamak için 7'ye basýn:" << endl;
			cout << "Baþarý notunun harf karþýlýðýný yazdýrmak için 8'e basýn:" << endl;
			int MenüSecim2;

			cin >> MenüSecim2;

			if (MenüSecim2 == 0)
			{
				fomksiyon0(StudentSayisi);
				break;
			}

			else if (MenüSecim2 == 1)
			{
				fonksiyon1(StudentSayisi);
			}

			else if (MenüSecim2 == 2)
			{
				fonksiyon2(StudentSayisi);
			}

			else if (MenüSecim2 == 3)
			{
				fonksiyon3(StudentSayisi);
			}

			else if (MenüSecim2 == 4)
			{
				fonksiyon4(StudentSayisi);
			}

			else if (MenüSecim2 == 5)
			{
				fonksiyon5(StudentSayisi);
			}

			else if (MenüSecim2 == 6)
			{
				fonksiyon6(StudentSayisi);
			}

			else if (MenüSecim2 == 7)
			{
				fonksiyon7(StudentSayisi);
			}

			else if (MenüSecim2 == 8)
			{
				NottanHarfe(StudentSayisi);
			}

			else
				cout << "Hatalý giriþ yaptýnýz!!!" << endl;

			break;

		default:
			cout << "Hatalý Giriþ Yaptýnýz...";
		}

		
		system("pause");
		system("cls");
		//devam edip etmemesini sorgulayan yapý
		do
		{
			
			cout << "Devam etmek istiyor musunuz?[E/H]" << endl;
			cin >> Secim;

		} while (!(Secim == 'e' || Secim == 'E' || Secim == 'h' || Secim == 'H'));

	}while (Secim == 'e' || Secim == 'E');

	return 0;
}



