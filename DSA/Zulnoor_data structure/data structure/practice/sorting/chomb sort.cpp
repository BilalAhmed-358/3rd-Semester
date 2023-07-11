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
int nextgap(int k)
{
	k=(k*10)/13;
	if(k<1)
	{
		return 1;
	}
	return k;
}
void sort(int arr[],int n)
{
	int i,j,k;
	k=n;
	bool s=true;
	while(k!=1||s==true)
	{
		k=nextgap(k);
		s=false;
		for(int i=0;i<n-k;i++)
		{
			if(arr[i]>arr[i+k])
			{
				swap(&arr[i],&arr[i+k]);
				s=true;
			}
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
