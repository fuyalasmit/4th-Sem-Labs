#include <iostream>
using namespace std;

struct nodeType
{
    int data;
    int next;
} node[10];

class Queue
{
    int max_size;

public:
    int front, rear, avail;

    Queue(int size)
    {
        max_size = size;
        front = -1;
        rear = -1;
        avail = 0;

        for (int i = 0; i < size; i++)
        {
            node[i].next = i + 1;
        }
        node[size - 1].next = -1;
    }

    int getNode(int x)
    {
        if (avail == -1)
        {
            cout << "Queue overflow" << endl;
            return -1;
        }
        int index = avail;
        avail = node[avail].next;
        node[index].data = x;
        node[index].next = -1;
        return index;
    }

    void freeNode(int index)
    {
        node[index].next = avail;
        avail = index;
    }

    void enqueue(int x)
    {
        int new_index = getNode(x);
        if (new_index == -1)
            return;

        if (front == -1)
        {
            front = new_index;
            rear = new_index;
        }
        else
        {
            node[rear].next = new_index;
            rear = new_index;
        }
    }

    int dequeue()
    {
        if (front == -1)
        {
            cout << "Queue underflow" << endl;
            return -1;
        }

        int del_index = front;
        int del_item = node[del_index].data;

        front = node[del_index].next;

        if (front == -1)
        {
            rear = -1;
        }

        freeNode(del_index);
        return del_item;
    }

    void displayQueue()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        int index = front;
        cout << "Queue: ";
        while (index != -1)
        {
            cout << node[index].data << " ";
            index = node[index].next;
        }
        cout << endl;
    }
};

int main()
{
    Queue q(10);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.displayQueue();

    cout << "Dequeued: " << q.dequeue() << endl;
    q.displayQueue();

    q.enqueue(4);
    q.enqueue(5);
    q.displayQueue();

    cout << "Dequeued: " << q.dequeue() << endl;
    q.displayQueue();

    return 0;
}