// Euler's Method
#include <iostream>
#include<cmath>
using namespace std;

// Function to calculate dy/dx
double fdash(double x, double y) {
    // return (x + y); 
    // return x * cos(x);
    return (x*x + y); 

}
 
int main() {
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

    
    for (int i = 1; i <= n; i++) {
        x[i] = x[i - 1] + h; 
        y[i] = y[i - 1] + h * fdash(x[i - 1], y[i - 1]); 
    }

    // Printing results
    cout << "\nResults:\n";
    cout << "Step\tX\t\tY\n";
    for (int i = 0; i <= n; i++) {
        cout << i << "\t" << x[i] << "\t" << y[i] << endl;
    }
    


    return 0;
}
