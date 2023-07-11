#ifndef sll_h
#define sll_h
#include<iostream>
#include "node.h"
using namespace std;
class sll
{
	node *head;
	int size=0;
	public:
		sll();
		void dup();
		void input_at_start(int);
		void input_at_end(int);
		void input_before(int,int);
		void input_after(int ,int);
		void delete_start();
		void delete_end();
		void delete_position(int);
		void display();
		void sort();
		void swapnode(node *n);
		void reverse();
		void swap(node *a,node *b);
};
#endif
