#include<iostream>
using namespace std;
void insert(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
}
void print(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
void sort(int arr[],int n)
{
	int i,j,k;
	for(int i=1;i<n;i++)
	{
		k=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>k)
		{
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=k;
	}
}
int main()
{
	int n;
	cout<<"enter number of elements: ";
	cin>>n;
	int a[n];
	cout<<"enter "<<n<<" elements in array: "<<endl;
	insert(a,n);
	sort(a,n);
	cout<<"elements of array after sorting"<<endl;
	print(a,n);
}
