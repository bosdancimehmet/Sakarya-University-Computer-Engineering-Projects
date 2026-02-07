/** 
* @file        :StackDugum.cpp
* @description :Stack node'unun kurucu gövdesi yazıldı
* @course Dersi:2. Öğretim B Grubu
* @assignment  :2. Ödev
* @date        :21.12.2023
* @author      :Mehmet Bosdancı mehmet.bosdanci@ogr.sakarya.edu.tr
*/
#include <iostream>
#include "StackDugum.hpp"
StackNode::StackNode(int data){
	this->data=data;
	next=NULL;
}