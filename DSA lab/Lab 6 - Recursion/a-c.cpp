#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

int fibonacci(int n) {
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int sumNatural(int n) {
    if (n == 0)
        return 0;
    return n + sumNatural(n - 1);
}

int main() {
    cout << "Factorial of 5 is: " << factorial(5) << endl;
    cout << "Fibonacci of 6th element: " << fibonacci(6) << endl;
    cout << "Sum of natural numbers till 5 is: " << sumNatural(5) << endl;

    return 0;
}