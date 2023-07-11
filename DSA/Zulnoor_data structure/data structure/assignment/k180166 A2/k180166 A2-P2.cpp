#include<iostream>
#include <fstream>
#include <sstream> 
#include<string>
using namespace std;
class node{
	node *next;
	public:
		int num;
		node():next(0){
		}
		friend class palindrome;
};
class palindrome{
	node *head;
	int n;
	int a;
	public:
		//default constructor
		palindrome():head(0){
		}
		//function to insert node at head of linked list
		void insert_at_head(int n)
		{
			node *temp=new node();
			temp->num=n;
			if(head)
			{
				temp->next=head->next;
				head=temp;
			}
			else
			{
				head=temp;
				temp->next=NULL;
			}
		}
		//function to insert node at end of linked list
		void insert_at_tail(int n)
		{
			if(!head)
			{
				insert_at_head(n);
			}
			else
			{
				node *temp=new node();
				node *current=new node();
				temp->num=n;
				current=head;
				while(current->next!=NULL)
				{
					current=current->next;
				}
				current->next=temp;
				temp->next=NULL;
			}
		}
		//function to read from a file
		void input()
		{
			//opening a file in input format
			ifstream inp("input2.txt");
			//loop to check if eof not reached
			while(!inp.eof())
			{
				//reading number of data for nodes present 
				inp>>a;
				//loop from 0 to a
				for(int i=0;i<a;i++)
				{
					//reading number stored in a file
					inp>>n;
					//creating a node at end of linked list
					insert_at_tail(n);
				}
			}
			//closing a file
			inp.close();
		}
		//function to find palindrome
		void find_palindrome(string s)
		{
			int len,check=0;
			string temp,temp2,temp3;
			//initializing int len with length of concatinated string
			len=s.length();
			cout<<"length of string: "<<len<<endl;
			//initializing string temp2 with string s
			temp2=s;
			//loop from 0 to length of string s
			for(int i=0;i<len;i++)
			{
				//string iterator
				string::iterator it;
				//initialzing temp with temp2
  				temp=temp2;
  				//assigniong value of (length of temp2-1) to j 
  				int j=temp2.length()-1;
  				//loop till j is not equals to 0 
				while(j>0)
				{	
					//initializing int index to length of temp-1				
					int index=temp.length()-1,start=0,count=0;
					//loop to check palindrome
					while(start<index)
					{
						//checking if temp[start] is equals to temp[index]
						if(temp[start++]==temp[index--])
						{
							//if yess increase count by 1 
							count++;
						}
						//if not
						else
						{
							//assign 0 to count
							count=0;
							//and break from loop
							break;
						}
					}
					//checking if count>0
					if(count)
					{
						//checking if index i.e length of string temp is greater than check
						if(index>check)
						{
							//if yess
							//assign temp to temp3
							temp3=temp;
							//assign value of index to check
							check=index;
						}
					}
					//checking if j>1
					if(j>1)
					{
						//move it to jth position of string temp
						it=temp.begin()+j;
						//remove jth character from temp
  						temp.erase (it);
					}
					//dec j by 1
					j--;
				}
				//move iterator it to 1st char of temp2
				it=temp2.begin();
				//remove 1st char of temp
  				temp2.erase (it);
			}
			//printing out largest palindrome found in string
			cout<<"largest palindrome: "<<temp3<<endl;
			//opening file in output mode
			ofstream out("output2.txt");
			//inputing temp3 i.e palindrome found largest to file
			out<<temp3;
			//closing file
			out.close();
		}
		//function to convert ints to string
		//and form a concatinated string
		void num_to_string()
		{
			int temp,count=0;
			string s;
			//creating str1 of stringstream type
			ostringstream str1; 
			node *current=new node();
			current=head;
			//loop to treverse all nodes of linked list
			while(current!=NULL)
			{
				//assigning data of current node to str1
				str1<<current->num;
				//moving current pointer to next
				current=current->next;
			}
			//copying or assigning str1 value to string str
			string str=str1.str();
			//printing type casted string
			cout<<"type-casted string"<<endl<<str<<endl;
			//calling function to find palindrome and sending str as a parameter
			find_palindrome(str);
		}
		//function to display contents of linked list node by node
		void display()
		{
			node *current=new node();
			current=head;
			while(current!=NULL)
			{
				cout<<current->num;
				if(current->next!=NULL)
				{
					cout<<"->";
				}
				current=current->next;
			}
			cout<<endl; 
		}
};
//main function
int main()
{
	//object of class
	palindrome p;
	//calling input function
	p.input();
	cout<<"linked list"<<endl;
	//calling display function
	p.display();
	//calling function to create type casted string
	p.num_to_string();
}
