//
// Created by TowardsTheStars on 2018/10/4.
//

#include <iostream>
#include <functional>
#include <cmath>
#include <fstream>
#include "../lib/analysis/interpolaion.h"

using namespace std;

double f(double x)
{
    return 1.0 / (1.0 + x * x);
}

double sampX1(int i, int n)
{
    return -5.0 + 10.0 * i / n;
}

double sampX2(int i, int n)
{
    return -5 * cos((2 * i + 1) * M_PI / (2 * n + 2));
}


vector<tuple<double, double>> genSamp(const function<double(double)>& f, const function<double(int, int)>& xGen, int n)
{
    double x;
    vector<tuple<double, double>> result;
    for (int i = 0; i <= n; ++i)
    {
        x = xGen(i, n);
        result.emplace_back(make_tuple(x, f(x)));
    }

    return result;
}

double getMaxNormError(const function<double(double)>& f,
        const NewtonianInterpolation& L,
        const function<double(int, int)>& xGen,
        int n)
{
    double x = xGen(0, n);
    double result = fabs(f(x) - L(x)), temp;
    for (int i = 1; i <= n; ++i)
    {
        x = xGen(i, n);
        temp = fabs(f(x) - L(x));
        result = result < temp? temp : result;
    }
    return result;
}

int main()
{


    unsigned n[] = {5, 10, 20, 40};
    NewtonianInterpolation re1, re2;
    for (int i = 0; i < 4; ++i)
    {
        re1.addPointList(genSamp(f, sampX1, n[i]));
        re2.addPointList(genSamp(f, sampX2, n[i]));
        cout << n[i] << '\t' << getMaxNormError(f, re1, sampX1, 500) <<
        '\t' << getMaxNormError(f, re2, sampX1, 500) << endl;
        re1.clear();
        re2.clear();
    }

    return 0;
}