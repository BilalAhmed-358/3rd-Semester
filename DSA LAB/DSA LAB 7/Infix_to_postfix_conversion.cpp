#include <iostream>
#include <stack>
using namespace std;
string infixToPostfix(string infix);
int prec(char c)
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
int main()
{
    string infix, postfix;
    cout << "Enter the infix expression.\n";
    getline(cin, infix);
    postfix = infixToPostfix(infix);
    cout<<"The postfix form of the string you entered is:\n";
    cout << postfix;
}
string infixToPostfix(string infix)
{
    string postfix;
    stack<char> stk;
    for (int i = 0; i < infix.size(); i++)
    {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')||(infix[i] >= '0' && infix[i] <= '9'))
        {
            postfix += infix[i];
        }
        else if (infix[i] == '(')
        {
            stk.push(infix[i]);
        }
        else if (infix[i] == '^')
        {
            stk.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!stk.empty() && stk.top() != '(')
            {
                char temp = stk.top();
                postfix += temp;
                stk.pop();
            }
            stk.pop(); //for popping the '(' out of the stack
        }
        else
        {
            while (!stk.empty() && (prec(infix[i]) <= prec(stk.top())))
            {
                char temp = stk.top();
                postfix += temp;
                stk.pop();
            }
            stk.push(infix[i]);
        }
    }
    while (!stk.empty())
    {
        char temp = stk.top();
        postfix += temp;
        stk.pop();
    }

    return postfix;
}