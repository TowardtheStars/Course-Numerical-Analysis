//
// Created by TowardsTheStars on 2018/10/28.
//

#include "../matrix.h"

size_t Mat::getRow() const
{
    return row;
}

size_t Mat::getCol() const
{
    return col;
}

Mat::Mat(size_t row, size_t col)
{
    this->row = row;
    this->col = col;
    data.resize(row);
    for (int i = 0; i < row; ++i)
    {
        data[i].resize(col);
        for (int j = 0; j < col; ++j)
        {
            data[i][j] = 0;
        }
    }
}

/**
 * 返回行向量
 * @param id
 * @return
 */
vector<double> &Mat::operator[](size_t id)
{
    return data[id];
}

Mat Mat::dot(const Mat & l, const Mat & r)
{
    if (l.col == r.row)
    {
        Mat result(l.row, r.col);
        for (int i = 0; i < result.getRow(); ++i)
        {
            for (int j = 0; j < result.getCol(); ++j)
            {
                result.data[i][j] = 0;
                for (int k = 0; k < l.getCol(); ++k)
                {
                    result.data[i][j] += l.data[i][k] * r.data[k][j];
                }
            }
        }
        return result;
    }
    else
    {
        throw out_of_range("Multiplication of Matrices. But # of rows and # of cols don't match!");
    }
}

double Mat::det() const
{
    if (col == row)
    {
        if (col == 1)
        {
            return data[0][0];
        }
        else if (col == 2)
        {
            return data[0][0] * data[1][1] - data[0][1] * data[1][0];
        }
        else
        {
            double result = 0.0;
            Mat temp(row - 1, col - 1);

            for (int i = 0; i < col; ++i)
            {
                for (int j = 1; j < row; ++j)
                {
                    for (int k = 0; k < i; ++k)
                    {
                        temp.data[j - 1][k] = data[j][k];
                    }
                    for (int k = i + 1; k < col; ++k)
                    {
                        temp.data[j - 1][k - 1] = data[j][k];
                    }
                }
                result += data[0][i] * (i % 2 * 2 - 1) * temp.det();
            }
            return result;
        }
    } else
    {
        return 0;
    }
}

Mat Mat::transpose(const Mat &obj)
{
    Mat result(obj.getCol(), obj.getRow());
    for (int i = 0; i < obj.getRow(); ++i)
    {
        for (int j = 0; j < obj.getCol(); ++j)
        {
            result.data[j][i] = obj.data[i][j];
        }
    }
    return result;
}

Mat &Mat::operator=(const Mat & obj)
{
    col = obj.col;
    row = obj.row;
    data.resize(row);
    for (int i = 0; i < row; ++i)
    {
        data[i].resize(col);
        for (int j = 0; j < col; ++j)
        {
            data[i][j] = obj.data[i][j];
        }
    }
    return (*this);
}
