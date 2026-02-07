/** 
* @file: main
* @description: Sayi listesinin düğümleri burada bulunur
* @course: veri yapıları 2-B
* @assignment: 1.Ödev
* @date 25.11.2023
* @author Mehmet Bosdancı G221210045
*/
#include <iostream>
#include "Basamak.hpp"
Basamak::Basamak(int data){
	this->data=data;
	this->next=NULL;
}
