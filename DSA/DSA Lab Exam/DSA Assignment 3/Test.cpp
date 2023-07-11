#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int main()
{
    string sent="machine a";
    string sentFing;
    getline(cin,sentFing);
    int check=sentFing.find(sent);
    if(check != string :: npos)
    {
        cout<<"Sent Found\n";
    }
}