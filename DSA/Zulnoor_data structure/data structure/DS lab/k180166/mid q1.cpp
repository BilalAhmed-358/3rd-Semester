#include<iostream>
using namespace std;
class node
{
	node *next;
	public:
		int x;
		int y;
		node():next(0){
		}
		node(node *n);
		friend class seq;
};
class seq
{
	node *head;
	int size=0;
	public:
	seq():head(0){
	}
	void input_at_start(int a,int b)
	{
		node *temp=new node();
		temp->x=a;
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
	void input_at_end(int a,int b)
	{	
		node *temp=new node();
		node *current=new node();
		current=head;
		temp->x=a;
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
			cout<<current->x<<"/"<<current->y<<"<==>";
			current=current->next;
		}
		cout<<endl;
	}
	void sequence(int n)
	{
		node *temp=new node();
		node *current = new node();
		node *current2 = new node();
		current=head;
		current2=head;
		for(int i=1;i<n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				while(current->next!=NULL)
				{
					temp->x=current->x+current->next->x;
					temp->y=current->y+current->next->y;
					if(temp->x<=n&&temp->y<=n)
					{
						temp->next=current->next;
						current->next=temp;
					}
					current=current->next;
				}
			}
			current=head;
		}
		
	}
};
int main()
{
	seq s;
	s.input_at_start(0,1);
	s.input_at_end(1,1);
	s.display();
	s.sequence(3);
	s.display();
}
