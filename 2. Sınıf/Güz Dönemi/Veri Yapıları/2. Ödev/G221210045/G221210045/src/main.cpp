/** 
* @file        :main.cpp
* @description :Dosya okuma işlemleri ve stack karşılaştırma işlemleri gerçekleştirildi
* @course Dersi:2. Öğretim B Grubu
* @assignment  :2. Ödev
* @date        :21.12.2023
* @author      :Mehmet Bosdancı mehmet.bosdanci@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <fstream>
#include <cctype>//isdigit için gerekli
#include <string>
#include <iomanip> // setw() için
#include "Stack.hpp"
#include "Avl.hpp"
using namespace std;
int main(){

	ifstream dosyaoku("Veri.txt");

    if (!dosyaoku.is_open()) {
        cout << "Dosya acilamadi!" <<endl;
        return 1;
    }

    string satir;
	int agacSayisi=0;
	while (getline(dosyaoku, satir)) {
		if(satir!=""){
			agacSayisi++;
		}
		  
    }
	
	// Dosyanın okuma konumunu başa alıyorum
	dosyaoku.clear();
	dosyaoku.seekg(0, ios::beg);
	
	AVL* agaclar[agacSayisi];
	int agac_index = 0;
    while (getline(dosyaoku, satir)){
		if(satir == ""){
			continue;
		}
		else{
			
			AVL* yeni_agac = new AVL();
				
			string sayiMetni = "";
			for (char c : satir) {
				if (isdigit(c)) {
					sayiMetni += c;
				} else if (!sayiMetni.empty()) {
					int number = stoi(sayiMetni);
					yeni_agac->Add(number);
					sayiMetni = "";
				}
			}

			if (!sayiMetni.empty()) {
				int number = stoi(sayiMetni);
				yeni_agac->Add(number);
			}
				
			agaclar[agac_index] = yeni_agac;
			agac_index++;
		}	
			
    }
	dosyaoku.close();
	
	for(int i =0;i<agacSayisi;i++)
	{
		agaclar[i]->postorderLeafNodes(agaclar[i]->getRoot());
		//cout<<"bos satir geldi:"<<i;
	}
	
	cout<<endl;

	for(int i =0;i<agacSayisi;i++)
	{
		cout<<(char)agaclar[i]->asciiKarakter(agaclar[i]->myStack);		
	}
	cout<<endl;

	int enKucuk =2147483647;
	int enBuyuk =-1;
	int kacDoluVar=agacSayisi;
	int i=0;
	while(kacDoluVar>1){
		if(i%2==0){
			//en küçüğü bulma
			for(int j =0;j<agacSayisi;j++)
			{
				if(agaclar[j]->getRoot()){
					if(agaclar[j]->myStack->top()<enKucuk){
					enKucuk=agaclar[j]->myStack->top();
					}
				}
			}
			//ilk en küçüğü çıkartma
			for (int j = 0; j < agacSayisi;j++) {
					if(agaclar[j]->getRoot()){
						if(agaclar[j]){	
							if (agaclar[j]->myStack->top() == enKucuk) {
							agaclar[j]->myStack->pop(); // Yalnızca en küçük elemanı çıkar
							
								if(agaclar[j]->myStack->isEmpty()){
									agaclar[j]->Clear();
									agaclar[j]->setRoot(NULL);
									enKucuk =2147483647;
									kacDoluVar--;							
									i=1;
									for(int m =0;m<agacSayisi;m++)
									{
										if(agaclar[m]->myStack->top()==0){
											
										}
										else{		
											cout<<(char)agaclar[m]->asciiKarakter(agaclar[m]->myStack);
											
										}				
									}
									system("cls");
									for(int p =0;p<agacSayisi;p++)
									{
										agaclar[p]->myStack->clear();	
									}
									//yaprakları yığıta atıyorum
									for(int n =0;n<agacSayisi;n++)
									{
										if(n!=j){
											agaclar[n]->postorderLeafNodes(agaclar[n]->getRoot());
										}	
									}	
									break; // İlk en küçük elemanı çıkardığımda döngüden çıkıyorum		
								}
							}
					}
				}
					
			}
		}
		else if(i%2==1){//cout<<"hello"<<endl;
			//en büyüğü bulma
			for(int k =0;k<agacSayisi;k++)
			{
				if(agaclar[k]){
					if(agaclar[k]->myStack->top()>enBuyuk){
						enBuyuk=agaclar[k]->myStack->top();
					}	
				}						
			}
			//ilk en büyüğü çıkartma
			for (int k = 0; k < agacSayisi;k++) {
				if(agaclar[k]->getRoot()){
					if(agaclar[k]){
						if (agaclar[k]->myStack->top() == enBuyuk) {
						agaclar[k]->myStack->pop(); // Yalnızca en büyük elemanı çıkar

							if(agaclar[k]->myStack->isEmpty()){
								agaclar[k]->Clear();
								agaclar[k]->setRoot(NULL);
								enBuyuk =-1;
								kacDoluVar--;
								i=1;
								for(int m =0;m<agacSayisi;m++)
								{
									
										if(agaclar[m]->myStack->top()==0){
											
										}
										else{
											
											cout<<(char)agaclar[m]->asciiKarakter(agaclar[m]->myStack);
										}		
								}
								system("cls");
								for(int y =0;y<agacSayisi;y++)
								{
									agaclar[y]->myStack->clear();	
								}
								//yaprakları yığıta atıyorum
								for(int j =0;j<agacSayisi;j++)
								{
									if(k!=j){
										agaclar[j]->postorderLeafNodes(agaclar[j]->getRoot());
									}
									
								}
									
								break; // İlk en büyük elemanı çıkardığımda döngüden çıkıyorum
							}	
						}
					}
				}
				
				
				
			}
		}
		
		i++;
	}

	if(kacDoluVar==1){
		for(int m =0;m<agacSayisi;m++)
		{
		if(agaclar[m]){
			if(agaclar[m]->myStack->top()==0){
				
			}
			else{
				system("cls");
				for(int t =0;t<30;t++){
					cout<<"=";
				}
				cout<<endl;
				cout<<"|                            |"<<endl;
				cout<<"|                            |"<<endl;
				string str = to_string(m+1);
				int uzunluk =str.length();
				cout<<"|     Son Karakter: "<<(char)agaclar[m]->asciiKarakter(agaclar[m]->myStack)<<"        |"<<"\n|     AVL No      : "<<setw(uzunluk)<<m+1<<setw(10-uzunluk)<<right<<"|"<<endl;
				cout<<"|                            |"<<endl;
				cout<<"|                            |"<<endl;
				for(int t =0;t<30;t++){
					cout<<"=";
					}
				}
			}
					
		}
			
	}
    
}
