//
// Created by TowardsTheStars on 2018/10/28.
//
#include <vector>
#include <cmath>
#include <iostream>
#include "../lib/algebra/matrix.h"

using namespace std;

void displayMat(Mat& result)
{
    for (int i = 0; i < result.getRow(); ++i)
    {
        for (int j = 0; j < result.getCol(); ++j)
        {
            cout << result[i][j]<<',';
        }
        cout<<endl;
    }
}

int main()
{
    vector<double>
            data_x = {0.25, 0.50, 0.75, 1.00, 1.25, 1.50, 1.75, 2.00, 2.25, 2.50},
            data_y = {1.284,1.648,2.117,2.718,3.427,2.798,3.534,4.456,6.465,5.894};

    Mat A(data_x.size(), 2), ATA, ATY, Y(data_x.size(), 1), result;
    for (int i = 0; i < A.getRow(); ++i)
    {
        A[i][0] = sin(data_x[i]);
        A[i][1] = cos(data_x[i]);
        Y[i][0] = data_y[i];
    }
    ATA = Mat::dot(Mat::transpose(A), A);
    ATY = Mat::dot(Mat::transpose(A), Y);
    result = solveLinear(ATA, ATY);

    double a = result[0][0], b = result[1][0], sum = 0.0, temp;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    for (int i = 0; i < data_x.size(); ++i)
    {
        temp = a * sin(data_x[i]) + b * cos(data_x[i]) - data_y[i];
        temp *= temp;
        sum += temp;
    }
    sum /= data_x.size();
    cout << "均方误差 = " << sum << endl;
    return 0;
}