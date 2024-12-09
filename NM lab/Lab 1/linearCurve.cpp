#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter how many data you want to enter:";
    cin >> n;

    double *arrayX = new double[n];
    double *arrayY = new double[n];

    cout << "Enter data for x and y in order, seperated by space:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arrayX[i];
        cin >> arrayY[i];
    }

    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;

    for (int i = 0; i < n; i++)
    {
        sumX += arrayX[i];
        sumY += arrayY[i];
        sumXY += arrayX[i] * arrayY[i];
        sumX2 += arrayX[i] * arrayX[i];
    }

    double determinant = n * sumX2 - sumX * sumX;

    if (determinant == 0)
    {
        cout << "Unexpected Value";
        return 1;
    }

    double determinantMatrixA = sumX2 * sumY - sumX * sumXY;
    double determinantMatrixB = n * sumXY - sumX * sumY;

    double a = determinantMatrixA / determinant;
    double b = determinantMatrixB / determinant;

    if (b < 0)
    {
        cout << a << "-" << b << "x";
    }
    else
    {
        cout << a << "+" << b << "x";
    }
    delete[] arrayX;
    delete[] arrayY;

    return 0;
}

// Pseudocode
// Input Data:
//  Read n (number of points).
//  Read x[i], y[i] for all i
// Initialize variables sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0.
// Calculate sumX,sumY,sumXY,sumX2 by iterating i from 0 to n-1
// Calculate Parameters:
//  determinant = n * sumX2 - sumX * sumX
//  determinantMatrixA = sumX2 * sumY - sumX * sumXY
//  determinantMatrixB = n * sumXY - sumX * sumY
//  a = determinantMatrixA / determinant
//  b = determinantMatrixB / determinant
// If b<0:
//  Print a-bx.
// Else:
//  Print a+bx.