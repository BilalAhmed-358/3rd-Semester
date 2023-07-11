#include<iostream>
using namespace std;
void sort(int arr[],int n)
{
	int temp,gap,j;
	for(gap=n/2;gap>0;gap/=2)
	{
		for(int i=gap;i<n;i++)
		{
			temp=arr[i];
			for(j=i;j>=gap && arr[j-gap]>temp;j-=gap)
			{
				arr[j]=arr[j-gap];
			}
			arr[j]=temp;
		}
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
