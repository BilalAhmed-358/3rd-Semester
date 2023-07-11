#include <iostream>
#include "dll.h"
using namespace std;
dll::dll():head(0){
}
void dll::insert_at_beg(int d){
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
void dll::insert_at_end(int d){
	node *temp=new node();
	node *current=new node();
	current=head;
	temp->data=d;
	while(current->next!=NULL)
	{
		current=current->next;
	}
	current->next=temp;
	temp->prev=current;
	size++;
}
void dll::insert_after(int d,int node_num)
{
	node *temp=new node();
	node *current=new node();
	current=head;
	temp->data=d;
	int count=1;
	if(node_num==size)
	{
		while(current->next!=NULL)
		{
			current=current->next;
		}
		current->next=temp;
		temp->prev=current;
	}
	else if(node_num<size)
	{
		while(count!=node_num)
		{
			current=current->next;
			count++;
		}
		temp->next=current->next;
		current->next->prev=temp;
		current->next=temp;
		temp->prev=current;
	}
	else if(node_num>size)
	{
		cout<<"size limit exceeded"<<endl;
		exit(0);
	}
	size++;
}
void dll::insert_before(int d,int node_num)
{
	node *temp=new node();
	node *current=new node();
	current=head;
	temp->data=d;
	int count=1;
	if(node_num==1)
	{
		temp->next=head;
		head->prev=temp;
		head=temp;
	}
	else if(node_num<=size)
	{
		while(count+1!=node_num)
		{
			current=current->next;
			count++;
		}
		temp->next=current->next;
		current->next->prev=temp;
		current->next=temp;
		temp->prev=current;
	}
	else if(node_num>size)
	{
		cout<<"size limit exceeded"<<endl;
		exit(0);
	}
	size++;
}
void dll::search(int num){
	node *current=new node();
	current=head;
	int count=1;
	int x=0;
	if(!head)
	{
		cout<<"list not available"<<exit;
		exit(0);
	}
	while(count<=size)
	{
		if(current->data==num)
		{
			cout<<"number "<<num<<" found at node number "<<count<<endl;
			x++;
			break;
		}
			current=current->next;
			count++;
	}
	if(!x)
		cout<<"number "<<num<<" not found in the list"<<endl;
}
void dll::delete_1st(){
	node *temp=new node();
	temp=head;
	head=head->next;
	head->prev=NULL;
	temp->next=NULL;
	delete temp;
	size--;
}
void dll::delete_last(){
	node *temp=new node();
	node *current=new node();
	current=head;
	while(current->next!=NULL)
	{
		current=current->next;
	}
	temp=current;
	current->prev->next=NULL;
	current->prev=NULL;
	delete temp;
	size--;
}
void dll::delete_node_num(int node_num)
{
	node *temp=new node();
	node *current=new node();
	current=head;
	int count=1;
	while(count!=node_num)
	{
		count++;
		current=current->next;
	}
	temp=current;
	current->prev->next=current->next;
	current->prev=NULL;
	current->next=NULL;
	delete temp;
	size--;
}
void dll::display(){
	node *current=new node();
	current=head;
	int count=1;
	if(!head)
	{
		cout<<"list not available"<<exit;
		exit(0);
	}
	while(count<=size)
	{
		cout<<"-------------------------"<<endl;
		cout<<"NODE "<<count<<endl;
		cout<<current->data<<endl;
		cout<<"-------------------------"<<endl;
		current=current->next;
		count++;
	}
}

