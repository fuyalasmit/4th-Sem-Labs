// 3. REPRESENT THE POLYNOMIAL EQUATION USING LINKED LIST TO PERFORM ADDITION OF TWO POLYNOMIALS.

#include <iostream>
using namespace std;

class Node {
public:
    int coeff, expo;
    Node* next;
    Node(int c, int e) {
        coeff = c;
        expo = e;
        next = nullptr;
    }
};

class List {
public:
    Node* head;
    List() { head = nullptr; }

    void insert(int coeff, int expo) {
        Node* temp = new Node(coeff, expo);
        if (head==nullptr) {
            head = temp;
        } else {
            Node* curr = head;
            while (curr->next!=nullptr)
                curr = curr->next;
            curr->next = temp;
        }
    }

    void display() {
        Node* temp = head;
        while (temp->next!=nullptr) {
            cout << " + "<<temp->coeff << "x^" << temp->expo;
            temp = temp->next;
        }
        cout << endl;
    }
};

Node* addPoly(Node* p, Node* q) {
    Node* rHead = nullptr;
    Node* rTail = nullptr;

    while (p && q) {
        Node* temp = nullptr;
        if (p->expo == q->expo) {
            temp = new Node(p->coeff + q->coeff, p->expo);
            p = p->next;
            q = q->next;
        } else if (p->expo > q->expo) {
            temp = new Node(p->coeff, p->expo);
            p = p->next;
        } else {
            temp = new Node(q->coeff, q->expo);
            q = q->next;
        }

        if (!rHead) {
            rHead = rTail = temp;
        } else {
            rTail->next = temp;
            rTail = temp;
        }
    }

    // Copy remaining terms
    while (p) {
        rTail->next = new Node(p->coeff, p->expo);
        rTail = rTail->next;
        p = p->next;
    }
    while (q) {
        rTail->next = new Node(q->coeff, q->expo);
        rTail = rTail->next;
        q = q->next;
    }

    return rHead;
}

int main() {
    List P, Q, R;

    // Sample Input for P: 5x^2 + 4x^1 + 2x^0
    P.insert(5, 2);
    P.insert(4, 1);
    P.insert(2, 0);

    // Sample Input for Q: 5x^1 + 5x^0
    Q.insert(5, 1);
    Q.insert(5, 0);

    cout << "Polynomial P: ";
    P.display();

    cout << "Polynomial Q: ";
    Q.display();

    Node* result = addPoly(P.head, Q.head);
    R.head = result;

    cout << "Sum Polynomial R: ";
    R.display();

    return 0;
}
