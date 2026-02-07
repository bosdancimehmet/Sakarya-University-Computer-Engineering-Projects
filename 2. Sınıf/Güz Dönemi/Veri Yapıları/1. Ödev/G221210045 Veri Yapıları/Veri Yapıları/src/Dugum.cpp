/** 
* @file: main
* @description: SayilarListesini oluşturan düğümler buradadır
* @course: veri yapıları 2-B
* @assignment: 1.Ödev
* @date 25.11.2023
* @author Mehmet Bosdancı G221210045
*/
#include <iostream>
#include "Dugum.hpp"
Dugum::Dugum(Sayi* value){
	this->sayi=value;
	this->next=NULL;
}