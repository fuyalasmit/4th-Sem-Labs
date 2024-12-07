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

    for (char c : expression)
    {
        if (isdigit(c))
        {
            // Push operands (convert char to int)
            st.push(c - '0');
        }
        else
        {

            int operand2 = st.top();
            st.pop();
            int operand1 = st.top();
            st.pop();

            switch (c)
            {
            case '+':
                st.push(operand1 + operand2);
                break;
            case '-':
                st.push(operand1 - operand2);
                break;
            case '*':
                st.push(operand1 * operand2);
                break;
            case '/':
                st.push(operand1 / operand2);
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
