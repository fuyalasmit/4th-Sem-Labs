// 4. Check the paired parenthesis in mathematical expression
#include <iostream>
#include <stack>
using namespace std;

bool checkParentheses(string expression) {
    stack<char> st;
    int i ;

    for (i=0;i < expression.length();i++) { // Loop through the entire string
        char c = expression[i];

        if (c == '(') {
            st.push(c); // Push opening parenthesis
        } else if (c == ')') {
            if (st.empty()) {
                return false; // Unmatched closing parenthesis
            }
            st.pop(); // Pair matched, pop the stack
        }

    }
    
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
