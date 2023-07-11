#include <iostream>

using namespace std;
int max_subarray(int array[], int n)
{
    int maxsum = -9999, currentsum = 0, start = 0, end = 0, begin = 0;
    for (int i = 0; i < n; i++)
    {
        currentsum = currentsum + array[i];
        if (currentsum < array[i])
        {
            currentsum = array[i];
            begin = i;
        }
        if (maxsum < currentsum)
        {
            maxsum = currentsum;
            end = i;
            start = begin;
        }
    }
    currentsum = 0;
    for (int i = start; i <= end; i++)
    {
        cout << array[i] << " ";
        // currentsum = currentsum + array[i];
    }
    cout << endl
         << maxsum;
}
int main()
{
    int n = 0;
    cin >> n;
    int *array = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    // cout << "The array is as follows\n";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << array[i];
    // }
    max_subarray(array, n);
}