#ifndef dll_h
#define dll_h
#include <iostream>
#include "node.h"
using namespace std;

class dll
{
	node *head;
	public:
		int size=0;
		dll();
		void insert_at_beg(int);
		void insert_at_end(int);
		void insert_after(int,int);
		void insert_before(int,int);
		void delete_1st();
		void delete_last();
		void delete_node_num(int);
		void search(int);
		void display();
};
#endif

