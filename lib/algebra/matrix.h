//
// Created by TowardsTheStars on 2018/10/28.
//

#ifndef NUMERICALANALYSIS_MATRIX_H
#define NUMERICALANALYSIS_MATRIX_H

#include <vector>
#include <exception>

using namespace std;
class Mat
{
    size_t row=0, col=0;
public:
    size_t getRow() const;

    size_t getCol() const;

protected:
    vector<vector<double>> data;
public:
    Mat() = default;
    Mat(size_t row, size_t col);

    vector<double>& operator[](size_t id);

    static Mat dot(const Mat&, const Mat&);

    double det() const;

    static Mat transpose(const Mat &);

    Mat&operator=(const Mat &);
};

Mat solveLinear(const Mat& coeff, const Mat& y);

#endif //NUMERICALANALYSIS_MATRIX_H
