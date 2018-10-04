//
// Created by TowardsTheStars on 2018/9/7.
//

#include "../series.h"


using namespace std;

double numericSeries(function<double(int)> term,
                     ErrorType type, double errorParam) {
    if (errorParam > 0.0)
        switch (type) {
            case ABSOLUTE:
                return __numeric_series_abso(term, errorParam / 10);
            case FRACTIONAL:
                if (errorParam >= 1.0)
                    return __numeric_series_frac(term, errorParam / 10);
                else
                    throw new out_of_range("You have selected FRACTIONAL, so are you expecting a result with an error bigger than itself?");
            case EFFECTIVE_DIGITS:
                if (floor(errorParam) == errorParam)
                    return __numeric_series_frac(term, 5 * pow(10, -errorParam - 1) / 10);
                else
                    throw new out_of_range("You have selected EFFECTIVE_DIGITS, so please input an integer into errorParam!");
            default:
                throw new out_of_range("Your ErrorType is not listed in the enumeration, it must be magical!");
        }
    else
        throw new out_of_range("errorParam cannot be negative!");
}

double __numeric_series_abso(function<double(int)> term, double errorabs) {
    double result = 0.0;
    double t;
    int i = 0;
    for (i = 0, t = term(0); errorabs <= abs(t) * i|| i == 0; ++i) {
        t = term(i);
        result += t;
    }
    return result;
}

double __numeric_series_frac(function<double(int)> term, double errorfrac) {
    double result = 0.0;
    double t;
    int i = 0;
    for (i = 0, t = term(0); errorfrac * result <= abs(t) || i == 0; ++i) {
        t = term(i);
        result += t;
    }
    return result;
}
