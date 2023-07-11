#include<bits/stdc++.h>
using namespace std;
void Create_Matrix(int **arr,int n,int m,int **matrix)
{
	for(int i=0;i<m+1;i++)
	{
		for(int j=0;j<m+1;j++)
		{
			matrix[i][j]=0;
		}
		
	}
	
	for(int i=0;i<n;i++)
	{
		
			matrix[arr[i][0]][arr[i][1]]=1;
			matrix[arr[i][1]][arr[i][0]]=1;
		
	}
}
void Print_Matrix(int n,int **matrix)
{
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<n+1;j++)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
		
	}
}
int main()
{
	cout<<"Enter the Adjacent Pair of vertices to draw the Matrix.."<<endl;
	cout<<"Enter the No of Edges the graph has.."<<endl;
	int n,m;
	cin>>n;
	int **arr=new int*[n];
	for(int i=0;i<n;i++)
	{
		arr[i]=new int[2];
	}
	
	cout<<"Enter End points of Edges"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<2;j++)
		{
			cin>>arr[i][j];
	    }
		cout<<endl;
	}
	cout<<"How many vertices your Graph has..."<<endl;
	cin>>m;
	int **matrix=new int*[m+1];
	for(int i=0;i<m+1;i++)
	{
		matrix[i]=new int[m+1];
	}
	Create_Matrix(arr,n,m,matrix);
	Print_Matrix(m,matrix);

	
}
