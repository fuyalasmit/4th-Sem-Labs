#include <iostream>
#include <cmath>
#include <string>
using namespace std;

double f(double x)
{
    return exp(x) - 3 * x;
    // return x*x + tan(x) + exp(x);
    // return 1 / (x * x * x);
    // return 1/(pow(x,3)) + sin(x);
}

int main()
{
    double a, b, c;
    int d;
    cout << "Enter the value of a and b(starting boundary): ";
    cin >> a >> b;
    cout << "Enter the decimal place for tolerance: ";
    cin >> d;
    double tolerance = 0.5 * (pow(10, -d));
    // int n = ceil(log(abs(b - a) - log(tolerance)) / log(2));
    int n = ceil((log(abs(b - a)) - log(tolerance)) / log(2));
    if (f(a) * f(b) > 0)
    {
        cout << "Error, no value between these two inputs";
        return 1;
    }
    else if (f(a) * f(b) == 0)
    {
        if (f(a) == 0)
        {
            cout << a << endl;
        }
        else
        {
            cout << b << endl;
        }
    }
    else
    {
        int count = 0;
        do
        {
            c = (a + b) / 2.0;
            if (f(c) * f(a) < 0)
            {
                b = c;
            }
            else
            {
                a = c;
            }
            count++;
            if (count > 2 * n)
            {
                cout << "Discontinuous, can't find the value of this function." << endl;
                return 1;
            }
        } while (abs(f(c)) >= tolerance);
        cout << "Required value is: " << c << endl;
    }
    return 0;
}
