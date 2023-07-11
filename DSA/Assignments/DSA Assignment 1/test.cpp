#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string *s1 = new string[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter string number " << i + 1 << endl;
        fflush(stdin);
        getline(cin, s1[i]);
        fflush(stdin);
    }
    for (int i = 0; i < n; i++)
    {   int string_len=s1[i].size();
        cout<<"Size of the string is "<<string_len<<endl;
        for (int j = 0; s1[i][j] != '\0'; j++)
        {
            cout << s1[i][j] << ".";
        }
        cout << endl;
    }
}