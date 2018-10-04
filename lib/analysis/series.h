//
// Created by TowardsTheStars on 2018/9/7.
//

#ifndef NUMERICALANALYSIS_SERIES_H
#define NUMERICALANALYSIS_SERIES_H

#include <functional>
#include <math.h>
#include <exception>
#include "../util/error_type.h"
#include "../util/criteria.h"

using namespace std;

/**
 * A function that calculates functional series with error limits provided
 *
 * @tparam varType
 *              type of variants
 * @param func
 *              functional term with an integer parameter, iteration starts from 0
 * @param var
 *              this is a function series, so put your variant here
 * @param errorType
 *              error type you want to have
 * @param errorParam
 *              a positive number varies with the errorType you selected above:
 *                  for ABSOLUTE:
 *                      an absolute error limit;
 *                  for FRACTIONAL:
 *                      an fractional error limit, must be under 1.0;
 *                  for EFFECTIVE_DIGITS:
 *                      an integer indicating how many effective digits you want;
 *
 *              but remember, the more accurate result you want, the more time you will need.
 * @return a returnType result of the calculation
 */
template <typename varType>
double series(function<double(varType, int)> func, varType var,
              ErrorType errorType, double errorParam);

/**
 * A function that calculates functional series with error limits provided
 *
 * @param func
 *              term with an integer parameter, iteration starts from 0
 * @param errorType
 *              error type you want to have
 * @param errorParam
 *              a positive number varies with the errorType you selected above:
 *                  for ABSOLUTE:
 *                      an absolute error limit;
 *                  for FRACTIONAL:
 *                      an fractional error limit, must be under 1.0;
 *                  for EFFECTIVE_DIGITS:
 *                      an integer indicating how many effective digits you want;
 *
 *              but remember, the more accurate result you want, the more time you will need.
 * @return a returnType result of the calculation
 */
double numericSeries(function<double(int)> term,
                     ErrorType type, double errorParam);

double __numeric_series_abso(function<double(int)> term, double errorabs);
double __numeric_series_frac(function<double(int)> term, double errorfrac);





template<typename varType>
double series(function<double(varType, int)> func, varType var,
              ErrorType errorType, double errorParam) {
    return numericSeries(bind(func, var, placeholders::_1), errorType, errorParam);
}
#endif //NUMERICALANALYSIS_SERIES_H
