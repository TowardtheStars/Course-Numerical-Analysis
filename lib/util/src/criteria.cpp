//
// Created by TowardsTheStars on 2018/9/11.
//

#include "../criteria.h"


CRITERIA_TERMINATE_UPDATE getCriteriaUpdate(ErrorType type, double param)
{
    if (param > 0.0)
        switch (type) {
            case ABSOLUTE:
                return std::bind(__criteria_update_absolute,
                        std::placeholders::_1, std::placeholders::_2, param / 10);
            case FRACTIONAL:
                if (param >= 1.0)
                    return std::bind(__criteria_update_fractional,
                                     std::placeholders::_1, std::placeholders::_2, param / 10);
                else
                    throw new std::out_of_range("You have selected FRACTIONAL, so are you expecting a result with an error bigger than itself?");
            case EFFECTIVE_DIGITS:
                if (floor(param) == param)
                    return std::bind(__criteria_update_fractional,
                                     std::placeholders::_1, std::placeholders::_2,
                                     5 * pow(10, -param - 1) / 10);
                else
                    throw new std::out_of_range("You have selected EFFECTIVE_DIGITS, so please input an integer into errorParam!");
            default:
                throw new std::out_of_range("Your ErrorType is not listed in the enumeration, it must be magical!");
        }
    else
        throw new std::out_of_range("errorParam cannot be negative!");
}

bool __criteria_update_absolute(double newValue, double oldValue, double param)
{
    return abs(newValue - oldValue) < param;
}
bool __criteria_update_fractional(double newValue, double oldValue, double param)
{
    return abs(newValue - oldValue) / abs(oldValue) < param;
}