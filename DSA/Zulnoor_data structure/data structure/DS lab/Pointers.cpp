#include<iostream>
using namespace std;
int main()
{
	int a,b;	
	cout<<"Enter a : ";
	cin>>a;
	cout<<"Enter b : ";
	cin>>b;
	int *p,*p2;

	
	p=&a;
	p2=&b;
	
	if(p<p2)
	{
		cout<<"b is highest : "<<*p2;
	}
	else
	cout<<"a is highest : "<<*p;
}
