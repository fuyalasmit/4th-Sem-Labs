// polynomial curve fitting using least square method

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int n, i, j, k, d;
    cout << "Enter how many no. of data and degree of polynomial: " << endl;
    cin >> n >> d;
    double *arrX = new double[n];
    double *arrY = new double[n];
    cout << "Enter data for x and y in order, separated by space:" << endl;
    for (i = 0; i < n; i++)
    {
        cin >> arrX[i];
        cin >> arrY[i];
    }

    // Initialize the augmented matrix
    vector<vector<double>> a(d + 1, vector<double>(d + 2, 0.0));

    // Aij matrix formation
    for (i = 0; i < d + 1; i++)
    {
        for (int j = 0; j < d + 2; j++)
        {
            if (j == d + 1)
            {
                for (int k = 0; k < n; k++)
                {
                    a[i][j] += arrY[k] * pow(arrX[k], i);
                }
            }
            else
            {
                for (int k = 0; k < n; k++)
                {
                    a[i][j] += pow(arrX[k], i + j);
                }
            }
        }
    }

    // Printing matrix here
    // cout << "Constructed Augmented Matrix:" << endl;
    // for (int i = 0; i < d + 1; i++)
    // {
    //     for (int j = 0; j < d + 2; j++)
    //     {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // gauss jordan method
    n = d + 1;
    for (j = 0; j < n; j++)
    {
        if (abs(a[j][j]) <= 0.005)
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
    cout << "Coefficients are: ";
    for (i = 0; i < n; i++)
    {
        double x = a[i][n] / a[i][i];
        cout << (x <= 0.0005 && x >= -0.0005 ? 0 : x) << "\t";
    }
    return 0;
}
