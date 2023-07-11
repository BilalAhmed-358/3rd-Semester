#include <iostream>
using namespace std;
void num_printer(int num, int x);
void function(int x)
{
    static int count = 0, num = 1;
    if (count < x)
    {
        if (count == 0)
        {

            cout << num << " ";
        }

        num = num + count;
        count++;
        num_printer(num, x);
    }
}
void num_printer(int num, int x)
{
    cout << num << " ";
    function(x);
}
int main()
{
    int x = 0;
    cout << "Enter the number of times you want to execute the sequence.\n";
    cin >> x;
    function(x);
}