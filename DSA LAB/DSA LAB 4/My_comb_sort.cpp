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
void Comb_Sort(int array[],int n)
{
	bool flag=true;
	int gap=n;
	
	while(gap!=1 && flag==true)
	{
		gap=getgap(gap);
		flag=false;
		
		for(int i=0;i<n-gap;i++)
		{
			if(array[i]>array[i+gap])
			{
				swap(array[i],array[i+gap]);
				flag=true;
			}
		}
	}
}
int main()
{
	int n;
	cout<<"Enter the size of the array you want\n";
	cin>>n;
	int *array=new int [n];
	cout<<"Enter the values in the array below"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>array[i];
	}
	Comb_Sort(array,n);
	cout<<"The Array After sorting becomes\n"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<array[i]<<" ";
	}
	
}
