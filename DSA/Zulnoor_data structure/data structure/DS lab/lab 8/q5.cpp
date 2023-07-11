#include<iostream>
using namespace std;
class node
{
	node *next;
	node *prev;
	int data;
	public:
		node():prev(0),next(0){
		}
		friend class dll;
};
class dll
{
	node *head;
	public:
		int size=0;
		dll():head(0){
		}	
		void insert_at_beg(int d)
		{
			node *temp=new node();
			temp->data=d;
			if(!head)
			{
				head=temp;
			}
			else
			{
				temp->next=head;
				head->prev=temp;
				head=temp;
			}
			size++;
		}
		void insert_at_end(int d)
		{
			node *temp=new node();
			node *current=new node();
			current=head;
			temp->data=d;
			if(!head)
			{
				head=temp;		
			}
			else
			{
				while(current->next!=NULL)
				{
					current=current->next;
				}
				current->next=temp;
				temp->prev=current;
				size++;
			}
		}
		void display()
		{
			node *current=new node();
			current=head;
			while(current!=NULL)
			{
				cout<<current->data;
				if(current->next!=NULL)
				{
					cout<<"<=>";
				}
				current=current->next;
			}
		}
//		void sort()
//		{
//			node *current1 , *current2;
//			current1=head;
//			current2=current1->next;
//			while(current2->next!=NULL)
//			{
//				if(current1->data > current2->data)
//				{
//					current2->prev->next=current2->next;
//					current2->next->prev=current2->prev;
//					node *temp=new node();
//					temp=current2;
//					current2->next=current2->prev=NULL;
//					
//					head=temp;
//				}
//			}
//		}
		void sum_pair(int x)
		{
			node *current,*current2;
			for(current=head;current->next!=NULL;current=current->next)
			{
				for(current2=current->next;current2->next!=NULL;current2=current2->next)
				{
					if((current->data+current2->data)==x)
					{
						cout<<"("<<current2->data<<","<<current->data<<") ";
					}
				}
			}
		}
};
int main()
{
	dll l;
	l.insert_at_end(5);
	l.insert_at_end(6);
	l.insert_at_end(8);
	l.insert_at_end(9);
	l.insert_at_beg(4);
	l.insert_at_beg(2);
	l.insert_at_beg(1);
	l.display();
	cout<<endl;
	l.sum_pair(7);
}
