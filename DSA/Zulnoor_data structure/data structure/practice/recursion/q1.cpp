#include<iostream>
#include<cmath>
using namespace std;
signed int multiply(signed int a,signed int b,signed int prod)
{
	if(b==0)
	{
		if(a<0)
		{
			return abs(prod);
		}
		else
			return prod;
	}
	else
	{
		if(a>0&&b>0)
		{
			prod+=a;
			multiply(a,b-1,prod);
		}
		else if(a>0&&b<0)
		{
			prod-=a;
			multiply(a,b+1,prod);
		}
		else if(a<0&&b>0)
		{
			prod+=a;
			multiply(a,b-1,prod);
		}
		else if(a<0&&b<0)
		{
			a*=-1;
			prod-=a;
			multiply(a,b+1,prod);
		}		
	}
}
int main()
{
	signed int a,b,prod;
	cout<<"enter number a and b: "<<endl;
	cin>>a>>b;
	prod=multiply(a,b,0);
	cout<<"product of "<<a<<" and "<<b<<" is "<<prod<<endl;
}
