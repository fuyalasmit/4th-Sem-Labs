// 2. DELETION OPERATIONS
// a. DELETE NODE FROM BEGINNING OF THE LIST
// b. DELETE NODE FROM END OF THE LIST
// c. DELETE NODE AFTER SPECIFIC NODE
// d. DELETE NODE BEFORE SPECIFIC NODE

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

    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }
        
        Node* temp = head;
        
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        
        delete temp;
    }

    void deleteFromEnd() {
        if (tail == nullptr) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }
        
        Node* temp = tail;
        
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        
        delete temp;
    }

    void deleteAfter(int existingValue) {
        if (head == nullptr || head == tail) {
            cout << "Cannot delete after. List is too short." << endl;
            return;
        }
        
        Node* current = head;
        while (current != nullptr && current->data != existingValue) {
            current = current->next;
        }
        
        if (current == nullptr || current->next == nullptr) {
            cout << "Node not found or no node after it to delete." << endl;
            return;
        }
        
        Node* nodeToDelete = current->next;
        
        if (nodeToDelete == tail) {
            tail = current;
            current->next = nullptr;
        } else {
            current->next = nodeToDelete->next;
            nodeToDelete->next->prev = current;
        }
        
        delete nodeToDelete;
    }

    void deleteBefore(int existingValue) {
        if (head == nullptr || head == tail) {
            cout << "Cannot delete before. List is too short." << endl;
            return;
        }
        
        Node* current = head;
        while (current != nullptr && current->data != existingValue) {
            current = current->next;
        }
        
        if (current == nullptr || current == head) {
            cout << "Node not found or no node before it to delete." << endl;
            return;
        }
        
        Node* nodeToDelete = current->prev;
        
        if (nodeToDelete == head) {
            head = current;
            current->prev = nullptr;
        } else {
            nodeToDelete->prev->next = current;
            current->prev = nodeToDelete->prev;
        }
        
        delete nodeToDelete;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
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

};

int main() {
    DoublyLinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);

    cout << "Original List:" << endl;
    list.display();

    cout << "\nDeleting from beginning:" << endl;
    list.deleteFromBeginning();
    list.display();

    cout << "\nDeleting from end:" << endl;
    list.deleteFromEnd();
    list.display();

    cout << "\nDeleting after node with value 20:" << endl;
    list.deleteAfter(20);
    list.display();

    cout << "\nDeleting before node with value 30:" << endl;
    list.deleteBefore(30);
    list.display();

    return 0;
}