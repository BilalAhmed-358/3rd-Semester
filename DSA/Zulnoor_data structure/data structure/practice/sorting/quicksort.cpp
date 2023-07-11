#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int arr[],int low,int high)
{
	int pivot =arr[high];
	int i=(low-1);
	for(int j=low;j<=high-1;j++)
	{
		if(arr[j]<pivot)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return (i+1);
}
void quicksort(int arr[],int low ,int high)
{
	if(low<high)
	{
		int p=partition(arr,low,high);
		quicksort(arr,p+1,high);
		quicksort(arr,low,p-1);
	}
}
void print(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
void insert(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
}
int main()
{
	int n=8;
	int a[n];
	cout<<"enter "<<n<<" elements in array: "<<endl;
	insert(a,n);
	quicksort(a,0,n-1);
	cout<<"elements of array after sorting"<<endl;
	print(a,n);
}
