#include <iostream>
#include <cmath>
using namespace std;

// Define the functions for Simpson's rule
double f1(double x) {
    return x * x;  // x^2
}

double f2(double x) {
    return x * x * x;  // x^3
}

double f3(double x) {
    return sin(x);  // sin(x)
}

// 1. Trapezoidal Rule with discrete values of y
double trapezoidal(double y[], int n, double h) {
    double sum = (y[0] + y[n-1]) / 2.0;
    for (int i = 1; i < n-1; i++) {
        sum += y[i];
    }
    return sum * h;
}

// 2. Simpson's 1/3 Rule
double simpson13(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / (n - 1);
    double sum = f(a) + f(b);
    for (int i = 1; i < n-1; i++) {
        if (i % 2 != 0) {  // Odd indices
            sum += 4 * f(a + i * h);
        } else {            // Even indices
            sum += 2 * f(a + i * h);
        }
    }
    return sum * h / 3;
}

// 3. Simpson's 3/8 Rule
double simpson38(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / (n - 1);
    double sum = f(a) + f(b);
    for (int i = 1; i < n-1; i++) {
        if (i % 3 == 0) {  // Every third index
            sum += 2 * f(a + i * h);
        } else {            // Other indices
            sum += 3 * f(a + i * h);
        }
    }
    return sum * h * 3 / 8;
}

int main() {
    // Interval and number of subintervals for integration
    double a = 0, b = 1;  // limits of integration
    int n = 7;  // number of subintervals (should be odd for Simpson's 1/3)

    // Discrete y values for Trapezoidal Rule (example with 7 points for each function)
    double y1[] = {0, 0.04, 0.16, 0.36, 0.64, 1, 1.44};  // Values for f1(x) = x^2 at x = 0, 0.2, ..., 1
    double y2[] = {0, 0.008, 0.064, 0.216, 0.512, 1, 1.728};  // Values for f2(x) = x^3 at x = 0, 0.2, ..., 1
    double y3[] = {0, 0.198, 0.389, 0.564, 0.717, 0.841, 0.909};  // Values for f3(x) = sin(x) at x = 0, 0.2, ..., 1

    // For Simpson's Rule, we apply it for each function: f1, f2, f3
    cout << "Results for Simpson's 1/3 Rule:" << endl;
    cout << "For f1(x) = x^2: " << simpson13(f1, a, b, n) << endl;
    cout << "For f2(x) = x^3: " << simpson13(f2, a, b, n) << endl;
    cout << "For f3(x) = sin(x): " << simpson13(f3, a, b, n) << endl;

    cout << "\nResults for Simpson's 3/8 Rule:" << endl;
    cout << "For f1(x) = x^2: " << simpson38(f1, a, b, n) << endl;
    cout << "For f2(x) = x^3: " << simpson38(f2, a, b, n) << endl;
    cout << "For f3(x) = sin(x): " << simpson38(f3, a, b, n) << endl;

    // For Trapezoidal Rule, use discrete y values (example: 7 points)
    cout << "\nResults for Trapezoidal Rule:" << endl;
    cout << "For f1(x): " << trapezoidal(y1, 7, 0.2) << endl;
    cout << "For f2(x): " << trapezoidal(y2, 7, 0.2) << endl;
    cout << "For f3(x): " << trapezoidal(y3, 7, 0.2) << endl;

    return 0;
}
