//
// Created by TowardsTheStars on 2018/9/8.
//

#ifndef NUMERICALANALYSIS_NEWTONIANINTERPOLATION_H
#define NUMERICALANALYSIS_NEWTONIANINTERPOLATION_H

#include <functional>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
class NewtonianInterpolation{

protected:
    vector<tuple<double, double>> pList;
    vector<double> diffChart;
    void makeChart();
public:
    NewtonianInterpolation();
    explicit NewtonianInterpolation(vector<tuple<double,double>>&);

    double operator()(double);

    void addPoint(tuple<double, double>);                           //converter
    void addPoint(double, double);                                  //converter
    void addPointList(vector<tuple<double, double>>&);              //core
    void addPointList(initializer_list<initializer_list<double>>);  //converter

    static double difference(vector<tuple<double, double>> pointList);

};


#endif //NUMERICALANALYSIS_NEWTONIANINTERPOLATION_H
