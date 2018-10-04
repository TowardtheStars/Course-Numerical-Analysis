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
    vector<double> xList, yList, diffChart;
    void makeChart();
public:
    NewtonianInterpolation() = default;
    explicit NewtonianInterpolation(vector<tuple<double,double>>&);

    double operator()(double) const;

    void addPointList(const vector<tuple<double, double>>&);              //core

    static double difference(vector<tuple<double, double>> pointList);

    void clear();
};


#endif //NUMERICALANALYSIS_NEWTONIANINTERPOLATION_H
