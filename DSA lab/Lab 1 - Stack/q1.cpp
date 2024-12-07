// Perform push and pop operations in stack

#include <iostream>

using namespace std;

const int SIZE = 5;
int top = -1;
int stack[SIZE];

void push(int value)
{
    if (top >= SIZE - 1)
    {
        cout << "Stack overflow, cannot push." << endl;
    }
    else
    {
        top++;
        stack[top] = value;
        cout << value << " is pushed into stack." << endl;
    }
}
void pop(){
    if(top < 0){
        cout<<"Stack underflow, cannot pop."<<endl;
    }
    else{
        cout<<stack[top]<< " is popped out of the stack."<<endl;
        top--;
    }
}

int main()
{
    push(5);
    push(10);
    push(11);
    push(11);
    push(11);
    push(11);
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    return 0;
}
