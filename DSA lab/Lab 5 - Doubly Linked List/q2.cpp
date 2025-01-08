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

    // A. Delete node from the beginning of the list
    void deleteFromBeginning() {
        // If list is empty
        if (head == nullptr) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }
        
        // Store the current head
        Node* temp = head;
        
        // If only one node exists
        if (head == tail) {
            head = tail = nullptr;
        } else {
            // Move head to next node
            head = head->next;
            head->prev = nullptr;
        }
        
        // Free the memory of the first node
        delete temp;
    }

    // B. Delete node from the end of the list
    void deleteFromEnd() {
        // If list is empty
        if (tail == nullptr) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }
        
        // Store the current tail
        Node* temp = tail;
        
        // If only one node exists
        if (head == tail) {
            head = tail = nullptr;
        } else {
            // Move tail to previous node
            tail = tail->prev;
            tail->next = nullptr;
        }
        
        // Free the memory of the last node
        delete temp;
    }

    // C. Delete node after a specific node
    void deleteAfter(int existingValue) {
        // If list is empty or has only one node
        if (head == nullptr || head == tail) {
            cout << "Cannot delete after. List is too short." << endl;
            return;
        }
        
        // Find the node with the existing value
        Node* current = head;
        while (current != nullptr && current->data != existingValue) {
            current = current->next;
        }
        
        // If node not found or it's the last node
        if (current == nullptr || current->next == nullptr) {
            cout << "Node not found or no node after it to delete." << endl;
            return;
        }
        
        // Store the node to be deleted
        Node* nodeToDelete = current->next;
        
        // If deleting the last node, update tail
        if (nodeToDelete == tail) {
            tail = current;
            current->next = nullptr;
        } else {
            // Link the nodes around the deleted node
            current->next = nodeToDelete->next;
            nodeToDelete->next->prev = current;
        }
        
        // Free the memory
        delete nodeToDelete;
    }

    // D. Delete node before a specific node
    void deleteBefore(int existingValue) {
        // If list is empty or has only one node
        if (head == nullptr || head == tail) {
            cout << "Cannot delete before. List is too short." << endl;
            return;
        }
        
        // Find the node with the existing value
        Node* current = head;
        while (current != nullptr && current->data != existingValue) {
            current = current->next;
        }
        
        // If node not found or it's the first node
        if (current == nullptr || current == head) {
            cout << "Node not found or no node before it to delete." << endl;
            return;
        }
        
        // Store the node to be deleted
        Node* nodeToDelete = current->prev;
        
        // If deleting the first node, update head
        if (nodeToDelete == head) {
            head = current;
            current->prev = nullptr;
        } else {
            // Link the nodes around the deleted node
            nodeToDelete->prev->next = current;
            current->prev = nodeToDelete->prev;
        }
        
        // Free the memory
        delete nodeToDelete;
    }

    // Insert methods (for testing)
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

};

int main() {
    DoublyLinkedList list;

    // Insert some test values
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