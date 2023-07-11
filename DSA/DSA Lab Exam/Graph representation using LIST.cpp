#include<bits/stdc++.h>
using namespace std;
class Node
{
	int data;
	Node* next;
	public:
		Node(int data)
		{
			this->data=data;
			this->next=NULL;
		}
		friend class Graph;
};
//Graph using Adjacency list for Directed Graph:
class Graph
{
	public:
	Node* head;
	
	Graph()
	{
		this->head=NULL;
	}
	void Create(int v1,int v2)
	{
		
		if(head==NULL)
		{
			Node* Newnode=new Node(v2);
			head=Newnode;
		}
		else
		{
						
		Node* NewNode=new Node(v2);
		Node* temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=NewNode;
	}
	}
	void Print(int i)
	{
		Node* temp=head;
		
		cout<<i;
		while(temp!=NULL)
		{
			cout<<"-->"<<temp->data;
			temp=temp->next;
		}
		cout<<"-->NULL";
		cout<<endl;
	}
};
int main()
{
	int vertices;
	cout<<"Enter the number of vertices your graph have "<<endl;
   	cin>>vertices;
	Graph *Add_List[vertices];
	for(int i=0;i<vertices;i++)
	{
		Add_List[i]=new Graph;
		Add_List[i]->head=NULL;
	}
	int v1,v2;
	cout<<"How many edges your graph has: "<<endl;
	int edges;
	cin>>edges;
	for(int i=0;i<edges;i++)
	{
	   cin>>v1;
	   cin>>v2;
	   Add_List[v1]->Create(v1,v2);
//	   For Undirected UnComment this....
//	   Add_List[v2]->Create(v2,v1);
    }
    for(int i=0;i<vertices;i++)
    {
    	Add_List[i]->Print(i);
    	cout<<endl;
	}
     
}
