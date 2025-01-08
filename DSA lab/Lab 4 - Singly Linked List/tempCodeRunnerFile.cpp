// 2. IMPLEMENT QUEUE  AS LINKED LIST
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

class Queue {
private:
    Node* front; // Points to the first element
    Node* rear;  // Points to the last element

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Enqueue operation (insert at rear)
    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (rear == nullptr) { // Queue is empty
            front = rear = newNode;
            cout << value << " added to the queue." << endl;
            return;
        }

        rear->next = newNode; // Link new node to the last node
        rear = newNode;       // Update rear pointer
        cout << value << " added to the queue." << endl;
    }

    // Dequeue operation (remove from front)
    void dequeue() {
        if (front == nullptr) { // Queue is empty
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        Node* temp = front;    // Store the current front node
        front = front->next;   // Move front pointer to the next node

        // If the queue becomes empty after dequeuing
        if (front == nullptr) {
            rear = nullptr;
        }

        cout << temp->data << " removed from the queue." << endl;
        delete temp; // Free memory of the dequeued node
    }

    // Display the queue elements
    void display() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* current = front;
        cout << "Queue: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Queue queue;
    queue.display();

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.display();

    queue.dequeue();
    queue.display();

    queue.dequeue();
    queue.dequeue();
    queue.dequeue(); // Trying to dequeue from an empty queue

    return 0;
}
