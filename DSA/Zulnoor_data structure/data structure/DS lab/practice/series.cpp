#include<iostream>
using namespace std;
void series(int i,int j,char s)
{
	if(i>j)
	{
		return;
	}
	if(i==1)
	{
		cout<<"1"<<s;
	}
	else
	{
		cout<<"1/"<<i<<s;
	}
	if(i%2==0)
	{
		series(i+1,j,'+');
	}
	else if(i%2!=0)
	{
		series(i+1,j,'-');
	}
}
int main()
{
	series(1,7,'+');
}
