#include<iostream>
#include "sll.h"
#include "node.h"
using namespace std;
sll::sll():head(0){
}
void sll::input_at_start(int d)
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
void sll::input_at_end(int d)
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
void sll::input_before(int d,int node_num)
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
void sll::input_after(int d,int node_num)
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
void sll::delete_start()
{
	node *temp=new node();
	temp=head;
	head=head->next;
	delete temp;
}
void sll::delete_end()
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
void sll::delete_position(int node_pos)
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
void sll::swap(node *a,node *b)
{
	node *temp=new node();
	node *temp2=new node();
	node *c1,*c2,*x,*y;
	c1=head;
	c2=head;
	if(a==head)
	{
		while(c2->next!=b)
		{
			c2=c2->next;
		}
		temp=x=head;
		temp2=y=c2->next;
		temp->next=c2->next->next;
		temp2->next=c1->next;
		c2->next=temp;
		head=temp2;
	}
	else
	{
		while(c1->next!=a)
		{
			c1=c1->next;
		}
		while(c2->next!=b)
		{
			c2=c2->next;
		}
		temp=x=c1->next;
		temp2=y=c2->next;
		temp->next=c2->next->next;
		temp2->next=c1->next->next;
		c1->next=c2->next;
		c2->next=temp;
	}
}
void sll::swapnode(node *n)
{
	node *temp=new node();
	node *c=new node();
	node *current=new node();
	current=head;
	int x=0;
	if(n->data==head->data)
	{
		temp=c=head;
		head=head->next;
		temp->next=head->next;
		head->next=temp;
		x++;
	}
	else if(n->data!=head->data)
	{
		while(current->next->next!=NULL||current->next==NULL)
		{
			if(current->next->data==n->data)
			{
				temp=current->next;
				current->next=current->next->next;
				temp->next=current->next->next;
				current->next->next=temp;
				x++;
				break;
			}
			current=current->next;
			if(current->next==NULL)
			{
				cout<<"data "<<n->data<<" is on last node"<<endl<<"can't be swapped"<<endl;
				x++;
				break;
			}
		}
	}
	if(!x)
	{
		cout<<"number "<<n->data<<" not found in list to swap"<<endl;
	}
}
void sll::reverse()
{
	node *current=new node();
	node *a=new node();
	current=head;
	while(current->next!=NULL)
	{
		current=current->next;
	}
	current->next=head;
	head=current;
	current=current->next;
	a=head;
	for(int i=0;i<size-1;i++)
	{
		while(current->next!=a)
		{
			current=current->next;
		}
		current->next=a->next;
		a->next=current;
		a=a->next;
	}
	a->next=NULL;	
}
void sll::dup()
{
	node *current = new node();
	for(current=head; current->next!=NULL; current = current->next)
	{
		node *temp = new node();
		for(temp = current; temp->next!=NULL;temp = temp->next)
		{
			if(temp==NULL)
			{
				break;
			}
			if(current->data == temp->data)
			{
				current->next = temp->next;
			}
		}
	}
}
void sll::sort()
{
	node *current=new node();
	node *temp=new node();
	int t;
	for(current=head;current->next!=NULL;current=current->next)
	{
		for(temp=current->next;temp!=NULL;temp=temp->next)
		{
			if(current->data>temp->data)
			{
				t=current->data;
				current->data=temp->data;
				temp->data=t;
			}
		}
	}
}
void sll::display()
{
	int count=1;
	node *current=new node();
	current = head;
	while(current!=NULL)
	{
		cout<<current->data<<"<==>";
		current=current->next;
	}
}
