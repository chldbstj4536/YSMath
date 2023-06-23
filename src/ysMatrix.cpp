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
Matrix3x3& Matrix3x3::Transpose() noexcept
{
    for (UInt8 i = 0; i < 3; ++i)
    {
        for (UInt8 j = 0; j < 3; ++j)
        {
            if (i == j)
                continue;
            std::swap(data[3 * i + j], data[3 * j + i]);
        }
    }
    return *this;
}

Matrix3x3 operator*(Matrix3x3 const &m1, Matrix3x3 const &m2) noexcept
{
    Matrix3x3 result{0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (UInt8 i = 0; i < 3; ++i)
        for (UInt8 j = 0; j < 3; ++j)
            for (UInt8 k = 0; k < 3; ++k)
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