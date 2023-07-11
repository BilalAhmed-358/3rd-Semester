#include<iostream>
using namespace std;
class node
{
	public:
		node *next;
		int data;
		node():next(0)
		{
			
		}
		friend class cll;
};
class cll
{
	public:
		node *head;
		node *tail;
		int size=0;
		cll():head(0),tail(0)
		{
			
		}
		void insert_at_head(int d)
		{
			node *temp =new node();
			temp->data=d;
			if(!head)
			{
				head=temp;
				tail=temp;
			}
			else
			{
				temp->next=head;
				head=temp;
				tail->next=head;
			}
		}
		void insert_at_tail(int d)
		{
			node *temp =new node();
			temp->data=d;
			if(!head)
			{
				head=temp;
				tail=temp;
			}
			else
			{
				node  *current=head;
				while(current!=tail)
				{
					current=current->next;
				}
				current->next=temp;
				tail=temp;
				tail->next=head;
			}
		}
		void  display()
		{
			node *current=head;
			cout<<current->data<<" ";
			current=current->next;
			while(current!=head)
			{
				cout<<current->data<<" ";
				current=current->next;
			}
		}
		int length(node *current,int l)
		{
			if(current==NULL)
				return 0;
			if(current==head)
				return l+1;
				
			l++;
			length(current->next,l);	
		}
		void setsize(int l)
		{
			size=l;
		}
		void split(cll &a,cll &b)
		{
			node *current=head;
			for(int i=0;i<size/2;i++)
			{
				a.insert_at_tail(current->data);
				current=current->next;
			}
			
			for(int i=size/2;i<size;i++)
			{
				b.insert_at_tail(current->data);
				current=current->next;
			}
		}
};
int main()
{
	cll c;
	c.insert_at_tail(4);
	c.insert_at_head(5);
	c.insert_at_tail(8);
	c.insert_at_tail(7);
	c.insert_at_head(12);
	c.insert_at_head(9);
	cout<<"main list"<<endl;
	c.display();
	c.setsize(c.length(c.head->next,0));
	cll a;
	cll b;
	c.split(a,b);
	cout<<endl<<"sub list 1"<<endl;
	a.display();
	cout<<endl<<"sub list 2"<<endl;
	b.display();
}
