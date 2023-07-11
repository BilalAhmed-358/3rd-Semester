#include <iostream>
using namespace std;

void Array_sorting(int array[], int n);

int main()
{
    int n;
    cout << "Enter the number of elements you want in the array \n";
    cin >> n;
    cout << "Enter the values of the array\n";
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    cout << "The values of the array are as follows\n";
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    Array_sorting(array, n);
    cout << "\nAfter sorting the array becomes\n";
    // cout<<"The values of the array are as follows\n";
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
}

void Array_sorting(int array[], int n)
{  
    int static i = 0;
    int temp = 0;
    if (i < n)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (array[i] > array[j])
            {
                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
        i++;
    }
    if(i<n)
    Array_sorting(array, n);
}