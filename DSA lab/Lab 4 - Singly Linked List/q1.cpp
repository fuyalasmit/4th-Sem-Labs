// 1. IMPLEMENT STACK AS LINKED LIST
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top; // Points to the top of the stack

public:
    Stack() {
        top = nullptr;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top; // New node points to the current top
        top = newNode;       // Update the top to the new node
        cout << value << " pushed onto stack." << endl;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        Node* temp = top;
        top = top->next; // Update the top to the next node
        cout << temp->data << " popped from stack." << endl;
        delete temp;     // Free the memory
    }

    void display() {
        if (top == nullptr) {
            cout << "Stack is empty." << endl;
            return;
        }

        Node* current = top;
        cout << "Stack: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Stack stack;
    stack.display();

    stack.push(10);
    stack.display();

    stack.push(20);
    stack.push(30);
    stack.display();

    stack.pop();
    stack.display();

    stack.pop();
    stack.pop();
    stack.pop(); // Attempting to pop from an empty stack

    return 0;
}
