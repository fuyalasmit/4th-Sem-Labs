#include <iostream>
#include <cmath>
using namespace std;

void matrixMultiplication(double A[3][3], double Xi[3][1], double Xf[3][1]) {
    for (int i = 0; i < 3; i++) {
        Xf[i][0] = 0;  
        for (int j = 0; j < 3; j++) {
            Xf[i][0] += A[i][j] * Xi[j][0];
        }
    }
}

double findMaximum(double X[3][1]) {
    double max = fabs(X[0][0]);
    for (int i = 1; i < 3; i++) {
        if (fabs(X[i][0]) > max) {
            max = fabs(X[i][0]);
        }
    }
    return max;
}

bool findDifference(double X1[3][1], double X2[3][1]) {
    double tolerance = 0.001;
    for (int i = 0; i < 3; i++) {
        if (fabs(X1[i][0] - X2[i][0]) > tolerance) {
            return false;
        }
    }
    return true;
}

int main() {
    // double A[3][3] = {
    //     {2, 5, 1}, 
    //     {5, -2, 3}, 
    //     {1, 3, 10}
    // };
    // double A[3][3] = {
    //     {3, 2, 3}, 
    //     {2, 4, 6}, 
    //     {3, 6, 9}
    // };
    double A[3][3] = {
        {-2.1, 11, -5}, 
        {-2, 14.9, -7}, 
        {-4, 26, -12.1}
    };
    
    

    double X0[3][1] = {{1}, {1}, {1}};
    double X1[3][1];

    double lambda = 0;
    int maxIterations = 100;
    int iteration = 0;

    while (iteration < maxIterations) {
        iteration++;

        matrixMultiplication(A, X0, X1);

        lambda = findMaximum(X1);

        for (int i = 0; i < 3; i++) {
            X1[i][0] /= lambda;
        }

        if (findDifference(X0, X1)) {
            break;
        }

        for (int i = 0; i < 3; i++) {
            X0[i][0] = X1[i][0];
        }
    }

    cout << "Eigenvalue: " << lambda << endl;
    cout << "Eigenvector: " << endl;
    for (int i = 0; i < 3; i++) {
        cout << X1[i][0] << endl;
    }

    return 0;
}