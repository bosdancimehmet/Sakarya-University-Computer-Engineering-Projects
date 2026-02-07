#ifndef STACK_HPP
#define STACK_HPP
#include "StackDugum.hpp"
class Stack{
	public:
		StackNode* root;
		Stack();
		bool isEmpty();
		void push(int sayi);
		void pop();
		void yazdir();
		void clear();
		int top();
		int toplamStack();
		int toplamStack(StackNode* root);
};
#endif
