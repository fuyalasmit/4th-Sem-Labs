#include <iostream>
using namespace std;

void ss(int a[], int n)
{
    for (int i = 0, j, m; i < n - 1; swap(a[i], a[m]), i++)
        for (m = i, j = i + 1; j < n; j++)
            m = a[j] < a[m] ? j : m;
}

void is(int a[], int n)
{
    for (int i = 1, j, k; i < n; a[j + 1] = k, i++)
        for (k = a[i], j = i - 1; j >= 0 && a[j] > k; j--)
            a[j + 1] = a[j];
}

void qs(int a[], int l, int h)
{
    if (l < h)
    {
        int p = a[h], i = l - 1, j;
        for (j = l; j < h; j++)
            if (a[j] < p)
                swap(a[++i], a[j]);
        swap(a[i + 1], a[h]);
        qs(a, l, i);
        qs(a, i + 2, h);
    }
}
void qW(int a[], int n) { qs(a, 0, n - 1); }

void sS(int a[], int n)
{
    for (int g = n / 2; g; g /= 2)
        for (int i = g, j, t; i < n; i++)
        {
            t = a[i];
            for (j = i; j >= g && a[j - g] > t; j -= g)
                a[j] = a[j - g];
            a[j] = t;
        }
}

void mg(int a[], int l, int m, int r)
{
    int x = m - l + 1, y = r - m, L[x], R[y], i = 0, j = 0, k = l;
    for (; i < x; i++)
        L[i] = a[l + i];
    for (; j < y; j++)
        R[j] = a[m + 1 + j];
    for (i = j = 0; k <= r; a[k++] = i < x && (j == y || L[i] < R[j]) ? L[i++] : R[j++])
        ;
}
void mS(int a[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mS(a, l, m);
        mS(a, m + 1, r);
        mg(a, l, m, r);
    }
}
void mW(int a[], int n) { mS(a, 0, n - 1); }

void p(int *a, int n)
{
    for (; n--;)
        cout << *a++ << " ";
    cout << endl;
}

int main()
{
    int o[] = {64, 34, 25, 12, 22, 11, 90}, n = 7, t[7];
    cout << "Original: ";
    p(o, n);
    void (*f[])(int *, int) = {ss, is, qW, sS, mW};
    const char *s[] = {"Selection", "Insertion", "Quick", "Shell", "Merge"};
    for (int i = 0; i < 5; i++)
    {
        copy(o, o + n, t);
        f[i](t, n);
        cout << s[i] << ": ";
        p(t, n);
    }
}