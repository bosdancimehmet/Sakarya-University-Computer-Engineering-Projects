/** 
* @file        :Stack.cpp
* @description :Temel stack fonksiyonlarının gövdeleri yazıldı
* @course Dersi:2. Öğretim B Grubu
* @assignment  :2. Ödev
* @date        :21.12.2023
* @author      :Mehmet Bosdancı mehmet.bosdanci@ogr.sakarya.edu.tr
*/
#include <iostream>
#include "Stack.hpp"
using namespace std;
Stack::Stack(){
	root = NULL;
}
bool Stack::isEmpty(){
	return root == NULL;
}
void Stack::push(int sayi){
	if(isEmpty()){
		root = new StackNode(sayi);
	}
	else{
		StackNode* temp = root;
		root = new StackNode(sayi);
		root->next = temp;
	}
}
void Stack::pop(){
	if(!isEmpty()){
		StackNode* gecici = root;
		root = root->next;
		delete gecici;
	}
	else if(isEmpty()){
		root = NULL;
	}
}
void Stack::yazdir(){
	if(!isEmpty()){
		StackNode* temp = root;
		cout<<"UST"<<endl;
		while(temp!=NULL){
			cout<<temp->data<<endl;
			temp = temp->next;
		}
		cout<<"ALT"<<endl;
		cout<<"**********************"<<endl;;
	
	}
}
void Stack::clear(){
	while(!isEmpty()){
		pop();
	}
}
int Stack::top(){
	if(!isEmpty()){
		//cout<<root->data<<endl;
		return root->data;
	}	
    return 0;
}

int Stack::toplamStack(){
	return toplamStack(root);
}

int Stack::toplamStack(StackNode* root){
	int stackElemanToplami=0;
	if(!isEmpty()){
		StackNode* temp = root;
		while(temp!=NULL){
			stackElemanToplami+=temp->data;
			temp = temp->next;
		}
		
	}
	return stackElemanToplami;
}
