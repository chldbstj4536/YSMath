/**
 * @file ysMatrix.cpp
 * @author 최윤서 (choicoco1995@naver.com)
 * @brief Implementation matrix class
 * @version 0.1
 * @date 2023-06-22
 * 
 * @copyright Copyright (c) 2023 최윤서. All rights reserved.
 */
#include "../inc/ysMatrix.hpp"

#define _YS_MATH_BEGIN namespace YS::Math {
#define _YS_MATH_END }

_YS_MATH_BEGIN
const Matrix3x3 Matrix3x3::Identity{1, 0, 0, 0, 1, 0, 0, 0, 1};
Float Matrix3x3::Det() const noexcept
{
    return data[0] * data[4] * data[8] +
           data[1] * data[5] * data[6] +
           data[2] * data[3] * data[7] -
           data[0] * data[5] * data[7] -
           data[1] * data[3] * data[8] -
           data[2] * data[4] * data[6];
}
Matrix3x3 Matrix3x3::Adjoint() const noexcept
{
    Matrix3x3 m;
    m.data[0] = data[4] * data[8] - data[5] * data[7];
    m.data[3] = data[5] * data[6] - data[3] * data[8];
    m.data[6] = data[3] * data[7] - data[4] * data[6];
    m.data[1] = data[2] * data[7] - data[1] * data[8];
    m.data[4] = data[0] * data[8] - data[2] * data[6];
    m.data[7] = data[1] * data[0] - data[0] * data[7];
    m.data[2] = data[1] * data[5] - data[2] * data[4];
    m.data[5] = data[2] * data[3] - data[0] * data[5];
    m.data[8] = data[0] * data[4] - data[1] * data[3];
    return m;
}

Matrix3x3 operator*(Matrix3x3 const &m1, Matrix3x3 const &m2) noexcept
{
    Matrix3x3 result{0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (UInt i = 0; i < 3; ++i)
        for (UInt j = 0; j < 3; ++j)
            for (UInt k = 0; k < 3; ++k)
                result.data[3 * i + k] += m1.data[3 * i + j] * m2.data[3 * j + k];
    return result;
}
Vector3 operator*(Matrix3x3 const &m, Vector3 const &v) noexcept
{
    Vector3 result;
    result.x = m.data[0] * v.x + m.data[1] * v.y + m.data[2] * v.z;
    result.y = m.data[3] * v.x + m.data[4] * v.y + m.data[5] * v.z;
    result.z = m.data[6] * v.x + m.data[7] * v.y + m.data[8] * v.z;
    return result;
}
_YS_MATH_END