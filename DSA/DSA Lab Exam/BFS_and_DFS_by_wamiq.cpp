#include<iostream>
#include<queue>
using namespace std;

void BFS(int MATRIX[][7],int start,int n)	
{
	int visited[n]={0};
	queue<int> q;
	int i=start;
	cout<<i<<" ";
	visited[i]=1;
	q.push(i);
	while(!q.empty())
	{
		i=q.front();
		q.pop();
		for(int j=1;j<n;j++)
		{
	
			if(MATRIX[i][j]==1 && visited[j]==0)
			{
				cout<<j<<" ";
				visited[j]=1;
				q.push(j);
			}
		}
	}
	
	
}
void DFS(int MATRIX[][7],int start,int n)	
{
	static int visited[7]={0};
	if(visited[start]==0)
	{
		cout<<start<<" ";
		visited[start]=1;
		for(int j=1;j<n;j++)
		{
			if(MATRIX[start][j]==1 && visited[j]==0)
			{
				DFS(MATRIX,j,n);
			}
		}
	}
	
}
int main()
{
	int MATRIX[7][7]={{0,0,0,0,0,0,0},
	                  {0,0,1,1,0,0,0},
	                  {0,1,0,0,1,0,0},
	                  {0,1,0,0,1,0,0},
	                  {0,0,1,1,0,1,1},
					  {0,0,0,0,1,0,0},
					  {0,0,0,0,1,0,0}};

    BFS(MATRIX,1,7);
    cout<<endl;
    DFS(MATRIX,1,7);
}
