#include<iostream>
using namespace std;
void InsertionSort(int arr[],int size)
{
	for(int i=1;i<size;i++)
	{
		int temp;
		temp=arr[i];
		int j=i-1;
		while(j>=0 && arr[j]>temp)
		{
			arr[j+1]=arr[j];
			j--;
		}
		cout<<"the val of j:"<<j<<endl;
		arr[j+1]=temp;
	}
}
int main()
{
	int size;
	cout<<"Enter size of array : ";
	cin>>size;
	int arr[size];
	cout<<"Enter array : "<<endl;
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
	}
	InsertionSort(arr,size);
	cout<<"Array now : "<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<arr[i];
	}
}

