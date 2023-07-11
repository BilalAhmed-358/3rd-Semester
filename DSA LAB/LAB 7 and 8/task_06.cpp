#include<iostream>
using namespace std;
class node{
	public:
		int data;
		int key;
		node *next;
		
		node(int d,int k)
		{
			data=d;
			key=k;
			next=0;
		}
};

class Queue{
	public:
		node *head;
		Queue()
		{
			head=0;
		}
		void Enqueue(int data,int key)
		{
			node *new_node=0;
			if(head==0)
			{
				head = new node(data,key);
			}
			else if(head->key<key)
			{
				new_node=new node(data,key);
				new_node->next=head;
				head=new_node;
			}
			else
			{
				bool node_made=false;
				node *tmp=head;
				while(tmp->next!=0)
				{
					if(tmp->next->key<key)
					{
						new_node=new node(data,key);
						new_node->next=tmp->next;
						tmp->next=new_node;
						node_made=true;
						break;
					}
					tmp=tmp->next;
				}
				if(node_made==false)
				{
					new_node=new node(data,key);
					tmp->next=new_node;
				}		
			}
		}
		int Dequeue()
		{
			if(head!=0)
			{
				node *tmp_delete=0;
				tmp_delete=head;
				int tmp_data=tmp_delete->data;
				head=head->next;
				delete tmp_delete;
				return tmp_data;
			}	
		} 
		void deletion(int data)
		{
			if(head!=0)
			{
				node *tmp_delete=0;
				if(head->data==data)
				{
					tmp_delete=head;
					head=head->next;
					delete tmp_delete;
				}
				node *tmp=head;
				while(tmp->next!=0)
				{
					if(tmp->next->data==data)
					{
						tmp_delete=tmp->next;
						tmp->next=tmp_delete->next;
						int tmp_data=tmp_delete->data;
						delete tmp_delete;
					}
					tmp=tmp->next;
				}
			}	
		}
		int next(int index)
		{
			if(head!=0)
			{
				node *tmp=head;
				for(int i=0;i<index;i++)
				{
					tmp=tmp->next;
					if(tmp==0)
					{
						cout<<"Not available"<<endl;
						return 0;
					}
				}
				return tmp->data;
			}
		}
		void Display()
		{
			if(head!=0)
			{
				node *tmp=head;
				while(tmp!=0)
				{
					cout<<tmp->data<<" ";
					tmp=tmp->next;
				}
				cout<<endl;
			}
		}
};

int main()
{
	Queue q1;
	q1.Enqueue(1,4);
	q1.Enqueue(5,7);
	q1.Enqueue(3,2);
	cout<<q1.Dequeue()<<endl;
	cout<<q1.next(1)<<endl;
	q1.Display();	
}