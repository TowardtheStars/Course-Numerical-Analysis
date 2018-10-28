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
    // 原始数据
    vector<double>
            data_x = {0.25, 0.50, 0.75, 1.00, 1.25, 1.50, 1.75, 2.00, 2.25, 2.50},
            data_y = {1.284,1.648,2.117,2.718,3.427,2.798,3.534,4.456,6.465,5.894};

    // 声明矩阵
    Mat A(data_x.size(), 2), ATA, ATY, Y(data_x.size(), 1), result;
    // 计算系数矩阵
    for (int i = 0; i < A.getRow(); ++i)
    {
        A[i][0] = sin(data_x[i]);
        A[i][1] = cos(data_x[i]);
        Y[i][0] = data_y[i];
    }
    // 计算A^T A 和 A^T Y
    ATA = Mat::dot(Mat::transpose(A), A);
    ATY = Mat::dot(Mat::transpose(A), Y);
    // 解方程组得到结果
    result = solveLinear(ATA, ATY);

    // 输出结果
    double a = result[0][0], b = result[1][0], sum = 0.0, temp;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    // 计算均方误差
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