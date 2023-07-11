#ifndef node_h
#define node_h
#include<iostream>
using namespace std;
class node
{
	node *next;
	public:
		int data;
		node();
		node(node *n);
		friend class sll;
};
#endif
