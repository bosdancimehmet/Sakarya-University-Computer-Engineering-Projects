#ifndef AVL_HPP
#define AVL_HPP
#include "AvlDugum.hpp"
#include "Stack.hpp"
class AVL {
private:
    Node* root;
    Node* SearchAndAdd(Node* subNode, const int& item);
    Node* SwapWithLeftChild(Node* subNode);
    Node* SwapWithRightChild(Node* subNode);
    bool DeleteNode(Node*& subNode);
    void inorder(Node* subNode);
    void preorder(Node* subNode);
    void postorder(Node* subNode);

    int Height(Node* subNode);
    void PrintLevel(Node* subNode, int level);
    bool Search(Node* subNode, const int& item);
public:
    AVL();
	Stack* myStack;
    bool isEmpty() const;
    void Add(const int& item);
    void inorder();
    void preorder();
    void postorder();
    void levelorder();
    int Height();
    bool Search(const int& item);
    void Clear();
	void postorderLeafNodes(Node* root);
	Node* getRoot();
	void setRoot(Node* tmp);
	int toplamDugum();
	int toplamDugum(Node* root);
	int asciiKarakter(Stack*myStack);
	
    ~AVL();
};
#endif
