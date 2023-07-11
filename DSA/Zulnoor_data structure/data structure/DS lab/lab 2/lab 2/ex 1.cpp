#include<iostream>
using namespace std;
int main()
{
int array[] = {1,2,3};
cout << array[0];
cout << endl;
// int* dArray = new int[] {1,2,3};
int* dArray = new int[3] {1,2,3};
cout << *dArray+1;
cout << endl;
cout << dArray[2];
delete[] dArray;
}

