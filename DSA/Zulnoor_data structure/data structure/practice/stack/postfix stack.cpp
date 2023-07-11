#include<iostream>
#include<string>
#include<stack>
#include<cmath>
using namespace std;
class postfix
{
	public:
		stack<int>st;
		
		bool isoperator(char x)
		{
			switch(x)
			{
				case '+':
					return true;
				case '*':
					return true;
				case '-':
					return true;
				case '/':
					return true;
				case '%':
					return true;
				case '^':
					return true;		
				default:
					return false;				
			}
		}
		
		bool isnum(char x)
		{
			return (x>='0' && x<='9');
		}
			
		int solve(int o1,int o2,char x)
		{
			switch(x)
			{
				case '+':
					return o1+o2;
				case '*':
					return o1*o2;
				case '-':
					return o1-o2;
				case '/':
					return o1/o2;
				case '%':
					return o1%o2;
				case '^':
					return pow(o1,o2);						
			}
		}
		
		int evaluate(string s)
		{
			for(int i=0;i<s.length();i++)
			{
				if(s[i]==' ' || s[i]==',')
					continue;
				
				if(isnum(s[i]))
				{
					int o1=s[i]-48;
					while(i<s.length() && isnum(s[i+1]))
					{
						i++;
						o1=(o1*10)+(s[i]-48);
					}
					st.push(o1);
				}
				else if(isoperator(s[i]))
				{
					int op2=st.top();
					st.pop();
					int op1=st.top();
					st.pop();
					cout<<op1<<" "<<op2<<" "<<s[i]<<" ";
					int ans=solve(op1,op2,s[i]);
					cout<<ans<<endl;
					st.push(ans);
				}		
			}
			return st.top();
		}
};

int main()
{
	postfix p;
	string exp = "7 2 3 * - 4 ^ 9 3 / +";
	cout<<p.evaluate(exp)<<endl;
}
