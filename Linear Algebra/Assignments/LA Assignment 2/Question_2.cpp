#include <iostream>
using namespace std;

int main()
{   
    int array[3][3] = {{1, 1, 2}, {-1, -2, 3}, {3, -7, 4}};
    cout << "The values of the co-efficent matrix is\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << array[i][j] << "   ";
        }
        cout<<endl;
    }
}