//
// Created by TowardsTheStars on 2018/9/11.
//

#ifndef NUMERICALANALYSIS_CRITERIA_H
#define NUMERICALANALYSIS_CRITERIA_H

#include <cmath>
#include <functional>
#include "error_type.h"

typedef std::function<bool(double, double)> CRITERIA_TERMINATE_UPDATE;

CRITERIA_TERMINATE_UPDATE getCriteriaUpdate(ErrorType, double);

bool __criteria_update_absolute(double, double, double);
bool __criteria_update_fractional(double, double, double);


#endif //NUMERICALANALYSIS_CRITERIA_H
