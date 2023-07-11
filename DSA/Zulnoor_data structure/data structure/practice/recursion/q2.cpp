#include<iostream>
using namespace std;
void string_rev(string &str,int start,int size)
{
	if(start>=size)
	{
		return;
	}
	else
	{
		char temp;
		temp=str[start];
		str[start]=str[size];
		str[size]=temp;
		string_rev(str,start+1,size-1);
	}
}
int main()
{
	string s;
	getline(cin,s);
	string_rev(s,0,s.length()-1);
	cout<<s;
}
