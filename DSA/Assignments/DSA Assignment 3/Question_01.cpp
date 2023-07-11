#include <iostream>

using namespace std;
int test(int matrix[][3])
{
    // checking for illegitemate result
    int count1 = 0, count2 = 0;
    int play1prob = 0, play2prob = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j] == 1)
            {
                count1++;
            }
            if (matrix[i][j] == 2)
            {
                count2++;
            }
        }
    }
    if ((count1 - count2) > 1)
    {
        return -1;
    }
    if ((count2 - count1) > 1)
    {
        return -1;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(matrix[i][j]==1 )
            play1prob++;
            if(matrix[i][j]==2 )
            play2prob++;
        }
        
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(matrix[j][i]==1 )
            play1prob++;
            if(matrix[j][i]==2)
            play2prob++;
        }
        
    }
    if(matrix[0][0]==1 || matrix[1][1]==1  ||matrix[2][2]==1 )
        play1prob++;
    // if(matrix[1][1]==1 && matrix[2][2]==1)
    //     play1prob++;
    // if(matrix[1][1]==1 && matrix[0][2]==1)
    //     play1prob++;
    if(matrix[1][1]==1 || matrix[2][0]==1 || matrix[0][2]==1)
        play1prob++;
    

    if(matrix[0][0]==2 || matrix[1][1]==2  ||matrix[2][2]==2 )
        play2prob++;
    // if(matrix[1][1]==1 && matrix[2][2]==1)
    //     play1prob++;
    // if(matrix[1][1]==1 && matrix[0][2]==1)
    //     play1prob++;
    if(matrix[1][1]==2 || matrix[2][0]==2|| matrix[0][2]==2)
        play2prob++;


    if (play1prob > play2prob)
        return 1;
    else if (play2prob > play1prob)
        return 2;
    else if (play1prob == play2prob)
        return 0;
}
int main()
{
    int matrix[3][3] = {};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << test(matrix);
    return 0;
}
