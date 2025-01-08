// 1. INSERTION OPERATIONS
// a. INSERT NODE AT BEGINNING OF THE LIST
// b. INSERT NODE AT END OF THE LIST
// c. INSERT NODE AFTER SPECIFIC NODE
// d. INSERT NODE BEFORE SPECIFIC NODE
#include <iostream>
using namespace std;

// Node class representing each element in the doubly linked list
class Node {
public:
    int data;
    Node* next;
    Node* prev;    // Additional pointer for previous node

    // Constructor
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;    // Keep track of last node for efficient end operations

public:
    // Constructor
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // A. Insert node at the beginning of the list
    void insertAtBeginning(int value) {
        // Create a new node
        Node* newNode = new Node(value);
        
        // If list is empty
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }
        
        // Link new node with current head
        newNode->next = head;
        head->prev = newNode;
        
        // Update head to point to new node
        head = newNode;
    }

    // B. Insert node at the end of the list
    void insertAtEnd(int value) {
        // Create a new node
        Node* newNode = new Node(value);
        
        // If list is empty
        if (tail == nullptr) {
            head = tail = newNode;
            return;
        }
        
        // Link new node with current tail
        newNode->prev = tail;
        tail->next = newNode;
        
        // Update tail to point to new node
        tail = newNode;
    }

    // C. Insert node after a specific node
    void insertAfter(int existingValue, int newValue) {
        // If list is empty
        if (head == nullptr) {
            cout << "List is empty. Cannot insert." << endl;
            return;
        }
        
        // Find the node with existingValue
        Node* current = head;
        while (current != nullptr && current->data != existingValue) {
            current = current->next;
        }
        
        // If node not found
        if (current == nullptr) {
            cout << "Node with value " << existingValue << " not found." << endl;
            return;
        }
        
        // Create new node
        Node* newNode = new Node(newValue);
        
        // If inserting after tail
        if (current == tail) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            return;
        }
        
        // Link new node
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
    }

    // D. Insert node before a specific node
    void insertBefore(int existingValue, int newValue) {
        // If list is empty
        if (head == nullptr) {
            cout << "List is empty. Cannot insert." << endl;
            return;
        }
        
        // Special case: inserting before head
        if (head->data == existingValue) {
            insertAtBeginning(newValue);
            return;
        }
        
        // Find the node with existingValue
        Node* current = head;
        while (current != nullptr && current->data != existingValue) {
            current = current->next;
        }
        
        // If node not found
        if (current == nullptr) {
            cout << "Node with value " << existingValue << " not found." << endl;
            return;
        }
        
        // Create new node
        Node* newNode = new Node(newValue);
        
        // Link new node
        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
    }

    // Display the list
    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        
        Node* current = head;
        cout << "List: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~DoublyLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    DoublyLinkedList list;

    cout << "Inserting at beginning:" << endl;
    list.insertAtBeginning(10);
    list.display();

    list.insertAtBeginning(5);
    list.display();

    cout << "\nInserting at end:" << endl;
    list.insertAtEnd(15);
    list.display();

    cout << "\nInserting after specific node:" << endl;
    list.insertAfter(10, 12);
    list.display();

    cout << "\nInserting before specific node:" << endl;
    list.insertBefore(15, 14);
    list.display();

    return 0;
}