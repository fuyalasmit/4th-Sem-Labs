#include <iostream>
using namespace std;

// Function to calculate dy/dx
double fdash(double x, double y)
{
    return (x + y);
    // return x * cos(x);
}

int main()
{
    double xo, yo;
    cout << "Enter xo and yo separated by space: ";
    cin >> xo >> yo;

    int n;
    double h;
    cout << "Enter how many sub-intervals you want: ";
    cin >> n;
    cout << "Enter the interval width (step size): ";
    cin >> h;

    double x[100], y[100];
    x[0] = xo;
    y[0] = yo;

    // Runge-Kutta 4th Order Method
    for (int i = 1; i <= n; i++)
    {
        double k1 = h * fdash(x[i - 1], y[i - 1]);
        double k2 = h * fdash(x[i - 1] + h / 2.0, y[i - 1] + k1 / 2.0);
        double k3 = h * fdash(x[i - 1] + h / 2.0, y[i - 1] + k2 / 2.0);
        double k4 = h * fdash(x[i - 1] + h, y[i - 1] + k3);

        x[i] = x[i - 1] + h;
        y[i] = y[i - 1] + (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
    }

    // Printing results
    cout << "\nResults using RK4 Method:\n";
    cout << "Step\tX\t\tY\n";
    for (int i = 0; i <= n; i++)
    {
        cout << i << "\t" << x[i] << "\t" << y[i] << endl;
    }

    return 0;
}
