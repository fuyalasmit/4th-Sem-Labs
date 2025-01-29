#include <iostream>
#include <iomanip> // For better output formatting
#include <cmath> // For exp()
using namespace std;

// Define functions f1 and f2
double f1(double x, double y, double z) {
    return z; // dz/dx = z
}

double f2(double x, double y, double z) {
    return exp(x) + z; // Example: d^2y/dx^2 = x + y
}

int main() {
    double xi, xf, yi, zi, h;

    // Prompt user for inputs
    cout << "Enter initial x: ";
    cin >> xi;
    cout << "Enter final x: ";
    cin >> xf;
    cout << "Enter initial y: ";
    cin >> yi;
    cout << "Enter initial z (dy/dx): ";
    cin >> zi;
    cout << "Enter step size h: ";
    cin >> h;

    // Arrays to store k values
    double k1[2], k2[2], k3[2], k4[2];

    // Print table header
    cout << setw(10) << "x" << setw(15) << "y" << setw(15) << "z (dy/dx)" << endl;
    cout << "----------------------------------------" << endl;

    while (xi < xf) {
        // Compute k1
        k1[0] = h * f1(xi, yi, zi);
        k1[1] = h * f2(xi, yi, zi);

        // Compute k2
        k2[0] = h * f1(xi + h / 2, yi + k1[0] / 2, zi + k1[1] / 2);
        k2[1] = h * f2(xi + h / 2, yi + k1[0] / 2, zi + k1[1] / 2);

        // Compute k3
        k3[0] = h * f1(xi + h / 2, yi + k2[0] / 2, zi + k2[1] / 2);
        k3[1] = h * f2(xi + h / 2, yi + k2[0] / 2, zi + k2[1] / 2);

        // Compute k4
        k4[0] = h * f1(xi + h, yi + k3[0], zi + k3[1]);
        k4[1] = h * f2(xi + h, yi + k3[0], zi + k3[1]);

        // Update y and z
        yi += (k1[0] + 2 * k2[0] + 2 * k3[0] + k4[0]) / 6;
        zi += (k1[1] + 2 * k2[1] + 2 * k3[1] + k4[1]) / 6;

        // Update x
        xi += h;

        // Print the current step with better formatting
        cout << fixed << setprecision(4) << setw(10) << xi << setw(15) << yi << setw(15) << zi << endl;
    }

    return 0;
}