#include <iostream>
using namespace std;

int l(int a[], int s, int k)
{
    for (int i = 0; i < s; i++)
        if (a[i] == k)
            return i;
    return -1;
}

int bI(int a[], int s, int k)
{
    int l = 0, r = s - 1, m;
    while (l <= r)
    {
        m = l + (r - l) / 2;
        if (a[m] == k)
            return m;
        a[m] < k ? l = m + 1 : r = m - 1;
    }
    return -1;
}

int bR(int a[], int l, int r, int k)
{
    if (l > r)
        return -1;
    int m = l + (r - l) / 2;
    return a[m] == k ? m : a[m] < k ? bR(a, m + 1, r, k)
                                    : bR(a, l, m - 1, k);
}

int main()
{
    int a[] = {11, 12, 22, 25, 34, 64, 90}, s = sizeof(a) / sizeof(a[0]), k = 25;
    cout << "Array:";
    for (int i = 0; i < s; i++)
        cout << a[i] << " ";
    cout << "\nLinear:" << l(a, s, k) << "\nBinary(I):" << bI(a, s, k) << "\nBinary(R):" << bR(a, 0, s - 1, k);
}