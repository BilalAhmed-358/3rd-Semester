#include<stdio.h>
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	int num;
	cout<<"Enter the number you want to find the factors of\n";
	cin>>num;
//	cout<<"The number you entered is "<<num;
	if(num<0)
	{
		cout<<"Sorry this program works for values on >=0.\n";
		exit(0);
	}
			int static sum_fac=0;
	for(int i=1;i<=num;i++)
	{
		if(num%i==0)
		{
			int static count =1;
			cout<<i<<" is the number "<<count<<" factor of the given number.\n";
			sum_fac+=i;
			count++;
		}
	}
	cout<<endl<<"The sum of all factors of the given number is "<< sum_fac<<".";
}