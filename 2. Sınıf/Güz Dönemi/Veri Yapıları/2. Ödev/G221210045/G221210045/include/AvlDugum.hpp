#ifndef AVL_DUGUM_HPP
#define AVL_DUGUM_HPP
struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    Node(const int& vr, Node*, Node*); 
	Node(int data);
};
#endif
