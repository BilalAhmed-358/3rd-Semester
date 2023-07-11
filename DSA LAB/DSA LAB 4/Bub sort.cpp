#include<iostream>
using namespace std;
void BubbleSort(int arr[],int size)
{
	bool flag;int count=0;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(arr[j],arr[j+1]);
				flag=true;
				count++; 
				
			}
        
		}
		if(flag==false)
			{
				
				cout<<"Already Sorted :"<<endl;
				break;
			}
	}
	cout<<count<<endl;
	cout<<"Array now : "<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<arr[i];
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
	BubbleSort(arr,size);
}

