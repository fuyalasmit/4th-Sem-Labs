// Perform push and pop operations in stack

#include <iostream>
using namespace std;

class Stack
{
private:
    int top, SIZE;
    int *arr;

public:
    Stack(int n)
    {
        top = -1;
        SIZE = n;
        arr = new int[SIZE];
    }
    void push(int value)
    {
        if (top >= SIZE - 1)
        {
            cout << "Stack overflow, cannot push." << endl;
        }
        else
        {
            top++;
            arr[top] = value;
            cout << value << " is pushed into stack." << endl;
        }
    }
    void pop()
    {
        if (top < 0)
        {
            cout << "Stack underflow, cannot pop." << endl;
        }
        else
        {
            cout << arr[top] << " is popped out of the stack." << endl;
            top--;
        }
    }
};

int main()
{
    Stack a(2);
    a.push(2);
    a.push(5);
    a.push(10);
    a.pop();
    a.pop();
    a.pop();
    return 0;
}