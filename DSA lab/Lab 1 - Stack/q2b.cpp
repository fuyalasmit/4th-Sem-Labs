//Convert infix expression to prefix expression
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char op) {
    return (op == '+' || op == '-' || op == '*' || op == '/' || op == '^');
}

bool isOperand(char op) {
    return ((op >= 'A' && op <= 'Z') || (op >= 'a' && op <= 'z') || (op >= '0' && op <= '9'));
}

string infixToPrefix(string infix) {
    stack<char> st;
    string prefix = "";
    int i = infix.length() - 1;  // Start from the end of the string

    while (i >= 0) {  // Loop through the string in reverse order
        char c = infix[i];

        if (isOperand(c)) {
            prefix = c + prefix; // Prepend operands (because we are traversing right to left)
        }
        else if (c == ')') {
            st.push(c); // Push closing parenthesis to stack
        }
        else if (c == '(') {
            while (!st.empty() && st.top() != ')') {
                prefix = st.top() + prefix; // Pop operators and prepend to the result
                st.pop();
            }
            st.pop(); // Pop closing parenthesis
        }
        else if (isOperator(c)) {
            while (!st.empty() && precedence(c) < precedence(st.top()) ) {
                prefix = st.top() + prefix; // Pop operators and prepend to the result
                st.pop();
            }
            st.push(c); // Push the current operator to the stack
        }

        i--; // Move to the previous character
    }

    // Pop any remaining operators from the stack
    while (!st.empty()) {
        prefix = st.top() + prefix;
        st.pop();
    }

    return prefix;
}

int main() {
    string infix;
    cout << "Enter the infix expression: ";
    getline(cin, infix);
    cout << "Entered infix expression is: " << infix << endl;

    string prefix = infixToPrefix(infix);
    cout << "The converted prefix expression is: " << prefix << endl;

    return 0;
}
