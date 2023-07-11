#include<iostream>
#include<stack>
using namespace std;
class conversion
{
	public:
		stack <int>s;
		void convert(int n,int b)
		{
			while(n!=0)
			{
				s.push(n%b);
				n/=b;
			}
		}
		
		void display()
		{
			while(!s.empty())
			{
				int x=s.top();
				switch(x)
				{
					case 10:
						cout<<"A";
						break;
					case 11:
						cout<<"B";
						break;
					case 12:
						cout<<"C";
						break;
					case 13:
						cout<<"D";
						break;
					case 14:
						cout<<"E";
						break;
					case 15:
						cout<<"F";
						break;
					default:
						cout<<x;
						break;						
				}
				s.pop();
			}
		}
};


int main()
{
	conversion c;
	int num;
	int base;
	cout<<"enter a number"<<endl;
	cin>>num;
	cout<<"enter base"<<endl;
	cin>>base;
	c.convert(num,base);
	c.display();
}
