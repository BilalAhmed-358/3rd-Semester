#include<iostream>
using namespace std;
void addition(int b)
{
	cout<<endl<<"The Sum of the numbers are : ";
	cout<<b;
}
int main()
{
	int a;
	cout<<"how many numbers do you want: ";
	cin>>a;
	int sum=0;
	for(int i=0;i<=a;i++)
	{
		cin>>i;
		sum+=i;
	}
	addition(sum);
}
