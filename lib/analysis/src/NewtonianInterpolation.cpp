//
// Created by TowardsTheStars on 2018/9/8.
//

#include "../NewtonianInterpolation.h"
using namespace std;


NewtonianInterpolation::NewtonianInterpolation(vector<tuple<double, double>>& points)
{
    addPointList(points);
}

double NewtonianInterpolation::operator()(double x) const
{
    size_t size = xList.size();
    double result;
    double temp = 1.0;
    if (size < 2)
        return 0;
    result = yList[0];
    for (int i = 0; i < size - 1; ++i) {
        temp *= x - xList[i];
        result += diffChart[i + 1] * temp;
    }
    return result;
}

void NewtonianInterpolation::addPointList(const vector<tuple<double, double>> & points)
{
    size_t n = points.size();
    size_t size = xList.size();
    xList.resize(n + size);
    yList.resize(n + size);
    /* make point list */
    for (int i = 0; i < n; ++i) {
        xList[i + size] = get<0>(points[i]);
        yList[i + size] = get<1>(points[i]);
    }
    makeChart();

}

void NewtonianInterpolation::makeChart()
{
    diffChart = yList;
    size_t n;
    if (diffChart.empty())
        return;
    else
        n = diffChart.size() - 1;
    for (size_t i = 1; i <= n; ++i)
    {
        for (size_t j = n; j >= i; --j)
        {
            diffChart[j] = (diffChart[j] - diffChart[j - 1]) / (xList[j] - xList[j - i]);
        }
    }
}

void NewtonianInterpolation::clear()
{
    xList.clear();
    yList.clear();
    diffChart.clear();
}



