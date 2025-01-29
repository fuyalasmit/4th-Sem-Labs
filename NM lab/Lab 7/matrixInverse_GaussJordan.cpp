#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the order of the matrix: ";
    cin >> n;

    double a[10][20]; // Adjust size if larger matrix is needed (10x10 max)

    // Input the matrix
    cout << "Enter the elements of the matrix row-wise:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    // Append the identity matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                a[i][j + n] = 1.0;
            else
                a[i][j + n] = 0.0;
        }
    }

    // Gauss-Jordan Elimination
    for (int j = 0; j < n; j++)
    {
        if (a[j][j] == 0)
        {
            cout << "Error: Division by zero (pivot is zero)" << endl;
            return 1;
        }

        // Normalize the pivot row
        double pivot = a[j][j];
        for (int k = 0; k < 2 * n; k++)
        {
            a[j][k] /= pivot;
        }

        // Eliminate other rows
        for (int i = 0; i < n; i++)
        {
            if (i != j)
            {
                double ratio = a[i][j];
                for (int k = 0; k < 2 * n; k++)
                {
                    a[i][k] -= ratio * a[j][k];
                }
            }
        }
    }

    // Output the inverse matrix
    cout << "The inverse matrix is:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j < 2 * n; j++)
        {
            if (a[i][j] >= 0) cout << " ";
            printf("%.2f ", a[i][j]);
        }
        cout << endl;
    }

    return 0;
}
