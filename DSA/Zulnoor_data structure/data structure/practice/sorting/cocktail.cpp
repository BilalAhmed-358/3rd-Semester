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
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void sort(int arr[],int n)
{
	bool swapped = true;
	int start=0;
	int end=n-1;
	while(swapped)
	{
		for(int i=start;i<end;i++)
		{
			if(arr[i]>arr[i+1])
			{
				swap(&arr[i],&arr[i+1]);
				swapped=true;
			}
		}
		if(!swapped)
		{
			break;
		}
		swapped = false;
		end--;
		for(int i=end-1;i>=start;i--)
		{
			if(arr[i]>arr[i+1])
			{
				swap(&arr[i],&arr[i+1]);
				swapped=true;
			}
		}
		start++;
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
