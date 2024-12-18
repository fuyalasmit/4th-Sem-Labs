#include <iostream>
using namespace std;

// Node class representing each element in the linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Linked List class with insertion operations
class SinglyLinkedList {
private:
    Node* head;

public:
    // Constructor
    SinglyLinkedList() {
        head = nullptr;
    }

    // A. Insert node at the beginning of the list
    void insertAtBeginning(int value) {
        // Create a new node
        Node* newNode = new Node(value);
        
        // If list is empty, make this node the head
        if (head == nullptr) {
            head = newNode;
            return;
        }
        
        // Set new node's next to current head
        newNode->next = head;
        
        // Update head to point to new node
        head = newNode;
    }

    // B. Insert node at the end of the list
    void insertAtEnd(int value) {
        // Create a new node
        Node* newNode = new Node(value);
        
        // If list is empty, make this node the head
        if (head == nullptr) {
            head = newNode;
            return;
        }
        
        // Traverse to the last node
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        
        // Attach the new node at the end
        current->next = newNode;
    }

    // C. Insert node after a specific node
    void insertAfter(int existingValue, int newValue) {
        // If list is empty, can't insert after
        if (head == nullptr) {
            cout << "List is empty. Cannot insert." << endl;
            return;
        }
        
        // Traverse to find the node with existingValue
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
        newNode->next = current->next;
        current->next = newNode;
    }

    // D. Insert node before a specific node
    void insertBefore(int existingValue, int newValue) {
        // If list is empty, can't insert before
        if (head == nullptr) {
            cout << "List is empty. Cannot insert." << endl;
            return;
        }
        
        // Special case: inserting before head
        if (head->data == existingValue) {
            insertAtBeginning(newValue);
            return;
        }
        
        // Traverse to find the node before the target node
        Node* current = head;
        Node* previous = nullptr;
        
        while (current != nullptr && current->data != existingValue) {
            previous = current;
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
        previous->next = newNode;
        newNode->next = current;
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
    ~SinglyLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Demonstration of the implementation
int main() {
    SinglyLinkedList list;

    // Demonstrating insertion operations
    cout << "Inserting at beginning:" << endl;
    list.insertAtBeginning(10);
    list.display();  // Should show: 10

    list.insertAtBeginning(5);
    list.display();  // Should show: 5 10

    cout << "\nInserting at end:" << endl;
    list.insertAtEnd(15);
    list.display();  // Should show: 5 10 15

    cout << "\nInserting after specific node:" << endl;
    list.insertAfter(10, 12);
    list.display();  // Should show: 5 10 12 15

    cout << "\nInserting before specific node:" << endl;
    list.insertBefore(15, 14);
    list.display();  // Should show: 5 10 12 14 15

    return 0;
}