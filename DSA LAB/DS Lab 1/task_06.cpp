#include <iostream>
using namespace std;

class Animals
{
public:
    string name;
    int age;
    Animals() {}
    Animals(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    void View_info()
    {
        cout << "\nThe name of the animal is " << this->name << " .\n";
        cout << "The age of the animal is " << this->age << " .\n";
    }

    void assign_info()
    {
        cout << "\nEnter the name of the animal.\n";
        getline(cin, this->name);
        cout << "Enter the age of the animal.\n";
        cin >> age;
    }
};
int main()
{
    Animals *Array;
    Array = new Animals[5];
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter the name of animal number " << i + 1 << ".\n";
        fflush(stdin);
        getline(cin, (Array + i)->name);
        cout << "Enter the age of animal number " << i + 1 << ".\n";
        cin >> (Array + i)->age;
    }
    for (int i = 0; i < 5; i++)
    {

        for (int j = i + 1; j < 5 ; j++)
        {
            Animals temp;
            if (((Array + i)->name[0]) > ((Array + j)->name[0]))
            {
                temp = *(Array + j);
                *(Array + j) = *(Array + i);
                *(Array + i) = temp;
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        (Array + i)->View_info();
    }
}