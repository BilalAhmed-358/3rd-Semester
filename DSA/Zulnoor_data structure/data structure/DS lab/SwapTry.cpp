#include<iostream>
using namespace std;

class node {
public:  
    int data;
    node *next;
//node *previous;
 public:
  
  node(int a){
		data=a;
		next=NULL;
	}

	node(int a,node *ptr){
		data=a;
		next=ptr;
	}



};
class Linklist{

	private:
		node *head,*tail;

	public:
		Linklist(){
			head=NULL;
			tail=NULL;
		}

		add_note_to_head(int n){

			if(head==NULL)
			{
				head= new node(n);

			}

			else{

				head = new node (n,head);

			}
		}
		add_note_to_tail(int n){

			if(tail==NULL && head==NULL){
				head = tail = new node(n);
			}
			else {
				node *nn = new node(n);
				tail->next = nn;
				tail = nn;
			}
		}
		void print() {
			node *n = head;
			while(n!= NULL) {
				cout<<n->data<<" ";
				n = n->next;
			}
		}

//Give Index to put new Node....
		add_data_in_middle(int n,int size){

			node *temp = head;

			for(int k = 0;k<size-1;k++){
				temp = temp->next;

			}

			node *ptr = temp->next;

			node *newone = new node(n,temp->next);
			temp->next = newone;

		}
		add_data_in_middle_before(int n,int size){

			node *temp = head;

			for(int k = 0;k<size-2;k++){
				temp = temp->next;

			}

			node *ptr = temp->next;

			node *newone = new node(n,temp->next);
			temp->next = newone;

			}
		add_data_in_middle_After(int n,int size){

			node *temp = head;

			for(int k = 0;k<size;k++){
				temp = temp->next;

			}

			node *ptr = temp->next;

			node *newone = new node(n,temp->next);
			temp->next = newone;

		}
// Give Index and delete that..

		delete_data_in_middle(int size){

			node *temp=head;

			for(int k=0 ; k<size-1; k++){
				temp = temp->next;

			}

			node *ptr = temp->next;
//node *ptr1 = temp->next->next;

			temp->next = ptr->next;
		
		}
		delete_data_in_middle_Before(int size)
		{

			node *temp=head;

			for(int k=0 ; k<size-2; k++){
					temp = temp->next;

			}

			node *ptr = temp->next;
//node *ptr1 = temp->next->next;

			temp->next = ptr->next;

		}
		delete_data_in_middle_after(int size)
		{

			node *temp=head;

			for(int k=0 ; k<size; k++){
				temp = temp->next;

			}

			node *ptr = temp->next;
//node *ptr1 = temp->next->next;

			temp->next = ptr->next;

		}

		int length_of()
		{
			node *temp=head;
			int counter=0;
			
			for( ;temp!=NULL; ){
				
				temp=temp->next;
				counter++;
 			}
			return counter;
		}

		node* Search_Temp(int Index)
		{
				node *temp = head;
				int i = 0;
				
				while (1)
				{
					
					if(i > Index){
						return 0;
					}	
					if(i == Index){
						return temp;
					}
		
					temp = temp->next;		
					i++;
				}
				return NULL;

		}

		int Search(int dat){
				
				node *temp = head;
				int counter = 0;
				
				for( ; temp->data!=dat ; ){
					temp = temp->next ;
					counter++ ;

					if(temp == NULL){
						cout<<"Not found\n" ;
						return -1 ;
					}
				}
				return counter;

		}
		
//SWAPPING DATAAA.....

		void swap(int dat1,int dat2 ){

			if(head==NULL){
				return;
			}
			node *temp = head;
			node *tmp = head;
			
		//For Data 1

			while(temp->data!=dat1 ){
				
				temp=temp->next;
			}
		
		//FOr DAT2
		
			while(tmp->data!=dat2 ){
				
				tmp=tmp->next;
			}

			node *ptr=new node(temp->data);
			temp->data=tmp->data;
			tmp->data=ptr->data;



		}

		void Swap_Node(int Index ,int Index2 ){
				
				
			node *temp = Search_Temp(Index);
			node *temp2 = Search_Temp(Index2);
			
			if(temp == head){
				node *One_greater = Search_Temp(Index2+1);	
				node *lessone = Search_Temp(Index2-1);
				lessone->next = temp;
				temp2->next = temp -> next ;
				temp->next = One_greater ;
				head = temp2;
				
					
			}
			
			else 
			{
				
				node *One_greater_2 = Search_Temp(Index2+1);	
				node *lessone_2 = Search_Temp(Index2-1);
				node *One_greater_1 = Search_Temp(Index+1);	
				node *lessone_1 = Search_Temp(Index-1);
				lessone_1 -> next = temp2 ;
				lessone_2 -> next = temp ;
				temp2 -> next = temp->next;
				temp -> next = One_greater_2 ;
				
					if(temp2 == tail){
						tail = temp;
					}				
				
			}
			
			
		
		}
		~Linklist()
		{
			node *temp = head;

			for( ;temp!=NULL;){

			//head=head->next;
				temp =head;
				head = head->next;
				delete temp;
				temp=head;
				cout<<"DELETE>>\n";


			}
			// cout<<"TAIL>>DELETE\n";
			// delete tail;
		}
	
	protected:
		
};


int main(){
Linklist *l=new Linklist();
l->add_note_to_tail(8);
l->add_note_to_tail(10);
l->add_note_to_tail(20);
l->add_note_to_head(2);
l->add_note_to_head(16);
l->add_note_to_head(00);
l->print();
l->add_data_in_middle_After(88,2);
cout<<endl;

l->print();

l->delete_data_in_middle(2);
cout<<endl;
l->print();

//cout<<"\nIndex="<<l->Search(88)<<endl;

//cout<<"LENGTH_="<<l->length_of();
l->swap(8,20);
cout<<"\nAFTER SWAPPING\n";
l->print();
cout<<"\nNow\n";
l->Swap_Node(1,5);
l->print();

delete l;
}
