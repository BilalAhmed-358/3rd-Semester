#include <iostream>
using namespace std;

void function(int x)
{
    static int count = 0, num = 1;
    if (count < x)
    {
        cout << num << " ";
        num = num + count;
        count++;
        function(x);
    }
}
int main()
{
    int x = 0;
    cout << "Enter the number of times you want to execute the sequence.\n";
    cin >> x;
    function(x);
}