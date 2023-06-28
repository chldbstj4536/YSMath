/**
 * @file ysQuaternion.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-27
 * 
 * @copyright Copyright (c) 2023
 */
#include "../inc/ysQuaternion.hpp"

#define _YS_MATH_BEGIN namespace YS::Math {
#define _YS_MATH_END }

_YS_MATH_BEGIN
Quaternion& YS::Math::Quaternion::operator*=(Quaternion const &q) noexcept
{
    w = w * q.w - Vector3::Dot(v, q.v);
    v = q.w*v + w*q.v + Vector3::Cross(v, q.v);
    return *this;
}
Vector3 YS::Math::operator*(Vector3 const &v, Quaternion const &q) throw(division_by_zero)
{
    Quaternion nq = Quaternion::Normalize(q);
    Quaternion vq{0, v};
    vq = nq * vq * Quaternion::Inverse(nq);
    return vq.v;
}
Quaternion& YS::Math::Quaternion::Normalize()
{
    Float length = Length();
    if (std::fabs(length - 1.0f) < FLT_EPSILON)
        return *this;
    
    if (std::fabs(length) < FLT_EPSILON)
        throw division_by_zero();
    
    *this *= (1 / std::sqrtf(length));
    return *this;
}
Quaternion& YS::Math::Quaternion::Inverse()
{
    if (IsZero(Length()))
        throw division_by_zero();

    Conjugate();
    *this *= 1 / Length();
    return *this;
}
_YS_MATH_END

std::format_context::iterator std::formatter<YS::Math::Quaternion>::format(YS::Math::Quaternion const &q, std::format_context &format_ctx)
{
    auto out = format_ctx.out();
    out = std::format_to(out, "{{ ");
    out = std::formatter<float>::format(q.w, format_ctx);
    out = std::format_to(out, " {{ ");
    out = std::formatter<float>::format(q.v.x, format_ctx);
    out = std::format_to(out, "i ");
    out = std::formatter<float>::format(q.v.y, format_ctx);
    out = std::format_to(out, "j ");
    out = std::formatter<float>::format(q.v.z, format_ctx);
    return std::format_to(out, "k }} }}");
}