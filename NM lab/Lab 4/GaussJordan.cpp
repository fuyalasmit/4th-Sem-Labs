// Gauss Jordan Method
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
    for (j = 0; j < n; j++)
    {
        if (a[j][j] == 0)
        {
            cout << "Error: Division by zero" << endl;
            return 1;
        }
        for (i = 0; i < n; i++)
        {
            if (i != j)
            {
                double ratio = a[i][j] / a[j][j];
                for (k = 0; k < n + 1; k++)
                {
                    a[i][k] = a[i][k] - ratio * a[j][k];
                }
            }
        }
    }

    // output
    for (i = 0; i < n; i++)
    {
        double x = a[i][n] / a[i][i];
        cout << "x" << i + 1 << "=" << x << endl;
    }

    return 0;
}