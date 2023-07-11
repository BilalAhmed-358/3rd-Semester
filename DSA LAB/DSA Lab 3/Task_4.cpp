#include <iostream>
using namespace std;
 
int fun(int n)
{
    if (n > 100)
        return n - 10;
 
    // A recursive function passing parameter
    // as a recursive call or recursion inside
    // the recursion
    return fun(fun(n + 11));
}
int main()
{
    int r;
    r = fun(95);
   
    cout << " " << r;
   
    return 0;
}
