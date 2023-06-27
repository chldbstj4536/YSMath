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
        Quaternion& operator=(Quaterion const &) = default;
        Quaternion& operator=(Quaterion &&) = default;

        Quaternion(Float w, Vector3 v) noexcept : w(w), v(v) {}

        Quaternion& operator+=(Quaternion const &q) { w += q.w; v += q.v; return *this; }
        Quaternion& operator-=(Quaternion const &q) { w -= q.w; v -= q.v; return *this; }
        bool operator==(Quaternion const &q) { return std::fabs(w - q.w) < FLT_EPSILON && v == q.v; }
        bool operator!=(Quaternion const &q) { return !(*this == q); }

    public:
        Float w;
        Vector3 v;
    };
    inline Quaternion operator+(Quaterion const &lhs, Quaternion const &rhs) { return Quaternion(lhs.w + rhs.w, lhs.v + rhs.v); }
    inline Quaternion operator-(Quaterion const &lhs, Quaternion const &rhs) { return Quaternion(lhs.w - rhs.w, lhs.v - rhs.v); }
    inline Quaternion operator*(Quaternion const &lhs, Quaternion const &rhs) { return Quaternion(lhs.w*rhs.w - Vector3::Dot(lhs.v, rhs.v), rhs.w*lhs.v + lhs.w*rhs.v + Vector3::Cross(lhs.v, rhs.v)); }
    inline Quaternion operator*(Float k, Quaternion const &q) { return Quaternion(k * q.w, k * q.v); }
}