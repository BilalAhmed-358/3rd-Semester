#include <iostream>
using namespace std;
void Merge(int *array , int left, int mid, int right)
{
	int temp[right-left+1] , k=0 , i=left , j=mid+1 ;
	while(i<=mid && j<=right)
	{
		if(array[i]<array[j])
		{
			temp[k]=array[i];
			i++;
			k++;
		}
		else 
		{
			temp[k]=array[j];
			j++;
			k++;
		}
	}
	while(i<=mid)
	{
		temp[k]=array[i];
		i++;
		k++;
	}
	while(j<=right)
	{
		temp[k]=array[j];
		j++;
		k++;
	}
	for(i=left; i <=right ; i++)
	{
		array[i]=temp[i-left];
	}	
}
void MergeSort(int *array ,int left ,int right)
{
	if(right>left)
	{
		int mid = (left + right)/2;
		MergeSort(array,left,mid);
		MergeSort(array,mid+1,right);	
		Merge(array,left,mid,right);	
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
	int arr[8];
	insert(arr,n);
	cout<<"unsorted array"<<endl;
	print(arr,n);
	MergeSort(arr,0,n);
	cout<<endl<<"sorted array:"<<endl;
	print(arr,n);
}
