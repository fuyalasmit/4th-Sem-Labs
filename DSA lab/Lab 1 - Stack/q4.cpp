// 4. Check the paired parenthesis in mathematical expression
#include <iostream>
#include <stack>
using namespace std;

// Function to check if parentheses are balanced
bool checkParentheses(string expression) {
    stack<char> st;
    int i = 0; // Initialize the index for the while loop

    while (i < expression.length()) { // Loop through the entire string
        char c = expression[i];

        if (c == '(') {
            st.push(c); // Push opening parenthesis
        } else if (c == ')') {
            if (st.empty()) {
                return false; // Unmatched closing parenthesis
            }
            st.pop(); // Pair matched, pop the stack
        }

        i++; // Move to the next character in the expression
    }

    // If stack is empty, all parentheses are paired
    return st.empty();
}

int main() {
    string expression;
    cout << "Enter a mathematical expression: ";
    cin >> expression;

    if (checkParentheses(expression)) {
        cout << "The parentheses are balanced." << endl;
    } else {
        cout << "The parentheses are not balanced." << endl;
    }

    return 0;
}
