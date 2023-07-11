#include<iostream>
using namespace std;

int main()
{
    int array[10],temp;
    cout<<"Enter the values in the array\n";
    for(int i=0;i<10;i++)
    {
        cin>>array[i];
    }
    cout<<"\nElements sorted in ascending order\n";
    for(int i=0;i<10;i++)
    {
        for(int j=i+1;j<10;j++)
        {
            if(array[i]>array[j])
            {
                temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }

    for(int i=0;i<10;i++)
    cout<<array[i]<<"  ";

    cout<<"\nElements sorted in descending order\n";
    for(int i=0;i<10;i++)
    {
        for(int j=i+1;j<10;j++)
        {
            if(array[i]<array[j])
            {
                temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
    for(int i=0;i<10;i++)
    cout<<array[i]<<"  ";
}