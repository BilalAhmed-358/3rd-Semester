#include <iostream>
using namespace std;

void function(int x)
{
    static int num = 0, count = 1;
    if (num < x)
    {
        if ((num + count) < x)
        {
            cout << num + count <<endl;
        }
        num = num + count;
        count++;
        function(x);
    }
}
int main()
{
    int x = 0;
    cout << "Enter the number until which you want the sequence to execute.\n";
    cin >> x;
    function(x);
}