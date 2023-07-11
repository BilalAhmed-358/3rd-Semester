#include<iostream>
using namespace std;
int dup(int arr[],int i,int j,int c)
{
	if(i>j)
	{
		return c;
	}
	else
	{
		for(int k=i+1;k<j;k++)
		{
			if(arr[i]==0)
			{
				continue;
			}
			if(arr[i]==arr[k])
			{
				c+=1;
				arr[k]=0;
			}
		}
		dup(arr,i+1,j,c);
	}
}
int main()
{
	int n,c;
	cout<<"enter number of elements: ";
	cin>>n;
	int arr[n];
	cout<<"enter elements in array: "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	c=dup(arr,0,n,0);
	cout<<"number of duplicates number in array are "<<c;
}
