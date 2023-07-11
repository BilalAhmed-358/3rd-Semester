#include <iostream>
#include <stack>
using namespace std;
class coins{
	public:
		int coin;
		stack<int>s1;
		stack<int>s2;
		stack<int>s3;
		stack<int>s4;
		int top1;
		int top2;
		void insert1(int d)
		{
			s1.push(d);
		}
		void insert2(int d)
		{
			s2.push(d);
		}
		void insert3(int d)
		{
			s3.push(d);
		}
		void merge(int n ,int m)
		{
			int x=-1,y=-1;
			
			if(!s1.empty())
			{
				x=s1.top();
				s1.pop();
				if(!s1.empty())
				{
					y=s1.top();
					s1.pop();
				}
				if(y==-1 && x!=-1)
				{
					insert3(x);	
					x=-1;
				}
				else if(x>y && y!=-1)
				{
					insert3(y);
					insert3(x);
					x=-1;
					y=-1;
				}
				else if(x<y && y!=-1)
				{
					insert3(x);
					insert3(y);
					x=-1;
					y=-1;
				}
			}
			if(!s2.empty())
			{
				x=s2.top();
				s2.pop();
				if(!s2.empty())
				{
					y=s2.top();
					s2.pop();
				}
				if(y==-1 && x!=-1)
				{
					insert3(x);
					x=-1;
				}
				else if(x>y && y!=-1)
				{
					insert3(y);
					insert3(x);
					x=-1;
					y=-1;
				}
				else if(x<y && y!=-1)
				{
					insert3(x);
					insert3(y);
					x=-1;
					y=-1;
				}
			}
			cout<<endl;
			if(s1.empty()&&s2.empty())
			{
				reverse(n+m);
				exit(0);
			}	
			else	
				merge(n,m);
		}
		void reverse(int x)
		{
			for(int i=0;i<x;i++)
			{
				int a=s3.top();
				s4.push(a);
				s3.pop();
			}
			print3(x);	
		}
		void print3(int x)
		{
			cout<<"stack3"<<endl;
			for(int i=0;i<x;i++)
			{
				cout<<s4.top()<<" ";
				s4.pop();
			}
		}
};

int main()
{
	coins c;
	int n,m;
	int x;
	cout<<"enter size of stack1: ";
	cin>>n;
	cout<<"enter size of stack2: ";
	cin>>m;
	cout<<"enter elements in stack1"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		c.insert1(x);
	}
	cout<<"enter elements in stack2"<<endl;
	for(int i=0;i<m;i++)
	{
		cin>>x;
		c.insert2(x);
	}
	cout<<endl;

	c.merge(n,m);
}
