// 2
// a. Convert infix expression to postfix expression
// b. Convert infix expression to prefix expression
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

string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";
    int i = 0; // Start from the first character

    while (i < infix.length()) { // Continue until all characters are processed
        char c = infix[i];
        if (isOperand(c)) {
            postfix += c; // Append operands directly
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop(); // Remove '('
        } else if (isOperator(c)) {
            while (!st.empty() && precedence(c) <= precedence(st.top())) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
        i++; // Move to the next character
    }

    // Pop remaining operators from the stack
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

string infixToPrefix(string infix) {
    stack<char> st;
    string prefix = "";
    int i = infix.length() - 1;  // Start from the end of the string

    while (i >= 0) {  // Loop through the string in reverse order
        char c = infix[i];

        if (isOperand(c)) {
            prefix = c + prefix; // Prepend operands (because we are traversing right to left)
        } else if (c == ')') {
            st.push(c); // Push closing parenthesis to stack
        } else if (c == '(') {
            while (!st.empty() && st.top() != ')') {
                prefix = st.top() + prefix; // Pop operators and prepend to the result
                st.pop();
            }
            st.pop(); // Pop closing parenthesis
        } else if (isOperator(c)) {
            while (!st.empty() && precedence(c) < precedence(st.top())) {
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
    int choice;

    cout << "Enter the infix expression: ";
    getline(cin, infix);
    cout << "Choose the conversion type:\n";
    cout << "1. Infix to Postfix\n";
    cout << "2. Infix to Prefix\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        cout << "The converted postfix expression is: " << infixToPostfix(infix) << endl;
    } else if (choice == 2) {
        cout << "The converted prefix expression is: " << infixToPrefix(infix) << endl;
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
