#include<iostream>
#include "DSA.h"
#include "OSDA.h"
#include "USDA.h"
using namespace std;

int main()
{
	int a,arr[],b,brr[];
	cin>>a;
	ODSA d1(a);
	cout<<"enter ordered aray:"<<endl;
	for(int i=0;i<a;i++)
	{
		cin>>arr[i];
	}
	d1.insertion(arr[]);
	d1.searching(5);
	cin>>b;
	UDSA d2(b);
	cout<<"enter unordered aray:"<<endl;
	for(int i=0;i<a;i++)
	{
		cin>>brr[i];
	}
	d2.insertion(arr[]);
	d2.searching(9);
	
}
