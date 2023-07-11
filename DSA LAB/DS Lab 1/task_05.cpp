#include <iostream>
using namespace std;

int MinMax(int *array_ptr,int num);

int main()
{
    int num;
    cout << "How many elements do you want in the array?\n";
    cin >> num;
    int array[num];
    int *array_ptr = array;
    for (int i = 0; i < num; i++)
    {
        cout << "Enter the value of the number " << i + 1 << " element of the array.\n";
        cin >> array[i];
    }
    MinMax(array_ptr,num);
}

int MinMax(int *array_ptr,int num)
{
    int min=2147483647,max=0;
    for (int i = 0; i < num; i++)
    {
        if(*(array_ptr+i)>max)
        {
            max=*(array_ptr+i);
        }
    }
    cout<<"The max value of the array is "<<max<<".\n";
    for (int i = 0; i < num; i++)
    {
        if(*(array_ptr+i)<min)
        {
            min=*(array_ptr+i);
        }
    }
    cout<<"The min value of the array is "<<min<<".\n";


}