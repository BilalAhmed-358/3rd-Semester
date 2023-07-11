#include <iostream>
using namespace std;

void FriendChecker(int pupil1,int pupil2,bool Array[5][5])
{
    int count=0;
    for (int i = 0; i < 5; i++)
    {
        if(Array[pupil1][i]==1&&Array[pupil2][i]==1)
        {
            cout<<"Both Person number "<<pupil1<<" and "<<pupil2<<" are friends with "<<i<<" .\n";
            count++;
        }
        
    }
    if(count==0)
    cout<<"There are no common friends between the two,\n";
    
}
int main()
{
    bool Array[5][5];int pupil1=0,pupil2=0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << "Is person number " << i  << " friends with box number " << j << "?(Enter 1 or 0)\n";
            cin >> Array[i][j];
        }
    }
    cout<<"Enter the number of the first pupil you want to check\n";
    cin>>pupil1;
    cout<<"Enter the number of the second pupil you want to check\n";
    cin>>pupil2;
    FriendChecker(pupil1,pupil2,Array);
    // cout<<"Below is the data about who is friends with whom.\n";
    // for (int i = 0; i < 5; i++)
    // {
    //     for (int j = 0; j < 5; j++)
    //     {
    //         if(Array[i][j]==1)
    //         {
    //             cout<<"Person "<<i+1<<" is friends with number "<<j+1<<".\n";
    //         }
    //     }
        
    // }
    
}