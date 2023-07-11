#include<iostream>
using namespace std;
int getmax(int arr[],int n)
{
	int max=arr[0];
	for(int i=0;i<n;i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
		}
	}
	return max;
}
void countsort(int arr[],int n,int exp)
{
	int output[n];
	int count[10]={0};
	for(int i=0;i<n;i++)
	{
		count[(arr[i]/exp)%10]++;
	}
	for(int i=1;i<10;i++)
	{
		count[i]+=count[i-1];
	}
	for(int i=n-1;i>=0;i--)
	{
		output[count[ (arr[i]/exp)%10] -1]=arr[i];
		count[(arr[i]/exp)%10]--;
	}
	for(int i=0;i<n;i++)
	{
		arr[i]=output[i];
	}
}
void radixsort(int arr[],int n)
{
	int m=getmax(arr,n);
	for(int exp=1;m/exp>0;exp*=10)
	{
		countsort(arr,n,exp);
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
	radixsort(a,n);
	cout<<"elements of array after sorting"<<endl;
	print(a,n);
}
