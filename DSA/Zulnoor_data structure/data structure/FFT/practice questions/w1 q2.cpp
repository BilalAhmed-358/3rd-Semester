#include <iostream>

using namespace std;

int main()
{
	int n;
	cout<<"enter size of main array: ";
	cin>>n;
	int a[n];
	cout<<"enter numbers in array: "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int k;
	cout<<"enter size of window array: ";
	cin>>k;
	int b[k];
	int c[n-2];
	for(int i=0;i<n-2;i++)
	{
		int max=0;
		int co=0;
		for(int j=i;j<i+k;j++)
		{
			b[co]=a[j];
			co++;
		}
		for(int j=0;j<k;j++)
		{
			if(b[j]>max)
			{
				max=b[j];
			}
		}
		c[i]=max;
	}
	for(int i=0;i<n-2;i++)
	{
		cout<<c[i]<<" ";
	}
}

