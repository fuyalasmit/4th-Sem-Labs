// 1. INSERTION OPERATIONS
// a. INSERT NODE AT BEGINNING OF THE LIST
// b. INSERT NODE AT END OF THE LIST
// c. INSERT NODE AFTER SPECIFIC NODE
// d. INSERT NODE BEFORE SPECIFIC NODE

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }
        
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        
        if (tail == nullptr) {
            head = tail = newNode;
            return;
        }
        
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    void insertAfter(int existingValue, int newValue) {
        if (head == nullptr) {
            cout << "List is empty. Cannot insert." << endl;
            return;
        }
        
        Node* current = head;
        while (current != nullptr && current->data != existingValue) {
            current = current->next;
        }
        
        if (current == nullptr) {
            cout << "Node with value " << existingValue << " not found." << endl;
            return;
        }
        
        Node* newNode = new Node(newValue);
        
        if (current == tail) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            return;
        }
        
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
    }

    void insertBefore(int existingValue, int newValue) {
        if (head == nullptr) {
            cout << "List is empty. Cannot insert." << endl;
            return;
        }
        
        if (head->data == existingValue) {
            insertAtBeginning(newValue);
            return;
        }
        
        Node* current = head;
        while (current != nullptr && current->data != existingValue) {
            current = current->next;
        }
        
        if (current == nullptr) {
            cout << "Node with value " << existingValue << " not found." << endl;
            return;
        }
        
        Node* newNode = new Node(newValue);
        
        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
    }

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