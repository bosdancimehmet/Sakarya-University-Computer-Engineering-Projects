/** 
* @file        :Avl.cpp
* @description :Avl ağacı için gerekli fonksiyon gövdeleri dolduruldu
* @course Dersi:2. Öğretim B Grubu
* @assignment  :2. Ödev
* @date        :21.12.2023
* @author      :Mehmet Bosdancı mehmet.bosdanci@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <cmath>
#include "Avl.hpp"
#include "Stack.hpp"
using namespace std;
Node* AVL::SearchAndAdd(Node* subNode, const int& item) {
        if (subNode == NULL) subNode = new Node(item);
        else if (item < subNode->data) {
            subNode->left = SearchAndAdd(subNode->left, item);

            if (Height(subNode->left) == Height(subNode->right) + 2) {
                if (item < subNode->left->data)
                    subNode = SwapWithLeftChild(subNode);
                else {
                    subNode->left = SwapWithRightChild(subNode->left);
                    subNode = SwapWithLeftChild(subNode);
                }
            }
        }
        else if (item > subNode->data) {
            subNode->right = SearchAndAdd(subNode->right, item);

            if (Height(subNode->right) == Height(subNode->left) + 2) {
                if (item > subNode->right->data)
                    subNode = SwapWithRightChild(subNode);
                else {
                    subNode->right = SwapWithLeftChild(subNode->right);
                    subNode = SwapWithRightChild(subNode);
                }
            }
        }
        else;

        subNode->height = Height(subNode);
        return subNode;
}

Node* AVL::SwapWithLeftChild(Node* subNode) {
        Node* tmp = subNode->left;
        subNode->left = tmp->right;
        tmp->right = subNode;

        subNode->height = Height(subNode);
        tmp->height = 1 + max(Height(tmp->left), subNode->height);

        return tmp;
}

Node* AVL::SwapWithRightChild(Node* subNode) {
        Node* tmp = subNode->right;
        subNode->right = tmp->left;
        tmp->left = subNode;

        subNode->height = Height(subNode);
        tmp->height = 1 + max(Height(tmp->right), subNode->height);

        return tmp;
}

bool AVL::DeleteNode(Node*& subNode) {
        Node* delNode = subNode;

        if (subNode->right == NULL) subNode = subNode->left;
        else if (subNode->left == NULL) subNode = subNode->right;
        else {
            delNode = subNode->left;
            Node* parentNode = subNode;
            while (delNode->right != NULL) {
                parentNode = delNode;
                delNode = delNode->right;
            }
            subNode->data = delNode->data;
            if (parentNode == subNode) subNode->left = delNode->left;
            else parentNode->right = delNode->left;
        }
        delete delNode;
        return true;
}

void AVL::inorder(Node* subNode) {
        if (subNode != NULL) {
            inorder(subNode->left);
            cout << subNode->data << " ";
            inorder(subNode->right);
        }
}

void AVL::preorder(Node* subNode) {
        if (subNode != NULL) {
            cout << subNode->data << " ";
            preorder(subNode->left);
            preorder(subNode->right);
        }
}

void AVL::postorder(Node* subNode) {
        if (subNode != NULL) {
            postorder(subNode->left);
            postorder(subNode->right);
            cout << subNode->data << " ";
        }
}

int AVL::Height(Node* subNode) {
        if (subNode == NULL) return -1;
        return 1 + max(Height(subNode->left), Height(subNode->right));
}

void AVL::PrintLevel(Node* subNode, int level) {
        if (subNode == NULL) return;
        if (level == 0) cout << subNode->data << " ";
        else {
            PrintLevel(subNode->left, level - 1);
            PrintLevel(subNode->right, level - 1);
        }
}

bool AVL::Search(Node* subNode, const int& item) {
        if (subNode == NULL) return false;
        if (subNode->data == item) return true;
        if (item < subNode->data) return Search(subNode->left, item);
        else return Search(subNode->right, item);
}

AVL::AVL() {
        root = NULL;
		myStack = new Stack();
}

bool AVL::isEmpty() const {
        return root == NULL;
}

void AVL::Add(const int& item) {
        root = SearchAndAdd(root, item);
}

void AVL::inorder() {
        inorder(root);
}

void AVL::preorder() {
        preorder(root);
}

void AVL::postorder() {
        postorder(root);
}

void AVL::levelorder() {
        int h = Height();
        for (int level = 0; level <= h; level++) {
            PrintLevel(root, level);
        }
}

int AVL::Height() {
        return Height(root);
}

bool AVL::Search(const int& item) {
        return Search(root, item);
}

void AVL::Clear() {
        while (!isEmpty()) DeleteNode(root);
}

AVL::~AVL() {
        Clear();
}

void AVL::postorderLeafNodes(Node* root) {
    if (root == NULL) {
        return;
    }

    postorderLeafNodes(root->left);
    postorderLeafNodes(root->right);

    if (root->left == NULL && root->right == NULL) {
        myStack->push(root->data); // Yaprağı yığına ekliyorum
    }
}

Node* AVL::getRoot(){
	return root;
}

int AVL::toplamDugum() {
    return toplamDugum(getRoot()); // Kök düğümden başlayarak toplamı hesaplar
}

int AVL::toplamDugum(Node* root) {
    if (root == NULL) {
        return 0; // Boş düğüm, değer olarak 0 döndürür
    }
    
    // Kök düğümün değeri ve alt ağaçlardaki düğümlerin değerleri toplamı
    return root->data + toplamDugum(root->left) + toplamDugum(root->right);
}

int AVL::asciiKarakter(Stack* myStack){
    int yapraksizToplam = toplamDugum() - myStack->toplamStack();
    int ascii = yapraksizToplam % (90 - 65 + 1) + 65;
    return ascii;
}

void AVL::setRoot(Node* tmp) {
    root = tmp;
}