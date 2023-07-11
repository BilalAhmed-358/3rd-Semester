#include <iostream>
#include <stack>

using namespace std;

bool Check_Operator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Check_Precedence(char c)
{
	if (c == '^')
		return 3;
	else if (c == '*' || c == '/')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}

string InfixToPostfix(stack<char> s, string infix)
{
	string postfix;
	for (int i = 0; i < infix.length(); i++)
	{
		if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')||(infix[i] >= '0' && infix[i] <= '9'))
		{
			postfix += infix[i];
		}
		else if (infix[i] == '(')
		{
			s.push(infix[i]);
		}
		else if (infix[i] == ')')
		{
			while ((s.top() != '(') && (!s.empty()))
			{
				char temp = s.top();
				postfix += temp;
				s.pop();
			}
			if (s.top() == '(')
			{
				s.pop();
			}
		}
		else if (Check_Operator(infix[i]))
		{
			if (s.empty())
			{
				s.push(infix[i]);
			}
			else
			{
				if (Check_Precedence(infix[i]) > Check_Precedence(s.top()))
				{
					s.push(infix[i]);
				}
				else if ((Check_Precedence(infix[i]) == Check_Precedence(s.top())) && (infix[i] == '^'))
				{
					s.push(infix[i]);
				}
				else
				{
					while ((!s.empty()) && (Check_Precedence(infix[i]) <= Check_Precedence(s.top())))
					{
						postfix += s.top();
						s.pop();
					}
					s.push(infix[i]);
				}
			}
		}
	}
	while (!s.empty())
	{
		postfix += s.top();
		s.pop();
	}

	return postfix;
}

int main()
{

	string Infix, Postfix;
	cout << "Write an Infix Expression to Convert:" << endl;
	cin >> Infix;
	stack<char> stack;
	cout << "INFIX EXPRESSION: " << Infix << endl;
	Postfix = InfixToPostfix(stack, Infix);
	cout << endl
		 << "POSTFIX EXPRESSION: " << Postfix;

	return 0;
}
