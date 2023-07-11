#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node *next;
		Node():data(0),next(0){}
		Node(int data, Node * ptr = 0)
		{
			this->data=data;
			next=ptr;
		}
};
class SLL{
	private:
		Node *head, *tail;
		
	public:
		int size;
		SLL()
		{
			head=tail=0;
			size=0;
		}
		void InsertFront(int val)
		{
			if(head==0)		//if list empty
				{
				head=tail=new Node(val,head);
				}
			else{			//list not empty
				Node *newptr= new Node(val,head);
				newptr->next=head;
				tail=head;
				head=newptr;
			}
			size++;
		}
		void InsertTail(int val)
		{
			if(tail!=0)
				{
				tail->next=new Node(val);
				tail=tail->next;
				}
			else
				head=tail=new Node(val);
			size++;
		}
		void InsertBefore(int bf,int val)
		{
			
			if(bf==head->data)
			{
				Node *newNode = new Node(val);
				newNode->next=head;
				head=newNode;	
			}
			else{
			
			Node *temp=head;
			while(temp->next->data !=bf)
				temp=temp->next;
			Node *newNode = new Node(val);
			newNode->next=temp->next;
			temp->next=newNode; }
			size++;
		}
		void InsertAfter(int af,int val)
		{
			if(af==tail->data)
			{
				Node *newptr= new Node(val);
				tail->next=newptr;
				tail=newptr;
			}
			else
			{
				Node *temp=head;
				while(temp->data!=af)
					temp=temp->next;
				Node *newNode = new Node(val);
				newNode->next=temp->next;
				temp->next=newNode;
			
			}
			size++;
		}
		void InserAt(int val,int pos)
		{
			Node *temp=head;
			for(int i=0;i<pos-1;i++)
				temp=temp->next;
			Node *newNode = new Node(val);
			newNode->next=temp->next;
			temp->next=newNode;
			size++;
		}
		int DeleteHead()
		{
			Node *temp=head;
			int el=head->data;
			if(head==tail)		//only one node
				head=tail=0;
			else
				head=head->next;
			delete temp;
			size--;
			return el;
			
		}
		int DeleteTail()
		{
			
			int el=tail->data;
			if(tail==head)
				{
					delete head;
					head=tail=0;
				}
			else
				{
					Node *temp;
					for(temp=head; temp->next != tail; temp=temp->next);
					delete tail;
					tail = temp;
					tail->next=0;
				}
			size--;
			return el;
			
		}
		void DeleteNode(int val)
		{
			if(head != 0)
			{
				if(head==tail && val==head->data) 	//if only one node
				{
					delete head;
					head = tail = 0;
				}
				else if(val==head->data)	//if node is head
				{
					Node *temp=head;
					head=head->next;
					delete temp;
				}
				else if(val==tail->data)	//if node is tail
				{
					Node *current=head;
					while(current->next != tail)
					{
						current=current->next;
					}
					
					delete tail;
					tail=current;
					tail->next=0;
				}
				else				//beech wale node
				{
					Node *current = head;
					while(current->next->data != val)
					{
						current=current->next;
					}
					current->next=current->next->next;
					//tail=current->next->next;
				}
			}
		size--;
		}
		void getHead()
		{
			cout<<"Head : "<<head->data<<endl;
		}
		void getTail()
		{
			cout<<"Tail : "<<tail->data<<endl;
		}
		void SearchNode(int d)
		{
			Node *current=head;
			while(current!=NULL)
			{
				if(current->data==d)
				{
					cout<<"element "<<d<<" found"<<endl;
					return;
				}
				current=current->next;
			}
			cout<<"element "<<d<<" not found"<<endl;
		}
		void print()
		{
			if(head==0)
				cout<<"List is empty";
			else
			{
				Node *currptr = head;
				while(currptr!=0)
				{
					cout<<currptr->data<<" ";
					currptr=currptr->next;
				}
			}
		}
};

void chaining(SLL *arr,int d,int n)
{
	
	int key;
	key = d % n;
	for(int i=0;i<key;i++,arr++)
	{
	}
	arr->InsertTail(d);
	
}

void search(SLL *arr,int d,int n)
{
	
	int key;
	key = d % n;
	for(int i=0;i<key;i++,arr++)
	{
	}
	arr->SearchNode(d);
	
}
void chaining_delete(SLL *arr,int d,int n)
{
	
	int key;
	key = d % n;
	for(int i=0;i<key;i++,arr++)
	{
	}
	arr->DeleteNode(d);
	
}


int main()
{

	int size;
	cout<<"enter the size of the array : ";
	cin>> size;
	SLL a[size];
	chaining(a,0,size);
	chaining(a,5,size);
	chaining(a,11,size);
	chaining(a,5,size);
	chaining(a,5,size);
	
cout<<endl;
for(int i=0;i<size;i++)
{
		
		cout<<"value at index "<<i<<" is : ";
		a[i].print();
		cout<<endl<<endl;

}
chaining_delete(a,5,size);
chaining_delete(a,0,size);

cout<<endl<<endl<<endl;
for(int i=0;i<size;i++)
{
		
		cout<<"value at index "<<i<<" is : ";
		a[i].print();
		cout<<endl<<endl;

}	

search(a,11,size);
search(a,6,size);
	return 0;
	
}
