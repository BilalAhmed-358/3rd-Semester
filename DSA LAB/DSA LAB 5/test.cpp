#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* next;
		
};
class list{
	public:
		node* head;
		list(){
			head=NULL;
			}
		list(int d){
			head=new node;
			head->data=d;
			head->next-NULL;
		}
		InsertAtEnd(int d)
		{
			node *newnode;
			newnode->data=d;
			newnode->next=NULL;
			node* temp=head;
			// newnode=new node;
			
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=newnode;
			
			}	
			void display()
		{
			node *temp=head;
			cout<<temp->data;
			while(temp->next!=NULL)
			{
				temp=temp->next;
				
			}
			cout<<temp->data;
			}	
	};
	int main()
	{
		list l1(6);
		l1.InsertAtEnd(6);
		l1.InsertAtEnd(7);
		l1.display();
	}