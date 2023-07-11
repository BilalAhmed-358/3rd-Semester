#ifndef SLL_H
#define SLL_H
#include "Node.h"

class Ssl{
	private:
		Node *head;
		int size;
	public:
		Ssl();
		Ssl(int);
	void Insert_at_Head(int);//Insert at Start 
    void Insert_at_End(int);//Insert at last
    void Insert_Before(int,int);//insert before a specific data
    void Insert_After(int,int);//Insert after a specific data
    void Insert_at(int,int);//Insert at a specific position
    void Delete_from_End();//Delete Last node
    void Delete_from_front();//Delete first node from front 
    void Delete_at(int);// Detele at a specific Position
    void Delete_before(int);// Delete the node before the data
    void Delete_After(int);//Delete the node after the data 
    void Display();//Displays the list
    int Search_data(int);//search the data and return the node number if present, else return -1.  
    int Length_of_list();//counts the number of nodes in list
};
#endif
