#include <iostream>
#include<iomanip>
using namespace std;

int main()
{
    string names[5] = {"Ali", "Hiba", "Asma", "Zain", "Faisal"};
    int size[5];
    float **array = new float *[5];
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter the number of subjects for " << names[i] << ".\n";
        cin >> size[i];
        array[i] = new float[size[i]];
    }
    cout << "\nEnter the values of GPA's of students.\n";
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter the GPA values of " << names[i] << "." << endl;
        for (int j = 0; j < size[i]; j++)
        {
            cout << "Enter the GPA of sub number " << j + 1 << " for " << names[i] << ".\n";
            cin >> *(*(array + i) + j);
        }
    }

    for (int i = 0; i < 5; i++)
    {
        float sum = 0;
        for (int j = 0; j < size[i]; j++)
        {
            sum += *(*(array + i) + j);
        }
        cout << "The CGPA of " << names[i] << " is " <<setprecision(3)<< sum / size[i] << ".\n";
    }
    for (int i = 0; i < 5; i++)
    {
        delete array[i];
    }
    delete [] array;
    
}