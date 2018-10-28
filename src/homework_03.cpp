//
// Created by TowardsTheStars on 2018/10/28.
//
#include <vector>
#include <cmath>
#include <iostream>
#include "../lib/algebra/matrix.h"

using namespace std;
int main()
{
    vector<double>
            data_x = {0.25, 0.50, 0.75, 1.00, 1.25, 1.50, 1.75, 2.00, 2.25, 2.50},
            data_y = {1.284,1.648,2.117,2.718,3.427,2.798,3.534,4.456,6.465,5.894};

    Mat A(data_x.size(), 2), ATA, ATY, Y(data_x.size(), 1);
    for (int i = 0; i < A.getRow(); ++i)
    {
        A[i][0] = sin(data_x[i]);
        A[i][1] = cos(data_x[i]);
        Y[i][0] = data_y[i];
    }
    ATA = Mat::dot(Mat::transpose(A), A);
    ATY = Mat::dot(Mat::transpose(A), Y);
//    for (int i = 0; i < ATY.getRow(); ++i)
//    {
//        for (int j = 0; j < ATY.getCol(); ++j)
//        {
//            cout << ATY[i][j]<<',';
//        }
//        cout<<endl;
//    }
    cout << ATY.getRow() << endl;

    return 0;
}