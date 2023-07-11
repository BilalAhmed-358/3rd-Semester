#include <iostream>
using namespace std;
void BubbleSort(int array[], int n);
int main()
{
    int n, *array;
    cout << "Enter the size of the array you want\n";
    cin >> n;
    array = new int[n];
    cout << "Enter the values in the array\n";
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    BubbleSort(array, n);
    cout << "The values of the array are as follows\n";
    for (int i = 0; i < n; i++)
    {
        cout << *(array + i) << " ";
    }
}
void BubbleSort(int array[], int n)
{
    int temp,count=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            temp = 0;
            if (array[i] > array[j])
            {
                temp = array[i];
                array[i]=array[j];
                array[j]=temp;
                count++;
            }
        }
    }
    cout<<endl<<count<<endl;
}
