// 2. Perform enqueue and dequeue operations in Circular Queue
#include <iostream>
using namespace std;

class Queue
{
private:
    int f, r;
    int size;
    int *arr;

public:
    Queue(int n)
    {
        size = n;
        arr = new int[size];
        f = -1;
        r = -1;
    }
    void enqueue(int x)
    {
        if ((r + 1) % size == f)
        {
            cout << "Queue overflow, can't add "<<x<< endl;
        }
        else if (f == -1 || r == -1)
        {
            f = r = 0;
            arr[r] = x;
            cout << arr[r] << " is queued to the queue." << endl;
        }
        else
        {
            r = (r + 1) % size;
            arr[r] = x;
            cout << arr[r] << " is queued to the queue." << endl;
        }
    }
    void dequeue()
    {
        if (f == -1 && r == -1)
        {
            cout << "Queue underflow, can't dequeue." << endl;
        }
        else if (f == r)
        {
            cout << arr[f] << " is dequeued of the queue." << endl;
            f = r = -1;
        }
        else
        {
            cout << arr[f] << " is dequeued of the queue." << endl;
            f = (f + 1) % size;
        }
    }
};

int main()
{
    Queue q(3);
    q.enqueue(5);
    q.enqueue(6);
    q.dequeue();
    q.enqueue(7);
    q.dequeue();
    q.enqueue(8);
    q.enqueue(9);
    q.enqueue(3);
    q.dequeue();
    q.dequeue();
    q.enqueue(4);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    return 0;
}