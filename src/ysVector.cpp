#include "../inc/ysVector.hpp"

#define _YS_MATH_BEGIN namespace YS::Math {
#define _YS_MATH_END }

_YS_MATH_BEGIN
Vector2::operator Vector3() noexcept { return Vector3(0, 0, 0); }
Vector2::operator Vector4() noexcept { return Vector4(x, y, 0, 0); }
Vector2& Vector2::Normalize() throw(division_by_zero)
{
    Float d = Length();
    if (IsZero(d))
        throw division_by_zero();

    x = x / Length();
    y = y / Length();

    return *this;
}

Vector3::operator Vector2() { return Vector2(x, y); }
Vector3::operator Vector4() { return Vector4(x, y, z, 0); }
Vector3& Vector3::Normalize() throw(division_by_zero)
{
    Float d = Length();
    if (IsZero(d))
        throw division_by_zero();

    x = x / Length();
    y = y / Length();
    z = z / Length();

    return *this;
}

Vector4::operator Vector2() { return Vector2(x, y); }
Vector4::operator Vector3() { return Vector3(x, y, z); }
Vector4& Vector4::Normalize() throw(division_by_zero)
{
    Float d = Length();
    if (IsZero(d))
        throw division_by_zero();

    x = x / Length();
    y = y / Length();
    z = z / Length();
    w = w / Length();

    return *this;
}
_YS_MATH_END