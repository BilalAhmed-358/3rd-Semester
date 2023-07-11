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
			if(node_num>=1&&node_num<=size)
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
			else if(node_num>size)
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
		void sort()
		{
			node *current1 , *current2 ,*c1,*c2;
			node *temp1=new node();
			node *temp2=new node();
			current1=head;
			while(current1->next!=head)
			{
				current2=current1->next;
				while(current2->next!=head)
				{
					if(current1->next->data > current2->next->data)
					{
						temp1=current1->next;
						temp2=current2->next;
						c1=current1->next;
						c1->next=current1->next->next;
						c2=current2->next;
						c2->next=current2->next->next;
						current1->next=temp2;
						temp2->next=c1->next;
						current2->next=temp1;
						temp1->next=c2->next;
					}
					current2=current2->next;
				}
				current1=current1->next;
			}
		}
		void insert_new_node_sorted(int d)
		{
			node *temp=new node();
			node *current;
			current=head;
			temp->data=d;
			int pos=1;
			if(current->data > temp->data)
			{
				input_after(temp->data,pos);
			}
			else
			{
				while(current->next!=head)
				{
					if(current->next->data > temp->data)
					{
						input_after(temp->data,pos);
						break;
					}
					pos++;
					current=current->next;
				}
			}
		}
};
int main()
{
	cll L1;
	L1.input_at_start(7);
	L1.input_at_start(3);
	L1.input_at_end(9);
	L1.input_at_end(11);
	L1.display();
	L1.insert_new_node_sorted(8);
//	L1.sort();
//	cout<<"after sort"<<endl;
	L1.display();
}
