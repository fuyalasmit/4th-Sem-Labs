// 1. Perform enqueue and dequeue operations in Linear Queue
#include <iostream>
using namespace std;

class Queue
{
private:
    int f, r,size;
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
        if (r == (size - 1))
        {
            cout << "Queue overflow, can't add." << endl;
        }
        else if (r == -1)
        {
            f = r = 0;
            arr[r] = x;
            cout << arr[r] << " is queued to the queue." << endl;
        }
        else
        {
            r++;
            arr[r] = x;
            cout << arr[r] << " is queued to the queue." << endl;
        }
    }
    void dequeue()
    {
        if (f == -1 || f > r)
        {
            cout << "Queue underflow, can't dequeue." << endl;
        }
        else if (f == r)
        {
            cout << arr[f] << " is dequeued from the queue." << endl;
            f = r = -1;
        }
        else
        {
            cout << arr[f] << " is dequeued from the queue." << endl;
            f++;
        }
    }
};

int main()
{
    Queue q(2);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    return 0;
}