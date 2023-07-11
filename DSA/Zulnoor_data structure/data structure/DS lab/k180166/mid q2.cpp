#include<iostream>
using namespace std;
class node
{
	node *next;
	public:
		int data;
		char y;
		node():next(0){
		}
		node(node *n);
		friend class dellist;
		friend class list2;
};
class dellist
{
	node *head;
	int size=0;
	public:
	friend class list2;	
	dellist():head(0){
	}
	void input_at_start(int a)
	{
		node *temp=new node();
		temp->data=a;
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
	void input_at_end(int a)
	{	
		node *temp=new node();
		node *current=new node();
		current=head;
		temp->data=a;
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
	void display()
	{
		int count=1;
		node *current=new node();
		current = head;
		while(current!=NULL)
		{
			cout<<current->data<<"<==>";
			current=current->next;
		}
		cout<<endl;
	}
//	void sll::delete_position(int node_pos)
//	{
//		node *temp=new node();
//		node *current=new node();
//		current=temp=head;
//		int count=1;
//		if(node_pos==1)
//		{
//			temp=head;
//			head=head->next;
//			delete temp;
//		}
//		else if(node_pos==size)
//		{
//			while(current->next->next!=NULL)
//			{
//				current=current->next;
//			}
//			temp=current->next;
//			current->next=NULL;
//			delete temp;
//		}
//		else if(node_pos>size)
//		{
//			return;
//		}
//		else
//		{
//			while(count+1!=node_pos)
//			{
//				count++;
//				current=current->next;
//			}
//			temp=current->next;
//			current->next=current->next->next;
//			delete temp;	
//		}
//	}
	void sort()
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
	void xyz(int c)
	{
		node *current=new node();
		int z=1;
		while(current->next!=NULL)
		{
			if(c==z)
			{
				list2::del(current->data);
			}
			z++;
			current=current->next;
		}
	}
};
class list2{
	node *head;
	int size=0;
	public:
	friend class dellist;
	list2():head(0){
	}
	void input_at_start(char b)
	{
		node *temp=new node();
		temp->y=b;
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
	void input_at_end(char b)
	{	
		node *temp=new node();
		node *current=new node();
		current=head;
		temp->y=b;
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
	void display()
	{
		int count=1;
		node *current=new node();
		current = head;
		while(current!=NULL)
		{
			cout<<current->y<<"<==>";
			current=current->next;
		}
		cout<<endl;
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
			return;
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
	void sort()
	{
		node *current=new node();
		node *temp=new node();
		char t;
		for(current=head;current->next!=NULL;current=current->next)
		{
			for(temp=current->next;temp!=NULL;temp=temp->next)
			{
				if(current->y>temp->y)
				{
					t=current->y;
					current->y=temp->y;
					temp->y=t;
				}
			}
		}
	}
	void del(int x)
	{
		int count =1;
		node *current=new node();
		node *temp=new node();
		if(current->next!=NULL)
		{
			if(count+1==x)
			{
				temp=current->next;
				current->next=current->next->next;
			}
			current=current->next;
			count++;
		}
		dellist::xyz(x);
	}

};
int main()
{
	dellist l2;
	list2 l1;
	int ch;
	int x;
	char y;
	cout<<"enter"<<endl<<"1)to input in list 1 (character list): "<<endl<<"2)to input in list 2 (int list): ";
	cout<<endl<<"3)to cancel"<<endl;
	do
	{
	cin>>ch;
	switch(ch)
	{
		case 1:
			cout<<"enter char: ";
			cin>>y;
			l1.input_at_end(y);
			break;
		case 2:
			cout<<"enter int: ";
			cin>>x;
			l2.input_at_end(x);
			break;
		case 3:
			break;		
	}
	}while(ch!=3);
	l1.sort();
	l2.sort();
	l2.xyz();
	l1.display();
	l2.display();
}
