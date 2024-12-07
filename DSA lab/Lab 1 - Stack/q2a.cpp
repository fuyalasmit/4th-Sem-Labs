// 2.a. Convert infix expression to postfix expression
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}
bool isOperator(char op)
{
    if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isOperand(char op)
{
    if ((op >= 'A' && op <= 'Z') || (op >= 'a' && op <= 'z') || (op >= '0' && op <= '9'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

string infixToPostfix(string infix)
{
    stack<char> st;
    string postfix = "";
    int i = 0; // Start from the first character

    while (i < infix.length())
    { // Continue until all characters are processed
        char c = infix[i];

        if (isOperand(c))
        {
            postfix = postfix + c; // Append operands directly
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix = postfix + st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop(); // Remove '('
        }
        else if (isOperator(c))
        {
            while (!st.empty() && precedence(st.top()) >= precedence(c))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }

        i++; // Move to the next character
    }

    // Pop remaining operators from the stack
    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main()
{
    string infix;
    cout << "Enter the infix expression: " << endl;
    getline(cin, infix);
    cout << "Entered infix expression is: " << infix << endl;
    cout << "The converted postfix expression is: " << infixToPostfix(infix) << endl;
    return 0;
}