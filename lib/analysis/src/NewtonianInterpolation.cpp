//
// Created by TowardsTheStars on 2018/9/8.
//

#include "../NewtonianInterpolation.h"
using namespace std;
double NewtonianInterpolation::difference(vector<tuple<double, double>> pointList)
{
    size_t n = pointList.size();
    if (n > 2)
    {
        vector<tuple<double, double>> listPre(n-1), listAft(n-1);
        copy_n(&pointList[1], n-1, listAft.begin());
        copy_n(&pointList[0], n-1, listPre.begin());
        return (difference(listAft) - difference(listPre))/(get<0>(pointList[n-1]) - get<0>(pointList[0]));

    }else if(n == 2)
    {
        return (get<1>(pointList[1]) - get<1>(pointList[0]))/(get<0>(pointList[1]) - get<0>(pointList[0]));
    } else
    {
        throw out_of_range("too less points!");
    }
}

NewtonianInterpolation::NewtonianInterpolation() {}

NewtonianInterpolation::NewtonianInterpolation(vector<tuple<double, double>>& points)
{
    addPointList(points);
}

double NewtonianInterpolation::operator()(double x)
{
    size_t size = pList.size();
    double result = get<1>(pList[0]);
    double temp = 1.0;
    if (size < 2)
        return 0;
    for (int i = 0; i < size; ++i) {
        temp *= x - get<0>(pList[i]);
        result += diffChart[i] * temp;
    }
    return result;
}

void NewtonianInterpolation::addPointList(vector<tuple<double, double>> & points)
{
    size_t n = points.size();
    size_t size = pList.size();
    pList.resize(n + size);
    /* make point list */
    for (int i = 0; i < n; ++i) {
        pList[i + size] = points[i];
    }
    makeChart();

}

void NewtonianInterpolation::makeChart()
{
    size_t n = pList.size();
    size_t i = diffChart.size();
    diffChart.resize(n, 0.0);
    vector<tuple<double,double>> temp(i);
    if(i!=0)
        copy(&pList[0], &pList[i], temp.begin());
    else {
        temp.resize(1);
        temp[0] = pList[0];
        i = 1;
    }
    for (; i < n; ++i) {
        temp.push_back(pList[i]);
        diffChart[i - 1] = difference(temp);
    }
}