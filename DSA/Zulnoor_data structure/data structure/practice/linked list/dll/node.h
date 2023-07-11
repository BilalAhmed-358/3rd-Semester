#ifndef node_h
#define node_h
#include<iostream>
using namespace std;
class node
{
	node *next;
	node *prev;
	int data;
	public:
		node();
		friend class dll;
};
#endif
