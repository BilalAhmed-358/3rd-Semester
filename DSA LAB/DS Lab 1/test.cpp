#include<iostream>
using namespace std;

int main()
{
    int array[5]={5,4,3,2,1};
    for (int i = 0; i < 5; i++)
    {
        for (int j = i+1; j < 5; j++)
        {
            if (array[i]>array[j])
            {
                int temp;
                temp=array[j];
                array[j]=array[i];
                array[i]=temp;
            }
        }
        
    }
    for (int i = 0; i < 5; i++)
    {
        cout<<array[i]<<endl;
    }
    
}