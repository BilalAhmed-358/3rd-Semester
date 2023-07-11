#include<iostream>
using namespace std; 
bool IsSafe(int arr**, int x, int y, int n)
{
    for (int row = 0; row < x; row++)
    {
        if (arr[row][y]==1)
        {
            return false;
        }
        
    }
    
}