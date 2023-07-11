#include<iostream>
using namespace std;
class node
{
	node *next;
	public:
		int data;
		node():next(0){
		}
		friend class cll;
};
class cll
{
	node *head;
	node *tail;
	int size=0;
	public:
		cll():head(0),tail(0){
		}
		void input_at_start(int d)
		{
			node *temp=new node();
			temp->data=d;
			if(head==NULL)
			{
				head=temp;
				tail=temp;
				tail->next=head;
			}
			else if(head!=NULL)
			{
				temp->next=tail->next;
				head=temp;
				tail->next = temp;
			}
			size++;
		}
		void input_at_end(int d)
		{
			node *temp=new node();
			node *current;
			current=head;
			temp->data=d;
			if(!head)
			{
				head=temp;
				tail=temp;
				tail->next=head;
			}
			else
			{
				while(current->next!=head)
				{
					current=current->next;
				}
				current->next=temp;
				tail=temp;
				temp->next=head;
			}
			size++;
		}
		void input_after(int d,int node_num)
		{
			node *temp=new node();
			node *current;
			current=head;	
			temp->data=d;
			int count=1;
			if(!head)
			{
				cout<<"no list found"<<endl;
				exit(1);
			}
			if(node_num>=1&&node_num<size)
			{
				while(count!=node_num)
				{
					current=current->next;
					count++;
				}
				temp->next=current->next;
				current->next=temp;
			}	
			else if(node_num==size)
			{
				while(current->next!=head)
				{
					current=current->next;
				}
				current->next=temp;
				tail = temp;
				tail->next=head;
			}
			else if(node_num>=size)
			{
				cout<<"size limit exceeded"<<endl;
				exit(0);
			}
			size++;
		}
		void display()
		{
			node *current;
			current = head;
			while(current->next!=head)
			{
				cout<<current->data<<"<==>";
				current=current->next;
			}
			cout<<current->data<<endl;
		}
		void sort();
		void swapnode(node *n);
		void swap(node *a,node *b);
};
int main()
{
	cll L1;
	L1.input_at_start(5);
	L1.input_at_start(5);
	L1.input_after(3,2);
	L1.input_at_end(1);
	L1.input_at_end(4);
	L1.input_at_end(2);
	L1.input_at_end(5);
	L1.input_after(8,7);
	L1.display();
}
