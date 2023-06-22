/**
 * @file ysVector.cpp
 * @author 최윤서 (choicoco1995@naver.com)
 * @brief Implementation vector class
 * @version 0.1
 * @date 2023-06-22
 * 
 * @copyright Copyright (c) 2023 최윤서. All rights reserved.
 */
#include "../inc/ysVector.hpp"

#define _YS_MATH_BEGIN namespace YS::Math {
#define _YS_MATH_END }

_YS_MATH_BEGIN
Vector2::operator Vector3() const noexcept { return Vector3(0, 0, 0); }
Vector2::operator Vector4() const noexcept { return Vector4(x, y, 0, 0); }
Vector2& Vector2::Normalize() throw(division_by_zero)
{
    Float length = Length();
    if (IsZero(length))
        throw division_by_zero();

    x = x / length;
    y = y / length;

    return *this;
}

Vector3::operator Vector2() const noexcept { return Vector2(x, y); }
Vector3::operator Vector4() const noexcept { return Vector4(x, y, z, 0); }
Vector3& Vector3::Normalize() throw(division_by_zero)
{
    Float length = Length();
    if (IsZero(length))
        throw division_by_zero();

    x = x / length;
    y = y / length;
    z = z / length;

    return *this;
}

Vector4::operator Vector2() const noexcept { return Vector2(x, y); }
Vector4::operator Vector3() const noexcept { return Vector3(x, y, z); }
Vector4& Vector4::Normalize() throw(division_by_zero)
{
    Float length = Length();
    if (IsZero(length))
        throw division_by_zero();

    x = x / length;
    y = y / length;
    z = z / length;
    w = w / length;

    return *this;
}
_YS_MATH_END