#include <iostream>
#include <string.h>
using namespace std;
bool IsSafe(int **arr, int x, int y, int n1)
{
	if (x < n1 && y < n1 && arr[x][y] == 1)
		return true;

	return false;
}
bool RatInMaze(int **arr, int x, int y, int n1, int n2, int **SolArr)
{
	if (x == n1 - 1 && y == n1 - 1)
	{
		SolArr[x][y] = 1;
		return true;
	}
	if (IsSafe(arr, x, y, n1))
	{
		SolArr[x][y] = 1;
		if (RatInMaze(arr, x + 1, y, n1, n2, SolArr))
		{
			return true;
		}
		if (RatInMaze(arr, x, y + 1, n1, n2, SolArr))
		{
			return true;
		}
		SolArr[x][y] = 0;
		return false;
	}
	return false;
}
int main()
{
	int col, row;
	cout << "Enter Number of rows: ";
	cin >> row;
	cout << "Enter Number of Column: ";
	cin >> col;
	int **arr = new int *[row];
	for (int i = 0; i < row; i++)
		arr[i] = new int[col];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> arr[i][j];

	int **SolArr = new int *[row];
	for (int i = 0; i < row; i++)
	{
		SolArr[i] = new int[col];
		for (int j = 0; j < col; j++)
			SolArr[i][j] = 0;
	}

	if (RatInMaze(arr, 0, 0, row, col, SolArr) == true)
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cout << SolArr[i][j] << " ";
			}
			cout << endl;
		}
	else
		cout << "No Possible way out of the maze!\n";
}
