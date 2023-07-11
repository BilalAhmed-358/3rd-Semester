#include <iostream>
#include <string.h>
using namespace std;
void PrintArray(int** arr);
bool isSafe(int** arr, int x, int y, int n) {
    for(int row = 0; row < x; row++) {
        if(arr[row][y] == 1) {
            return false;
        }
    }

    int row=x;
    int col=y; 
    while(row >= 0 && col >= 0) {
        if(arr[row][col] == 1) {
            return false;
        }
        row--;
        col--;
    }

    row=x;
    col=y; 
    while(row >= 0 && col < n) {
        if(arr[row][col] == 1) {
            return false;
        }
        row--;
        col++;
    }
    return true;
}


bool nQueen(int** arr, int x, int n) {
    if(x == n) 
    {cout<<"BINGO!\n";
    return true;}

    for(int col = 0; col < n; col++) {
        cout<<"("<<x<<","<<col<<")\n";
        if(isSafe(arr, x, col, n)) {
            arr[x][col] = 1;
            if(nQueen(arr, x+1, n)) return true;
			arr[x][col] = 0; // Back track
            cout<<endl;
        }
    }
    return false;
}
int main() {
    int n;
    cout << "Enter size of Array: ";
    cin >> n;
    int** arr;
    arr = new int*[n];

    for(int i = 0; i < n; i++) {
        arr[i] = new int[n];
        for(int j = 0; j < n; j++) arr[i][j]=0;
    }
//	memset(arr, 0, sizeof(arr));
//	system("Color 0A");
    if(nQueen(arr, 0, n)) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    cout<<"No possible way out!\n";

    return 0;
}

