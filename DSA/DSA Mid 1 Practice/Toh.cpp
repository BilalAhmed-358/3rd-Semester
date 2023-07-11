#include <iostream>
using namespace std;

void Tower_Of_Hanoi(int n, int A, int B, int C);

int main()
{
    Tower_Of_Hanoi(50, 1, 2, 3);
}
void Tower_Of_Hanoi(int n, int A, int B, int C)
{
    int static count = 0;
    if (n > 0)
    {
        count++;
        Tower_Of_Hanoi(n - 1, A, C, B);
        cout << "Moving " << n - 1 << " from " << A << " to " << C << endl;
        Tower_Of_Hanoi(n - 1, B, A, C);
    }
}