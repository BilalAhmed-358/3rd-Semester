#include <iostream>
using namespace std;
int main()
{
	char phone[11];
	cout<<"enter phone number in alpha-numeric: "<<endl;
	for(int i=0;i<11;i++)
	{
		cin>>phone[i];
	}
	cout<<endl;
	for(int i=0;i<11;i++)
	{
		switch(phone[i])
		{
			case 'A':
			case 'B':
			case 'C':
				phone[i]='2';
				break;
			case 'D':
			case 'E':
			case 'F':
				phone[i]='3';
				break;
			case 'G':
			case 'H':
			case 'I':
				phone[i]='4';
				break;
			case 'J':
			case 'K':
			case 'L':
				phone[i]='5';
				break;
			case 'M':
			case 'N':
			case 'O':
				phone[i]='6';
				break;
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
				phone[i]='7';
				break;
			case 'V':	
			case 'T':
			case 'U':
				phone[i]='8';
				break;			
			case 'Y':
			case 'W':
			case 'X':
				phone[i]='9';
				break;	
			case '-':
				continue;
				break;
		}
		cout<<phone[i];
	}
}
