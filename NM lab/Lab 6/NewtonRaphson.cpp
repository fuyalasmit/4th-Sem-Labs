// newton raphson
#include <iostream>
#include <cmath>
using namespace std;

double function(double x)
{
    // return x*x -  4;
    // return sin(x-4);
}
double derivative(double x)
{
    // return 2*x;
    // return cos(x-4);
}

int main()
{
    double x0, x1;
    cout << "Enter the initial guess: ";
    cin >> x0;

    while (1)
    {
        if (function(x0) == 0)
        {
            cout << "Error: Division by zero" << endl;
            break;
        }
        x1 = x0 - function(x0) / derivative(x0);
        if (abs(x1 - x0) < 0.001)
        {
            cout << "The root is: " << x1 << endl;
            break;
        }
        x0 = x1;
    }

    return 0;
}