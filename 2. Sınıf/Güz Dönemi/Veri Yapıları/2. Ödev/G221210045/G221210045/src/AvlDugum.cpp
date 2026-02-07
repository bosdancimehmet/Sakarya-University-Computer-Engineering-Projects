/** 
* @file        :AvlDugum.cpp
* @description :Avl ağacının node'larının fonksiyon gövdeleri oluşturuldu
* @course Dersi:2. Öğretim B Grubu
* @assignment  :2. Ödev
* @date        :21.12.2023
* @author      :Mehmet Bosdancı mehmet.bosdanci@ogr.sakarya.edu.tr
*/
#include <iostream>
#include "AvlDugum.hpp"

Node :: Node(const int& vr, Node* sl = NULL, Node* sg = NULL) {
        data = vr;
        left = sl;
        right = sg;
        height = 0;
}

Node :: Node(int data) {
        this->data=data;
		left = NULL;
		right = NULL;
		height=0;
}