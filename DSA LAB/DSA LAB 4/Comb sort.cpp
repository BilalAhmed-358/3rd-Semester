#include<iostream>
using namespace std;
int getgap(int gap)
{
	gap/=1.3;
	if(gap<1)
	{
		return 1;
	}
	return gap;
}
void CombSort(int arr[],int size)
{
	bool flag=true;
	int gap=size;
	
	while(gap!=1 && flag==true)
	{
		gap=getgap(gap);
		flag=false;
		
		for(int i=0;i<size-gap;i++)
		{
			if(arr[i]>arr[i+gap])
			{
				swap(arr[i],arr[i+gap]);
				flag=true;
			}
		}
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
	CombSort(arr,size);
	cout<<"Array now : "<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
	
}
