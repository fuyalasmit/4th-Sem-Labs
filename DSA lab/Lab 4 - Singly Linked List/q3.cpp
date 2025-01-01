// 3. REPRESENT THE POLYNOMIAL EQUATION USING LINKED LIST TO PERFORM ADDITION OF TWO POLYNOMIALS.

#include <iostream>
using namespace std;

// Node structure for the linked list
class Node {
public:
    int coeff;  // Coefficient
    int expo;   // Exponent
    Node* next;

    Node(int c, int e) {
        coeff = c;
        expo = e;
        next = nullptr;
    }
};

// Function to create a polynomial
Node* createPolynomial() {
    Node* head = nullptr;

    cout << "Enter terms of the polynomial (coefficient exponent). Use '-1 -1' to stop:\n";
    while (true) {
        int coeff, expo;
        cin >> coeff >> expo;

        if (coeff == -1 && expo == -1) break;

        // Create a new node
        Node* newNode = new Node(coeff, expo);

        // Insert the node in sorted order based on exponent
        if (head == nullptr || expo > head->expo) {
            // Insert at the head
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr && current->next->expo > expo) {
                current = current->next;
            }
            if (current->expo == expo) {
                // Combine like terms
                current->coeff += coeff;
                delete newNode; // Clean up unused node
            } else {
                // Insert in the middle or end
                newNode->next = current->next;
                current->next = newNode;
            }
        }
    }
    return head;
}

// Function to display a polynomial
void displayPolynomial(Node* poly) {
    if (!poly) {
        cout << "0\n";
        return;
    }

    while (poly) {
        cout << poly->coeff << "x^" << poly->expo;
        if (poly->next) cout << " + ";
        poly = poly->next;
    }
    cout << endl;
}

// Function to append remaining terms to the result
void appendRemaining(Node*& tail, Node* poly) {
    while (poly) {
        Node* newNode = new Node(poly->coeff, poly->expo);
        if (tail) {
            tail->next = newNode;
            tail = newNode;
        } else {
            tail = newNode;
        }
        poly = poly->next;
    }
}

// Function to add two polynomials
Node* addPolynomials(Node* p, Node* q) {
    Node* result = nullptr; // Head of result
    Node* tail = nullptr;   // Tail pointer for result

    while (p && q) {
        Node* newNode = nullptr;

        if (p->expo == q->expo) {
            // Add coefficients of like terms
            newNode = new Node(p->coeff + q->coeff, p->expo);
            p = p->next;
            q = q->next;
        } else if (p->expo > q->expo) {
            // Copy term from P
            newNode = new Node(p->coeff, p->expo);
            p = p->next;
        } else { // q->expo > p->expo
            // Copy term from Q
            newNode = new Node(q->coeff, q->expo);
            q = q->next;
        }

        // Append to result
        if (!result) {
            result = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Append remaining terms
    appendRemaining(tail, p);
    appendRemaining(tail, q);

    return result;
}

int main() {
    cout << "Create the first polynomial:\n";
    Node* polyP = createPolynomial();

    cout << "Create the second polynomial:\n";
    Node* polyQ = createPolynomial();

    cout << "First Polynomial: ";
    displayPolynomial(polyP);

    cout << "Second Polynomial: ";
    displayPolynomial(polyQ);

    // Add the two polynomials
    Node* result = addPolynomials(polyP, polyQ);

    cout << "Resultant Polynomial: ";
    displayPolynomial(result);

    return 0;
}
