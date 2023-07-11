#include <iostream>
using namespace std;
void Insert_sort(int array[], int n);
int main()
{
    int n;
    cout << "Enter the number of values you want in the array\n";
    cin >> n;
    int *array= new int [n];
    cout << "Enter the values in the array below" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    Insert_sort(array, n);
    cout << "The array after running the insertion sort alogrithm becomes\n";
    for (int i = 0; i < n; i++)
    {
        cout << array[i]<<" ";
    }
}
void Insert_sort(int array[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp;
        temp = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > temp)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
}
