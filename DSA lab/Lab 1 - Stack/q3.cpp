// 3. Evaluate the postfix expression
#include <iostream>
#include <stack>
#include <cctype> // For isdigit
#include <string>
using namespace std;

// Function to evaluate a postfix expression
int evaluatePostfix(string expression)
{
    stack<int> st;
    for (int i = 0; i < expression.length(); i++)
    {
        char c = expression[i];
        if (isdigit(c))
        {
            // Push operands (convert char to int)
            st.push(c - '0');
        }
        else
        {
            int A = st.top();
            st.pop();
            int B = st.top();
            st.pop();

            switch (c)
            {
            case '+':
                st.push(B + A);
                break;
            case '-':
                st.push(B - A);
                break;
            case '*':
                st.push(B * A);
                break;
            case '/':
                st.push(B / A);
                break;
            }
        }
    }

    // Final result is the single value in the stack
    return st.top();
}

int main()
{
    string postfix;
    cout << "Enter the postfix expression: " << endl;
    getline(cin, postfix);
    cout << "Postfix Expression: " << postfix << endl;
    cout << "Result: " << evaluatePostfix(postfix) << endl;
    return 0;
}
