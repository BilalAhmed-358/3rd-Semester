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
	public:
		node *head;
		int size=0;
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
			node *temp=new node();
			temp=head;
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
			node *current=new node();
			current = head;
			if(head==NULL)
			{
				cout<<"no list"<<endl;
				exit(0);
			}
			while(current!=NULL)
			{
				cout<<current->data<<"<==>";
				current=current->next;
			}
		}
		void sum(int x)
		{
			node *current=head;
			while(current->next!=NULL)
			{
				if(current->data+current->next->data==x)
				{
					cout<<current->data<<" + "<<current->next->data<<" = "<<x<<endl;
				}
				current=current->next;
			}
		}
		int length(node *current,int l)
		{
			if(current==NULL)
				return l;
			
			l++;
			length(current->next,l);		
		}
		bool search(node *current,int d)
		{
			if(current==NULL)
				return 0;
			
			if(current->data==d)
				return 1;
			search(current->next,d);		
		}
};
int main()
{
	sll L1;
	L1.input_at_start(5);
	L1.input_at_start(4);
	L1.input_after(3,2);
	L1.input_at_end(1);
	L1.input_at_end(4);
	L1.input_before(3,2);
	L1.input_at_end(2);
	L1.input_at_end(5);
	L1.display();
	cout<<endl;
//	L1.deletelist();
//	L1.display();
	L1.sum(999);
	int len=L1.length(L1.head,0);
	cout<<"length of linked list is: "<<len<<" "<<L1.size<<endl;
	int b=L1.search(L1.head,6 );
	if(b)
		cout<<"data found in linked list"<<endl;
	else
		cout<<"data not found in linked list"<<endl;	
}
