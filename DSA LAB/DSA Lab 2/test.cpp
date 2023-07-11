#include <iostream>

using namespace std;

int main()
{
     bool arr[2][2];
     for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
        {
            cin>>arr[i][j];
        }
        
     }
     cout<<"\n Below are the values \n";
     for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
        {   if(arr[i][j]==0)
            cout<<arr[i][j];
        }
        
     }

     return 0;
}