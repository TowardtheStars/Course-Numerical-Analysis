//
// Created by TowardsTheStars on 2018/9/7.
//

#ifndef NUMERICALANALYSIS_INTERPOLAION_H
#define NUMERICALANALYSIS_INTERPOLAION_H

#include <functional>
#include <vector>
using namespace std;

function<double (double)> lagrange_interpolation(vector<tuple<double, double>>&);

#include "NewtonianInterpolation.h"

#endif //NUMERICALANALYSIS_INTERPOLAION_H
