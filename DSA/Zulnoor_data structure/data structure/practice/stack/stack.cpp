#include<iostream>
using namespace std;
class node
{
	node *next;
	public:
		int data;
		node():next(0){
		}
		friend class sll;
};
class sll
{
	
	int size=0;
	public:
		node *head;
		sll():head(0){
		}
		void input_at_start(int d)
		{
		node *temp=new node();
		temp->data=d;
		if(head==NULL)
		{
			head=temp;
			temp->next=NULL;
		}
		else if(head!=NULL)
		{
			temp->next=head;
			head=temp;
		}
		size++;
		}
		void input_at_end(int d)
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
				temp->next=NULL;
			}
			size++;
		}
		void input_before(int d,int node_num)
		{
			node *temp=new node();
			node *current=new node();
			current=head;
			temp->data=d;
			int count=1;
			if(!head)
			{
				cout<<"no list found"<<endl;
				exit(1);
			}
			if(node_num==1)
			{
				temp->next=head;
				head=temp;
			}
			else if(node_num>1&&node_num<=size)
			{
				while(count+1!=node_num)
				{
					current=current->next;
					count++;
				}
				temp->next=current->next;
				current->next=temp;
			}
			else if(node_num>size)
			{
				cout<<"size limit exceeded"<<endl;
				exit(0);
			}
			size++;
		}
		void input_after(int d,int node_num)
		{
			node *temp=new node();
			node *current=new node();
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
				while(current->next!=NULL)
				{
					current=current->next;
				}
				current->next=temp;
				temp->next=NULL;
			}
			else if(node_num>=size)
			{
				cout<<"size limit exceeded"<<endl;
				exit(0);
			}
			size++;
		}
		void delete_start()
		{
			node *temp=head;
			head=head->next;
			delete temp;
		}
		void delete_end()
		{
			node *temp=new node();
			node *current=new node();
			current=head;
			while(current->next->next!=NULL)
			{
				current=current->next;
			}
			temp=current->next;
			current->next=NULL;
			delete temp;
		}
		void delete_position(int node_pos)
		{
			node *temp=new node();
			node *current=new node();
			current=temp=head;
			int count=1;
			if(node_pos==1)
			{
				temp=head;
				head=head->next;
				delete temp;
			}
			else if(node_pos==size)
			{
				while(current->next->next!=NULL)
				{
					current=current->next;
				}
				temp=current->next;
				current->next=NULL;
				delete temp;
			}
			else if(node_pos>size)
			{
				cout<<"size limit exceeded"<<endl;
				exit(0);
			}
			else
			{
				while(count+1!=node_pos)
				{
					count++;
					current=current->next;
				}
				temp=current->next;
				current->next=current->next->next;
				delete temp;	
			}
		}
		void deletelist()
		{
			node *current=head;
			node *temp;
			while(current!=NULL)
			{
				temp=head;
				current=current->next;
				head=current;
				delete temp;
			}
		}
		void display()
    	{
			int count=1;
			node *current=head;
			if(head==NULL)
			{
				cout<<"no list"<<endl;
				exit(0);
			}
			while(current!=NULL)
			{
				cout<<current->data;
				if(current->next!=NULL)
				{
					cout<<"--->";
				}
				current=current->next;
			}
		}
};
class stack:public sll
{
	public:
		sll *stk;
		stack()
		{
			stk=new sll();
		}
		void push(int d)
		{
			stk->input_at_start(d);
		}
		void pop()
		{
			stk->delete_start();
		}
		void disp()
		{
			stk->display();
		}
};
int main()
{
	stack s1;
	s1.push(9);
	s1.push(8);
	s1.push(78);
	s1.push(76);
	s1.disp();
	cout<<endl;
	s1.pop();
	s1.disp();
	cout<<endl;
}
