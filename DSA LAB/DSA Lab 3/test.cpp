#include <iostream>
using namespace std;

float indices(int num, int power);

int main()
{
    int num = 0, power = 0;
    cout << "Enter the number\n";
    cin >> num;
    cout << "Enter the power\n";
    cin >> power;
    cout << "The value of " << num << " raised to the power of " << power << "  is " << indices(num, power) << endl;
}
float indices(int num, int power)
{
    if (power==0)
    {
        return 1;
    }
    else
    {
        return num*indices(num,power-1);
    }
    
    
}