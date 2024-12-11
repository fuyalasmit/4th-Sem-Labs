// 3. Perform operations in Deque( Double ended queue) for:
// a. Add at beginning
// b. Add at end
// c. Delete from beginning
// d. Delete from end

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
    void enqueueR()
    {
        int x;
        cout << "Enter value to add at the end: " << endl;
        cin >> x;
        if ((r + 1) % size == f)
        {
            cout << "Queue overflow, can't add." << endl;
        }
        else if (f == -1 || r == -1)
        {
            f = r = 0;
            arr[r] = x;
            cout << arr[r] << " is added to the queue end." << endl;
        }
        else
        {
            r = (r + 1) % size;
            arr[r] = x;
            cout << arr[r] << " is added to the queue end." << endl;
        }
    }
    void enqueueF()
    {
        int x;
        cout << "Enter value to add at the front: " << endl;
        cin >> x;
        if ((f + size - 1) % size == r)
        {
            cout << "Queue overflow, can't add." << endl;
        }
        else if (f == -1 || r == -1)
        {
            f = r = 0;
            arr[f] = x;
            cout << arr[f] << " is added to the queue front." << endl;
        }
        else
        {
            f = (f - 1 + size) % size;
            arr[f] = x;
            cout << arr[f] << " is added to the queue front." << endl;
        }
    }
    void dequeueF()
    {
        if (f == -1 && r == -1)
        {
            cout << "Queue underflow, can't dequeue." << endl;
        }
        else if (f == r)
        {
            cout << arr[f] << " is removed from the queue front." << endl;
            f = r = -1;
        }
        else
        {
            cout << arr[f] << " is removed from the queue front." << endl;
            f = (f + 1) % size;
        }
    }
    void dequeueR()
    {
        if (f == -1 && r == -1)
        {
            cout << "Queue underflow, can't dequeue." << endl;
        }
        else if (f == r)
        {
            cout << arr[r] << " is removed from the queue end." << endl;
            f = r = -1;
        }
        else
        {
            cout << arr[r] << " is removed from the queue end." << endl;
            r = (r - 1 + size) % size;
        }
    }
    void display()
    {
        if (f == -1 && r == -1)
        {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Current queue is: ";
        int i = f;
        while (true)
        {
            cout << arr[i] << "\t";
            if (i == r)
                break;
            i = (i + 1) % size; 
        }
        cout << endl;
    }
};

int main()
{
    Queue q(5);
    char choice;
    do
    {
        cout << "\nEnter your choice:\n a. Add at beginning\n b. Add at end\n c. Delete from beginning\n d. Delete from end\n e. Display the queue \n f. Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 'a':
            q.enqueueF();
            break;
        case 'b':
            q.enqueueR();
            break;
        case 'c':
            q.dequeueF();
            break;
        case 'd':
            q.dequeueR();
            break;
        case 'e':
            q.display();
            break;
        case 'f':
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 'f');
    return 0;
}