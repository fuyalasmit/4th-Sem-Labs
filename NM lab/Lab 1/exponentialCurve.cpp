#include <iostream>
#include<cmath>
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
        arrayY[i] = log(arrayY[i]);
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
    double a = exp(determinantMatrixA / determinant);
    double b = determinantMatrixB / determinant;

    cout<<"y="<<a<<"e^("<<b<<"x)";
    delete[] arrayX;
    delete[] arrayY;

    return 0;
}

//Pseudocode
// Input Data:
//  Read n (number of points).
//  Read x[i], y[i] for all i, and replace y[i] with ln(y[i]).
// Calculate sumX,sumY,sumXY,sumX2 by iterating i from 0 to n-1
// Compute determinant=n * sumX2 - sumX^2 & Exit if determinant==0.
// Calculate Parameters:
//  determinantMatrixA = sumX2 * sumY - sumX * sumXY
//  determinantMatrixB = n * sumXY - sumX * sumY
//  a = e^((sumX2 * sumY - sumX * sumXY) / determinant)
//  b = (n * sumXY - sumX * sumY) / determinant
// Print y = a * e^(b * x)
