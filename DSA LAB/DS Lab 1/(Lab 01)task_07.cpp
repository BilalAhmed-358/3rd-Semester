#include <iostream>
using namespace std;

class Numbers
{
private:
    int *size_ptr;

public:
    void Assign_value(int num)
    {
        size_ptr = new int;
        *this->size_ptr = num;
    }

    void Display_size()
    {
        cout << "The value of size is " << *size_ptr << ".\n";
    }
    Numbers() {}
    Numbers(int num)
    {
        size_ptr = new int;
        *this->size_ptr = num;
    }
    ~Numbers()
    {
        delete size_ptr;
    }
};

int main()
{
    Numbers Num1(9);
    Num1.Display_size();
    Numbers Num2(Num1);
    Num2.Display_size();
    Num1.Assign_value(20);
    Num1.Display_size();    
    Num2.Display_size();    
}