#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    vector<double> x(n), y(n);

    cout << "Enter the x and y values:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x[" << i + 1 << "] = ";
        cin >> x[i];
        cout << "y[" << i + 1 << "] = ";
        cin >> y[i];
    }

    // Essential check: duplicate x-values
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (x[i] == x[j]) {
                cout << "Error: Duplicate x-values found!" << endl;
                return 1;
            }
        }
    }

    double xp;
    cout << "Enter the value of x to interpolate: ";
    cin >> xp;

    // Check for exact match
    for (int i = 0; i < n; i++) {
        if (x[i] == xp) {
            cout << "Exact match found! y = " << y[i] << endl;
            return 0;
        }
    }

    double yp = 0;

    // Lagrange's formula
    for (int i = 0; i < n; i++) {
        double term = y[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term *= (xp - x[j]) / (x[i] - x[j]);
            }
        }
        yp += term;
    }

    cout << "Interpolated value at x = " << xp 
         << " is y = " << yp << endl;

    return 0;
}