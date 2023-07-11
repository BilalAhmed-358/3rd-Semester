#include <iostream>
#include <fstream>
using namespace std;

int main()
{
//	int sum=0;
	int a,b;
	ifstream file;
	ifstream file2;
	file.open("sum.txt");
	file2.open("f2.txt");
	file2.close();
	file.close();
	
	return 0;
}
