#include<iostream>
#include <fstream>
using namespace std;
class node{
	node *next;
	public:
		char sign='-';
		signed int cons;
		char var;
		int pow;
		node():next(0){
		}
		friend class polynomial;
};
class polynomial{
	
	public:
		node *head;
		int size=0;
		polynomial():head(0){
		}
		void insert_at_head(char s,signed int c,char v,int p)
		{
			node *temp=new node();
			temp->sign=s;
			temp->cons=c;
			temp->var=v;
			temp->pow=p;
			if(temp->sign=='-')
			{
				temp->cons*=-1;
			}
			if(head)
			{
				temp->next=head;
				head=temp;
			}
			else
			{
				head=temp;
				temp->next=NULL;
			}
			size++;
		}
		void insert_at_tail(char s,signed int c,char v,int p)
		{
			node *temp=new node();
			node *current;
			current=head;
			temp->sign=s;
			temp->cons=c;
			temp->var=v;
			temp->pow=p;
			if(temp->sign=='-')
			{
				temp->cons*=-1;
			}
			if(!head)
			{
				insert_at_head(s,c,v,p);
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
		void insert_at(char s,signed int c,char v,int p,int node_num)
		{
			node *temp=new node();
			node *current=new node();
			current=head;
			temp->sign=s;
			temp->cons=c;
			temp->var=v;
			temp->pow=p;
			if(temp->sign=='-')
			{
				temp->cons*=-1;
			}
			int count=0;
			if(!head)
			{
				cout<<"no list found"<<endl;
				exit(1);
			}
			if(node_num>=1&&node_num<=size)
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
		void input(polynomial &p1,polynomial &p2)
		{
			ifstream inp("input1.txt");
			string str1,str2;
			string::iterator it;
			int p;
			signed int c;
			char v,s;
			getline(inp,str1);
			getline(inp,str2);
			inp.close();
			int len1=str1.length();
			int len2=str2.length();
			for(int i=0;i<2;i++)
			{
				it=str1.begin()+len1-1;
  				str1.erase (it);
  				len1--;
			}
			for(int i=0;i<2;i++)
			{
				it=str2.begin()+len2-1;
  				str2.erase (it);
  				len2--;
			}
			int i=len1-1;
			for(int j=0;j<len1/5;j++)
			{
				p=str1[i]-48;
				v=str1[i-2];
				if(str1[i-3]=='+'||str1[i-3]=='-')
				{
					c=1;
					s=str1[i-3];
					i-=4;
				}
				else
				{
					c=str1[i-3]-48;
				 	s=str1[i-4];
				 	i-=5;
				}
				p1.insert_at_head(s,c,v,p);
				
			}
			if(len1%5>0)
			{
					int i=0;
					if(str1[0]=='X'||str2[0]!='x')
					{
						c=1;
						v=str1[0];
						p=str1[2]-48;
					}
					else if(str1[0]!='X'||str1[0]!='x')
					{
						c=str1[0]-48;
						v=str1[1];
						p=str1[3]-48;
					}
					p1.insert_at_head('+',c,v,p);
			}
			 i=len2-1;
			for(int j=0;j<len2/5;j++)
			{
				p=str2[i]-48;
				v=str2[i-2];
				if(str2[i-3]=='+'||str2[i-3]=='-')
				{
					c=1;
					s=str2[i-3];
					i-=4;
				}
				else
				{
					c=str2[i-3]-48;
				 	s=str2[i-4];
				 	i-=5;
				}
				p2.insert_at_head(s,c,v,p);
				
			}
			if(len2%5>0)
			{
					int i=0;
					if(str2[0]=='X'||str2[0]=='x')
					{
						c=1;
						v=str2[0];
						p=str2[2]-48;
					}
					else if(str2[0]!='X'||str2[0]!='x')
					{
						c=str2[0]-48;
						v=str2[1];
						p=str2[3]-48;
					}
					p2.insert_at_head('+',c,v,p);
			}
		}
		void input_der(polynomial &p4)
		{
			ifstream inp("output1_1.txt");
			string str;
			string::iterator it;
			int p;
			signed int c;
			char v,s;
			getline(inp,str);
			inp.close();
			int len=str.length();
			for(int i=0;i<2;i++)
			{
				it=str.begin()+len-1;
  				str.erase (it);
  				len--;
			}
			int i=len-1;
			for(int j=0;j<len/5;j++)
			{
				p=str[i]-48;
				v=str[i-2];
				c=str[i-3]-48;
				s=str[i-4];
				p4.insert_at_head(s,c,v,p);
				i-=5;
			}
			if(len%5>0)
			{
					int i=0;
					if(str[0]=='X'||str[0]=='x')
					{
						c=1;
						v=str[0];
						p=str[2]-48;
					}
					else if(str[0]!='X'||str[0]!='x')
					{
						c=str[0]-48;
						v=str[1];
						p=str[3]-48;
					}
					p4.insert_at_head('+',c,v,p);
			}
		}
		void display()
		{
			node *current;
			current=head;
			signed int x;
			while(current!=NULL)
			{
				if(current->cons!=0)
				{
					if(current->sign=='-')
					{
						current->cons*=-1;
						cout<<current->sign<<current->cons<<current->var<<"^"<<current->pow;
						current->cons*=-1;
					}
					else if(current->sign=='+')
					{
						if(current==head)
						{
							goto L1;
						}
						cout<<current->sign;
					L1:
						cout<<current->cons<<current->var<<"^"<<current->pow;	
					}
						
				}	
				current=current->next;
			}
			cout<<"=0";
			cout<<endl;
		}
		void displaysum()
		{
			node *current;
			current=head;
			signed int x;
			while(current!=NULL)
			{
				if(current->cons!=0)
				{
					if(current==head && current->sign=='+')
					{
						goto L2;
					}
					else if(current!=head && current->sign=='+')
					cout<<current->sign;
				L2:	
					cout<<current->cons<<current->var<<"^"<<current->pow;	
				}
				current=current->next;
			}
			cout<<"=0";
			cout<<endl;	
		}
		void polysum(polynomial &l2,polynomial &l3)
		{
			node *current1,*current2;
			node *temp=new node();
			int count=0;
			int flag=0;
			for(current1=l2.head;current1!=NULL;current1=current1->next)
			{
				flag=0;
				for(current2=l3.head;current2!=NULL;current2=current2->next)
				{
					if(current1->pow==current2->pow)
					{
						flag++;
					}
				}
				if(!flag)
				{
					count=0;
					for(current2=l3.head;current2!=NULL;current2=current2->next)
					{
						if(current2->next->pow <  current1->pow)
						{
							temp->cons=current1->cons;
							temp->pow=current1->pow;
							temp->sign=current1->sign;
							temp->var=current1->var;
							l3.insert_at(temp->sign,temp->cons,temp->var,temp->pow,count);
							
							break;
						}
						count++;
					}
				}
			}
		}
		void sum_polynomial(polynomial &l1,polynomial &l2,polynomial &l3)
		{
			node *temp=new node();
			node *current1,*current2;
			int flag;
			for(current1=l1.head;current1!=NULL;current1=current1->next)
			{
				flag=0;
				for(current2=l2.head;current2!=NULL;current2=current2->next)
				{
					if(current1->pow==current2->pow)
					{
						temp->cons=current1->cons+current2->cons;
						if(temp->cons<0)
						{
							temp->cons*=-1;
							temp->sign='-';
						}
						else
						{
							temp->sign='+';
						}
						temp->pow=current1->pow;
						temp->var=current1->var;
						l3.insert_at_tail(temp->sign,temp->cons,temp->var,temp->pow);
						flag++;
						break;
					}
				}
				if(!flag)
				{
					temp->cons=current1->cons;
					temp->pow=current1->pow;
					temp->var=current1->var;
					if(current1->sign == '-')
					{
						temp->cons*=-1;
						l3.insert_at_tail('-',temp->cons,temp->var,temp->pow);
					}
					else
					{
						l3.insert_at_tail('+',temp->cons,temp->var,temp->pow);
					}
				}
			}
			polysum(l2,l3);
		}
		void derivative(polynomial &l4)
		{
			node *temp=new node();
			node *current;
			current=l4.head;
			while(current!=NULL)
			{
				current->cons=current->cons*current->pow;
				current->pow=current->pow-1;
				current=current->next;
			}
		}
		void output_file(polynomial &p,int i)
		{
			node *current;
			current=p.head;
			ofstream out;
			if(i==1)
			{
				out.open("output1_1.txt");
				if(current->cons!=0)
				{
					if(current->sign=='-')
					{
						out<<current->sign;
					}
					if(current->cons==1)
					{
						cout<<current->var<<"^"<<current->pow;
					}
					else
					{
						out<<current->cons<<current->var<<"^"<<current->pow;
					}
				}
				current = current->next;
				while(current!=NULL)
				{
					if(current->cons!=0)
					{
						if(current->sign=='+')
						{
							out<<current->sign;
						}
						if(current->cons==1)
						{
							cout<<current->var<<"^"<<current->pow;
						}
						else
						{
							out<<current->cons<<current->var<<"^"<<current->pow;
						}
					}
					current=current->next;
				}
				out<<"=0"<<endl;
				out.close();
			}
			else if(i==2)
			{
				out.open("output1_2.txt");
				if(current->cons!=0)
				{
					out<<current->cons<<current->var<<"^"<<current->pow;
				}
				current = current->next;
				while(current!=NULL)
				{
					if(current->cons!=0)
					{
						if(current->sign=='+')
						{
							out<<current->sign;
						}
						out<<current->cons<<current->var<<"^"<<current->pow;
					}
					current=current->next;
				}
				out<<"=0"<<endl;
				out.close();
			}
		}
};
int main()
{
	polynomial p1;
	polynomial p2;
	polynomial p3;
	polynomial p4;
	p1.input(p1,p2);
	cout<<"list 1:"<<endl;
	p1.display();
	cout<<endl<<"list 2:"<<endl;
	p2.display();
	cout<<endl;
	p1.sum_polynomial(p1,p2,p3);
	cout<<"list 3=list 1+list 2:"<<endl;
	p3.displaysum();
	p3.output_file(p3,1);
	cout<<endl<<"list 4:"<<endl;
	p3.input_der(p4);
	p4.display();
	p3.derivative(p4);
	cout<<endl<<"derivative of list 4"<<endl;
	p4.display();
	p4.output_file(p4,2);
}
