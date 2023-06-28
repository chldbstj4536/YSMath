/**
 * @file ysQuaternion.hpp
 * @author 최윤서 (choicoco1995@naver.com)
 * @brief Implementation quaternion class
 * @version 0.1
 * @date 2023-06-27
 * 
 * @copyright Copyright (c) 2023 최윤서. All rights reserved.
 */
#pragma once

#include <ysDefine.hpp>
#include "ysVector.hpp"

namespace YS::Math
{
    struct Quaternion
    {
    public:
        Quaternion() = default;
        Quaternion(Quaternion const &) = default;
        Quaternion(Quaternion &&) = default;
        ~Quaternion() = default;
        Quaternion& operator=(Quaternion const &) = default;
        Quaternion& operator=(Quaternion &&) = default;

        Quaternion(Float w, Vector3 const &v) noexcept : w(w), v(v) {}

        Quaternion& operator+=(Quaternion const &q) noexcept    { w += q.w; v += q.v; return *this; }
        Quaternion& operator-=(Quaternion const &q) noexcept    { w -= q.w; v -= q.v; return *this; }
        Quaternion& operator*=(Quaternion const &q) noexcept;
        Quaternion& operator*=(Float k) noexcept                { w *= k; v *= k; return *this; }
        bool        operator==(Quaternion const &q) noexcept    { return std::fabs(w - q.w) < FLT_EPSILON && v == q.v; }
        bool        operator!=(Quaternion const &q) noexcept    { return !(*this == q); }

        Quaternion& Conjugate() noexcept                { v = -v; return *this; }
        Float       Length() const noexcept             { return w*w + v.Dot(v); }
        Quaternion& Normalize() throw(division_by_zero);
        Quaternion& Inverse() throw(division_by_zero);

        static Quaternion   Conjugate(Quaternion const &q) noexcept                 { return Quaternion(q).Conjugate(); }
        static Float        Length(Quaternion const &q) noexcept                    { return q.Length(); }
        static Quaternion   Normalize(Quaternion const &q) throw(division_by_zero)  { return Quaternion(q).Normalize(); }
        static Quaternion   Inverse(Quaternion const &q) throw(division_by_zero)    { return Quaternion(q).Inverse(); }

    public:
        Float w;
        Vector3 v;
    };
    inline Quaternion operator+(Quaternion const &lhs, Quaternion const &rhs) noexcept  { return Quaternion(lhs.w + rhs.w, lhs.v + rhs.v); }
    inline Quaternion operator-(Quaternion const &lhs, Quaternion const &rhs) noexcept  { return Quaternion(lhs.w - rhs.w, lhs.v - rhs.v); }
    inline Quaternion operator*(Quaternion const &lhs, Quaternion const &rhs) noexcept  { return Quaternion(lhs.w*rhs.w - Vector3::Dot(lhs.v, rhs.v), rhs.w*lhs.v + lhs.w*rhs.v + Vector3::Cross(lhs.v, rhs.v)); }
    inline Quaternion operator*(Float k, Quaternion const &q) noexcept                  { return Quaternion(k * q.w, k * q.v); }
    Vector3 operator*(Vector3 const &v, Quaternion const &q) throw(division_by_zero);
}

template<>
struct std::formatter<YS::Math::Quaternion> : std::formatter<YS::Float>
{
    std::format_context::iterator format(YS::Math::Quaternion const &q, std::format_context &format_ctx);
};