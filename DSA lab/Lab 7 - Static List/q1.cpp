#include <iostream>
using namespace std;

struct nodeType {
    int data;
    int next;
} node[10]; 

class List {
    int max_size;

public:
    int avail, size, list;

    List(int size) {
        max_size = size;
        avail = 0;
        list = -1;
        for (int i = 0; i < size; i++) {
            node[i].next = i + 1;
        }
        node[size - 1].next = -1;
    }

    int getNode(int x) {
        if (avail == -1) {
            cout << "List overflow" << endl;
            return -1;
        }
        int index = avail;
        avail = node[avail].next;
        node[index].data = x;
        node[index].next = -1;
        return index;
    }

    void insertBeg(int x) {
        int index = getNode(x);
        if (index == -1)
            return;
        node[index].next = list;
        list = index;
    }

    void insertEnd(int x) {
        if (list == -1) {
            insertBeg(x);
            return;
        }
        int index = list;
        while (node[index].next != -1)
            index = node[index].next;
        int new_index = getNode(x);
        if (new_index == -1)
            return;
        node[index].next = new_index;
    }

    void insertAfter(int ref, int x) {
        int i = list;
        while (i != -1 && node[i].data != ref)
            i = node[i].next;
        if (i == -1) {
            cout << "Reference element not found" << endl;
            return;
        }
        int new_index = getNode(x);
        if (new_index == -1)
            return;
        node[new_index].next = node[i].next;
        node[i].next = new_index;
    }

    void freeNode(int index) {
        node[index].next = avail;
        avail = index;
    }

    int deleteBegin() {
        if (list == -1) {
            cout << "List underflow" << endl;
            return -1;
        }
        int index = list;
        list = node[list].next;
        int del_item = node[index].data;
        freeNode(index);
        return del_item;
    }

    int deleteEnd() {
        if (list == -1) {
            cout << "List underflow" << endl;
            return -1;
        }
        if (node[list].next == -1) {
            return deleteBegin();
        }
        int index = list;
        while (node[node[index].next].next != -1)
            index = node[index].next;
        int del_item = node[node[index].next].data;
        freeNode(node[index].next);
        node[index].next = -1;
        return del_item;
    }

    int deleteAfter(int ref) {
        if (list == -1) {
            cout << "List underflow" << endl;
            return -1;
        }
        int i = list;
        while (i != -1 && node[i].data != ref)
            i = node[i].next;
        if (i == -1 || node[i].next == -1) {
            cout << "No element to delete after the reference: " << endl;
            return -1;
        }
        int del_index = node[i].next;
        int del_item = node[del_index].data;
        node[i].next = node[del_index].next;
        freeNode(del_index);
        return del_item;
    }
    
void displayList() {
    if (list == -1) {
        cout << "List is empty" << endl;
        return;
    }

    int index = list;
    cout << "List: ";
    while (index != -1) {
        cout << node[index].data << " ";
        index = node[index].next;
    }
    cout << endl;
}
};

int main() {
    List l(10);
    l.insertBeg(1);
    l.insertEnd(2);
    l.insertAfter(1, 3);
    l.displayList();
    cout << "Deleted from beginning: " << l.deleteBegin() << endl;
    cout << "Deleted from end: " << l.deleteEnd() << endl;
    cout << "Deleted after 1: " << l.deleteAfter(1) << endl;
    return 0;
}
