#include<iostream>
using namespace std;
void prime(int start,int end,int i)
{
	int c=0;
	if(start>end)
	{
		return;
	}
	else
	{	
		if(start<=2)
		{
			if(start==2)
			{
				cout<<start<<"--- prime"<<endl;
				c++;
			}
			else
			{
				cout<<start<<"--- not prime"<<endl;
				c++;
			}
		}
		else if(i*i>start)
		{
			cout<<start<<"--- prime"<<endl;
			c++;
		}
		else if((start%i)==0)
		{
			cout<<start<<"--- not prime"<<endl;
			c++;
		}
	}
	if(i>=start||c>0)
	{
		prime(start+1,end,2);
	}
	else 
		prime(start,end,i+1);
}
int main()
{
	int a,b;
	cout<<"enter range to find prime numbers within: "<<endl;
	cin>>a>>b;
	prime(a,b,2);\
}
