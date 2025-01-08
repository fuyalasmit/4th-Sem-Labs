// Gauss Elimination Method
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, i, j, k;
    cout << "Enter how many unknown values: ";
    cin >> n;

    vector<vector<double>> a(n, vector<double>(n + 1));

    // input
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            cout << "Enter a" << i + 1 << j + 1 << " value: ";
            cin >> a[i][j];
        }
    }

    // operation
    for (j = 0; j < n-1; j++)
    {
        if (a[j][j] == 0)
        {
            cout << "Error: Division by zero" << endl;
            return 1;
        }
        for (i = j+1; i < n; i++)
        {
            double ratio = a[i][j] / a[j][j];
            for (k = 0; k < n + 1; k++)
            {
                a[i][k] = a[i][k] - ratio * a[j][k];
            }
        }
    }

    // calc
    vector<double> x(n);
    x[n-1] = a[n-1][n] / a[n-1][n-1];
    for (i = n-2; i >= 0; i--)
    {
        x[i] = a[i][n];
        for (j = i+1; j < n; j++)
        {
            x[i] = x[i] - a[i][j] * x[j];
        }
        x[i] = x[i] / a[i][i];
    }

    // output
    for (i = 0; i < n; i++)
    {
        cout << "x" << i + 1 << "=" << x[i] << endl;
    }

    return 0;
}