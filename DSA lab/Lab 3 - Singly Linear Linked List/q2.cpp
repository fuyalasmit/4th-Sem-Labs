// 2. DELETION OPERATIONS
// a. DELETE NODE FROM BEGINNING OF THE LIST
// b. DELETE NODE FROM END OF THE LIST
// c. DELETE NODE AFTER SPECIFIC NODE

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

// Linked List class with insertion and deletion operations
class SinglyLinkedList {
private:
    Node* head;

public:
    // Constructor
    SinglyLinkedList() {
        head = nullptr;
    }

    // Previous insertion methods (insertAtBeginning, insertAtEnd, etc.) remain the same

    // A. Delete node from the beginning of the list
    void deleteFromBeginning() {
        // If list is empty, nothing to delete
        if (head == nullptr) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }
        
        // Store the current head
        Node* temp = head;
        
        // Move head to next node
        head = head->next;
        
        // Free the memory of the first node
        delete temp;
    }

    // B. Delete node from the end of the list
    void deleteFromEnd() {
        // If list is empty, nothing to delete
        if (head == nullptr) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }
        
        // If only one node exists
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        
        // Traverse to find the second last node
        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        
        // Delete the last node
        delete current->next;
        
        // Set next of second last node to null
        current->next = nullptr;
    }

    // C. Delete node after a specific node
    void deleteAfter(int existingValue) {
        // If list is empty or has only one node
        if (head == nullptr || head->next == nullptr) {
            cout << "Cannot delete after. List is too short." << endl;
            return;
        }
        
        // Find the node with the existing value
        Node* current = head;
        while (current != nullptr && current->data != existingValue) {
            current = current->next;
        }
        
        // If node not found
        if (current == nullptr || current->next == nullptr) {
            cout << "Node not found or no node after it to delete." << endl;
            return;
        }
        
        // Store the node to be deleted
        Node* nodeToDelete = current->next;
        
        // Link current node to the next of next node
        current->next = current->next->next;
        
        // Free the memory
        delete nodeToDelete;
    }

    // Display the list (same as before)
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

    // Insert methods from previous implementation (to make the example complete)
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        
        current->next = newNode;
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

    // Populate the list
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);

    cout << "Original List:" << endl;
    list.display();

    // Demonstrate deletion operations
    cout << "\nDeleting from beginning:" << endl;
    list.deleteFromBeginning();
    list.display();

    cout << "\nDeleting from end:" << endl;
    list.deleteFromEnd();
    list.display();

    cout << "\nDeleting after node with value 20:" << endl;
    list.deleteAfter(20);
    list.display();

    return 0;
}