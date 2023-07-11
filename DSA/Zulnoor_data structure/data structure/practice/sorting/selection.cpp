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
void swap(int *a, int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void sort(int arr[],int n)
{
	int i,j,min;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i;j<n;j++)
		{
			if(arr[j]<arr[min])
			{
				min=j;
			}
			swap(&arr[min] , &arr[i]);
		}
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
