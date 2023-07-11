#include <iostream>
using namespace std;
void printArray2(int array[][9]);
void Array2filler(int array[][9]);
void ArrayCopier(int array1[][8], int array2[][9]);
int main()
{
    int array1[8][8] = {0}, array2[9][9] = {0};

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> array1[i][j];
        }
    }

    // cout << "\nThe array2 is as follows.\n";
    // printArray2(array2);
    ArrayCopier(array1,array2);
    Array2filler(array2);
    // cout<<endl;
    printArray2(array2);
}
void ArrayCopier(int array1[][8], int array2[][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (j == 8 || i == 8)
            {
                array2[i][j] = 0;
            }
            else
                array2[i][j] = array1[i][j];
        }
    }
}
void printArray2(int array[][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}
void Array2filler(int array[][9])
{
    int sum = 0;
    for (int i = 0; i < 8; i++)
    {
        sum = 0;
        for (int j = 0; j < 8; j++)
        {
            sum += array[i][j];
        }
        array[i][8] = 45 - sum;
    }
    for (int i = 0; i < 9; i++)
    {
        sum = 0;
        for (int j = 0; j < 8; j++)
        {
            sum += array[j][i];
        }
        array[8][i] = 45 - sum;
    }
}