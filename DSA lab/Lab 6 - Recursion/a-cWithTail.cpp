#include <iostream>
using namespace std;

int factorialTail(int n, int acc = 1) {
    if (n == 0 || n == 1)
        return acc;
    return factorialTail(n - 1, acc * n);
}

int fibonacciTail(int n, int a = 0, int b = 1) {
    if (n == 0)
        return a;
    if (n == 1)
        return b;
    return fibonacciTail(n - 1, b, a + b);
}

int sumNaturalTail(int n, int acc = 0) {
    if (n == 0)
        return acc;
    return sumNaturalTail(n - 1, acc + n);
}

int main() {
    cout << "Factorial using Tail Recursion for 5 is: " << factorialTail(5) << endl;
    cout << "Fibonacci using tail recursion for 7th element is: " << fibonacciTail(7) << endl;
    cout << "Sum of natural numbers using tail recursion till 5 is: " << sumNaturalTail(5) << endl;

    return 0;
}