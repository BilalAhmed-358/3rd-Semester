#include<iostream>
using namespace std;

int main()
{
    int m,n;
    cout<<"Enter the number of rows you want in the matrix\n";
    cin>>m;
    cout<<"Enter the number of columns you want in the matrix\n";
    cin>>n;
    
    int matrix[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<"Enter the value for element number ["<<i+1<<"]["<<j+1<<"]\n";
            cin>>matrix[i][j];
        }
        
    }
    cout<<"The matrix you have entered is\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<matrix[i][j]<<"  ";
        }
        cout<<endl;
        
    }
    if(m==n)
    {
        cout<<"The matrix is a square matrix\n";
    int count=0,zero_count=0;
    for (int i = 0; i < m; i++)
    {   
        for (int j = 0; j < n; j++)
        {   
            if(i==j&& matrix[i][j]==1)
            {
                count++;
            }
            else
            {
                if(matrix[i][j]==0)
                zero_count++;
            }
        }
        
    }
    if(count==m&&zero_count==((m*n)-m))
    cout<<"The matrix is a identity matrix\n";
    }

    
}
