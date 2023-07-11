#include<iostream>
#include<string>
#include<stack>

using namespace std;

class palindrome
{
	public:
		string str;
		void input()
		{
			cout<<"enter string"<<endl;
			getline(cin,str);
		}
		void is_palindrome()
		{
			stack<char>s1;
			stack<char>s2;
			int len=str.length();
			int flag=0;
			for(int i=0;i<len/2;i++)
			{
				s1.push(str[i]);
			}
			for(int i=len/2;i<len;i++)
			{
				s2.push(str[i]);
			}
			stack<char>s3;
			for(int i=len/2;i<len;i++)
			{
				char x=s2.top();
				s3.push(x);
				s2.pop();
			}
			if(len%2!=0)
				s3.pop();
				
			for(int i=0;i<len/2;i++)
			{
				char x=s1.top();
				char y=s3.top();
				cout<<x<<" "<<y<<endl;
				if(x!=y)
				{
					flag++;
					break;
				}
				s1.pop();
				s3.pop();	
			}
			if(!flag)
				cout<<str<<" is a palindrome"<<endl;
			else
				cout<<str<<" is not a palindrome"<<endl;	
		}
};
int main()
{
	palindrome p;
	p.input();
	p.is_palindrome();
}
