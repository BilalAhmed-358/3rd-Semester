/* Write a C++ program to rearrange a given sorted array of positive integers . Note: In the final array, first element should be maximum value, second minimum value, third second maximum value , fourth second minimum value, fifth third maximum and so on.*/

#include <iostream>
using namespace std;

int main()
{
    int n = 0, temp = 0, result = 1;
    cout << "How many numbers do you want in the array?\n";
    cin >> n;
    int array[n], array2[n] = {0},highend=n-1,lowend=0;
    cout << "Enter the values in the array\n";
    for (int i = 0; i < n; i++)
        cin >> array[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    cout << "The array you have entered is as follows\n";
    for (int i = 0; i < n; i++)
        cout << array[i] << " ";
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            array2[i] = array[highend--];
            cout << "condition 1 ran\n";
            cout<<array2[i]<<endl;
        }
        if(i % 2 != 0)
        {
            array2[i] = array[lowend++];
            cout << "condition 2 ran\n";
            cout<<array2[i]<<endl;

        }
    }
    cout << "The array such that first element is the maximum value, second minimum value, third second maximum value , fourth second minimum value, fifth third maximum and so on\n";
    for (int i = 0; i < n; i++)
        cout << array2[i] << " ";
}
