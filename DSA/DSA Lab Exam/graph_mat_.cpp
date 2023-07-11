#include <iostream>
using namespace std;
#define N 5
#define M 2
void createAdjMatrix(int Adj[][N+1], int arr[][M]){
	int i;
	for (i = 0; i < N + 1; i++) {
		int j;
		for (j = 0; j < N + 1; j++) {
			Adj[i][j] = 0;
		}
	}
	// Traverse the array of Edges
	for ( i = 0; i < N; i++) {
		// Find X and Y of Edges
		int x = arr[i][0];
		int y = arr[i][1];
		// Update value to 1
		Adj[x][y] = 1;
		Adj[y][x] = 1;
	}
}
void printAdjMatrix(int Adj[][N + 1])
{
int i;
	for (i = 1; i < N + 1; i++) {
		int j;
		for (j = 1; j < N + 1; j++) {
			cout<< Adj[i][j];
		}
		cout<<endl;
	}
}
int main()
{
	// Given Edges
	int arr[][2]= { { 1, 2 }, { 2, 3 },{ 4, 5 }, { 1, 5 } };
	// For Adjacency Matrix
	int Adj[N + 1][N + 1];
	// Function call to create
	// Adjacency Matrix
	createAdjMatrix(Adj, arr);
	// Print Adjacency Matrix
	printAdjMatrix(Adj);

	return 0;
}

