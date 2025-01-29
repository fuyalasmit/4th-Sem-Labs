// Trapezoidal and Simpson's Rules Implementation
#include <iostream>
using namespace std;

double func(double x)
{
    return 1 / (1 + x * x);
}

double trapezoidal(double x0, double xn, double h)
{
    int n = (xn - x0) / h;
    double* x = new double[n + 1];
    double* y = new double[n + 1];

    for (int i = 0; i <= n; i++)
    {
        x[i] = x0 + i * h;
        y[i] = func(x[i]);
    }

    double sum = 0;
    for (int i = 1; i < n; i++)
    {
        sum += y[i];
    }

    double result = h / 2 * (y[0] + y[(int)n] + 2 * sum);
    delete[] x;
    delete[] y;
    return result;
}

double simpsons_onethird(double x0, double xn, double h)
{
    int n = (xn - x0) / h;

    // Ensure n is even for Simpson's 1/3 rule
    if (static_cast<int>(n) % 2 != 0)
    {
        cout << "Simpson's 1/3 rule requires an even number of intervals. Adjusting h." << endl;
        return 0;
    }

    double sum = func(x0) + func(xn);

    for (int i = 1; i < n; i++)
    {
        if (i % 2 == 0)
            sum += 2 * func(x0 + i * h);
        else
            sum += 4 * func(x0 + i * h);
    }

    return (h / 3) * sum;
}

double simpsons_threeeighth(double x0, double xn, double h)
{
    int n = (xn - x0) / h;

    // Ensure n is a multiple of 3 for Simpson's 3/8 rule
    if (static_cast<int>(n) % 3 != 0)
    {
        cout << "Simpson's 3/8 rule requires the number of intervals to be a multiple of 3. Adjusting h." << endl;
        return 0;
    }

    double sum = func(x0) + func(xn);

    for (int i = 1; i < n; i++)
    {
        if (i % 3 == 0)
            sum += 2 * func(x0 + i * h);
        else
            sum += 3 * func(x0 + i * h);
    }

    return (3 * h / 8) * sum;
}

int main()
{
    double x0, xn, h;
    cout << "Enter x0, xn, h: ";
    cin >> x0 >> xn >> h;

    cout << "Value using trapezoidal rule: " << trapezoidal(x0, xn, h) << endl;
    cout << "Value using Simpson's 1/3 rule: " << simpsons_onethird(x0, xn, h) << endl;
    cout << "Value using Simpson's 3/8 rule: " << simpsons_threeeighth(x0, xn, h) << endl;

    return 0;
}
