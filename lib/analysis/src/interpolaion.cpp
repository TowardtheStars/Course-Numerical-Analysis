//
// Created by TowardsTheStars on 2018/9/7.
//

#include "../interpolaion.h"

function<double (double)> lagrange_interpolation(vector<tuple<double, double>>& pointList)
{
    size_t size = pointList.size();
    function<double (double)> result = [=](double x)
    {
        double re = 0;
        double temp;
        for (int i = 0; i < size; ++i) {
            temp = 1;
            for (int j = 0; j < i; ++j) {
                temp *= (x - get<0>(pointList[j])) / (get<0>(pointList[i]) - get<0>(pointList[j]));
            }
            for (int j = i + 1; j < size; ++j) {
                temp *= (x - get<0>(pointList[j])) / (get<0>(pointList[i]) - get<0>(pointList[j]));
            }
            re += temp * get<1>(pointList[i]);
        }
        return re;
    };
    return result;
}