/**
 * @file ysVector.hpp
 * @author 최윤서 (choicoco1995@naver.com)
 * @brief Implementation vector class
 * @version 0.1
 * @date 2023-06-22
 * 
 * @copyright Copyright (c) 2023 최윤서. All rights reserved.
 */
#pragma once

#include <cmath>
#include <exception>
#include <format>
#include <ysDefine.hpp>

namespace YS::Math
{
    inline bool IsZero(Float f) { return std::fabs(f) < FLT_EPSILON; }

    struct Vector2;
    struct Vector3;
    struct Vector4;

    inline Vector2 operator-(Vector2 const &v1, Vector2 const &v2) noexcept;
    /**
     * @brief Vector in 2-Dimensional
     */
    struct Vector2
    {
        Vector2() = default;
        Vector2(Vector2 const &v) = default;
        Vector2(Vector2 &&v) = default;
        ~Vector2() = default;
        Vector2& operator=(Vector2 const &v) = default;
        Vector2& operator=(Vector2 &&v) = default;

        Vector2(Float x, Float y) noexcept : x(x), y(y) {}

        Vector2& operator+=(Vector2 const &v) noexcept          { x += v.x; y += v.y; return *this; }
        Vector2& operator-=(Vector2 const &v) noexcept          { x -= v.x; y -= v.y; return *this; }
        Vector2& operator*=(Float k) noexcept                   { x *= k; y *= k; return *this; }
        Vector2& operator/=(Float k) throw(division_by_zero)    { if (IsZero(k)) throw division_by_zero(); x /= k; y /= k; return *this; }
        bool operator==(Vector2 const &v) const noexcept        { return fabs(x - v.x) < FLT_EPSILON && fabs(y - v.y) < FLT_EPSILON; }
        bool operator!=(Vector2 const &v) const noexcept        { return !(*this == v); }
        operator Vector3() const noexcept;
        operator Vector4() const noexcept;

        /**
         * @brief 벡터 길이의 제곱을 구한다
         * 
         * 루트 연산을 안하므로 Length() 함수보다 비용이 적다
         * 
         * @return Float 벡터 길이의 제곱
         */
        Float LengthSquared() const noexcept { return x * x + y * y; }
        /**
         * @brief 벡터 길이를 구한다
         * 
         * 루트 연산이 추가로 필요하다
         * 정밀한 벡터길이가 필요한 것이 아니라면
         * LengthSquared() 함수를 사용하는 것이 성능향상에 도움이 될 수 있다
         * 
         * @return Float 벡터 길이의 제곱
         */
        Float Length() const noexcept { return std::sqrtf(LengthSquared()); }
        /**
         * @brief 다른 벡터와의 거리의 제곱을 구한다
         * 
         * @param v 거리를 구할 대상
         * @return Float v와의 거리의 제곱
         */
        Float DistanceSquared(Vector2 const &v) const noexcept { return (*this - v).LengthSquared(); }
        /**
         * @brief 다른 벡터와의 거리를 구한다
         * 
         * @param v 거리를 구할 대상
         * @return Float v와의 거리
         */
        Float Distance(Vector2 const &v) const noexcept { return (*this - v).Length(); }
        /**
         * @brief 벡터의 내적 연산
         * 
         * @param v 내적을 수행할 대상
         * @return Float v와의 내적 결과
         */
        Float Dot(Vector2 const &v) const noexcept { return x * v.x + y * v.y; }
        /**
         * @brief 벡터를 정규화 한다
         * 
         * @return Vector2& 정규화된 자기 자신을 돌려준다
         */
        Vector2& Normalize() throw(division_by_zero);

        static Float    LengthSquared(Vector2 const &v) noexcept                        { return v.LengthSquared(); }
        static Float    Length(Vector2 const &v) noexcept                               { return v.Length(); }
        static Float    DistanceSquared(Vector2 const &v1, Vector2 const &v2) noexcept  { return v1.DistanceSquared(v2); }
        static Float    Distance(Vector2 const &v1, Vector2 const &v2) noexcept         { return v1.Distance(v2); }
        static Vector2  Normalize(Vector2 const &v) throw(division_by_zero)             { return Vector2(v).Normalize(); }
        static Float    Dot(const Vector2 &v1, const Vector2 &v2) noexcept              { return v1.Dot(v2); }

        Float x, y;
    };
    inline Vector2 operator-(Vector2 const &v) noexcept                             { return Vector2(-v.x, -v.y); }
    inline Vector2 operator+(Vector2 const &v1, Vector2 const &v2) noexcept         { return Vector2(v1.x + v2.x, v1.y + v2.y); }
    inline Vector2 operator-(Vector2 const &v1, Vector2 const &v2) noexcept         { return v1 + -v2; }
    inline Vector2 operator*(Float k, Vector2 const &v) noexcept                    { return Vector2(k * v.x, k * v.y); }
    inline Vector2 operator/(Vector2 const &v, Float k) throw(division_by_zero)     { if (IsZero(k)) throw division_by_zero(); return Vector2(v.x / k, v.y / k); }


    inline Vector3 operator-(Vector3 const &v1, Vector3 const &v2) noexcept;
    /**
     * @brief Vector in 3-Dimensional
     */
    struct Vector3
    {
        Vector3() = default;
        Vector3(Vector3 const &v) = default;
        Vector3(Vector3 &&v) = default;
        ~Vector3() = default;
        Vector3& operator=(Vector3 const &v) = default;
        Vector3& operator=(Vector3 &&v) = default;

        Vector3(Float x, Float y, Float z) noexcept : x(x), y(y), z(z) {}

        Vector3& operator+=(Vector3 const &v) noexcept          { x += v.x; y += v.y; z += v.z; return *this; }
        Vector3& operator-=(Vector3 const &v) noexcept          { x -= v.x; y -= v.y; z -= v.z; return *this; }
        Vector3& operator*=(Float k) noexcept                   { x *= k; y *= k; z *= k; return *this; }
        Vector3& operator/=(Float k) throw(division_by_zero)    { if (IsZero(k)) throw division_by_zero(); x /= k; y /= k; z /= k; return *this; }
        bool operator==(Vector3 const &v) const noexcept        { return fabs(x - v.x) < FLT_EPSILON && fabs(y - v.y) < FLT_EPSILON && fabs(z - v.z) < FLT_EPSILON; }
        bool operator!=(Vector3 const &v) const noexcept        { return !(*this == v); }
        operator Vector2() const noexcept;
        operator Vector4() const noexcept;

        Float LengthSquared() const noexcept                    { return x*x + y*y + z*z; }
        Float Length() const noexcept                           { return std::sqrtf(LengthSquared()); }
        Float DistanceSquared(Vector3 const &v) const noexcept  { return (*this - v).LengthSquared(); }
        Float Distance(Vector3 const &v) const noexcept         { return (*this - v).Length(); }
        Float Dot(Vector3 const &v) const noexcept              { return x*v.x + y*v.y + z*v.z; }
        Vector3 Cross(Vector3 const &v) const noexcept          { return Vector3(y*v.z - v.y*z, z*v.x - v.z*x, x*v.y - v.x*y); }
        Vector3& Normalize() throw(division_by_zero);

        static Float LengthSquared(Vector3 const &v) noexcept                           { return v.LengthSquared(); }
        static Float Length(Vector3 const &v) noexcept                                  { return v.Length(); }
        static Float DistanceSquared(Vector3 const &v1, Vector3 const &v2) noexcept     { return v1.DistanceSquared(v2); }
        static Float Distance(Vector3 const &v1, Vector3 const &v2) noexcept            { return v1.Distance(v2); }
        static Vector3 Normalize(Vector3 const &v) noexcept                             { return Vector3(v).Normalize(); }
        static Float Dot(Vector3 const &v1, Vector3 const &v2) noexcept                 { return v1.Dot(v2); }
        static Vector3 Cross(Vector3 const &v1, Vector3 const &v2) noexcept             { return v1.Cross(v2); }

        Float x, y, z;
    };
    inline Vector3 operator-(Vector3 const &v) noexcept                         { return Vector3(-v.x, -v.y, -v.z); }
    inline Vector3 operator+(Vector3 const &v1, Vector3 const &v2) noexcept     { return Vector3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z); }
    inline Vector3 operator-(Vector3 const &v1, Vector3 const &v2) noexcept     { return v1 + -v2; }
    inline Vector3 operator*(Float k, Vector3 const &v) noexcept                { return Vector3(k * v.x, k * v.y, k * v.z); }
    inline Vector3 operator/(Vector3 const &v, Float k) throw(division_by_zero) { if (IsZero(k)) throw division_by_zero(); return Vector3(v.x / k, v.y / k, v.z / k); }


    inline Vector4 operator-(Vector4 const &v1, Vector4 const &v2) noexcept;
    /**
     * @brief Vector in 4-Dimensional
     */
    struct Vector4
    {
        Vector4() = default;
        Vector4(Vector4 const &v) = default;
        Vector4(Vector4 &&v) = default;
        ~Vector4() = default;
        Vector4& operator=(Vector4 const &v) = default;
        Vector4& operator=(Vector4 &&v) = default;

        Vector4(Float x, Float y, Float z, Float w) noexcept : x(x), y(y), z(z), w(w) {}

        Vector4& operator+=(Vector4 const &v) noexcept          { x += v.x; y += v.y; z += v.z; w += v.w; return *this; }
        Vector4& operator-=(Vector4 const &v) noexcept          { x -= v.x; y -= v.y; z -= v.z; w -= v.w; return *this; }
        Vector4& operator*=(Float k) noexcept                   { x *= k; y *= k; z *= k; w *= k; return *this; }
        Vector4& operator/=(Float k) throw(division_by_zero)    { if (IsZero(k)) throw division_by_zero(); x /= k; y /= k; z /= k; w /= k; return *this; }
        bool operator==(Vector4 const &v) const noexcept        { return fabs(x - v.x) < FLT_EPSILON && fabs(y - v.y) < FLT_EPSILON && fabs(z - v.z) < FLT_EPSILON && fabs(w - v.w) < FLT_EPSILON; }
        bool operator!=(Vector4 const &v) const noexcept        { return !(*this == v); }
        operator Vector2() const noexcept;
        operator Vector3() const noexcept;

        Float LengthSquared() const noexcept                    { return x*x + y*y + z*z + w*w; }
        Float Length() const noexcept                           { return std::sqrtf(LengthSquared()); }
        Float DistanceSquared(Vector4 const &v) const noexcept  { return (*this - v).LengthSquared(); }
        Float Distance(Vector4 const &v) const noexcept         { return (*this - v).Length(); }
        Float Dot(Vector4 const &v) const noexcept              { return x*v.x + y*v.y + z*v.z + w*v.w; }
        Vector4& Normalize() throw(division_by_zero);

        static Float LengthSquared(Vector4 const &v) noexcept                           { return v.LengthSquared(); }
        static Float Length(Vector4 const &v) noexcept                                  { return v.Length(); }
        static Float DistanceSquared(Vector4 const & v1, Vector4 const & v2) noexcept   { return v1.DistanceSquared(v2); }
        static Float Distance(Vector4 const & v1, Vector4 const & v2) noexcept          { return v1.Distance(v2); }
        static Vector4 Normalize(Vector4 const &v) noexcept                             { return Vector4(v).Normalize(); }
        static Float Dot(Vector4 const &v1, Vector4 const &v2) noexcept                 { return v1.Dot(v2); }

        Float x, y, z, w;
    };
    inline Vector4 operator-(Vector4 const &v) noexcept                             { return Vector4(-v.x, -v.y, -v.z, -v.w); }
    inline Vector4 operator+(Vector4 const &v1, Vector4 const &v2) noexcept         { return Vector4(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w); }
    inline Vector4 operator-(Vector4 const &v1, Vector4 const &v2) noexcept         { return v1 + -v2; }
    inline Vector4 operator*(Float k, Vector4 const &v) noexcept                    { return Vector4(k * v.x, k * v.y, k * v.z, k * v.w); }
    inline Vector4 operator/(Vector4 const &v, Float k) throw(division_by_zero)     { if (IsZero(k)) throw division_by_zero(); return Vector4(v.x / k, v.y / k, v.z / k, v.w / k); }
}

template <>
struct std::formatter<YS::Math::Vector2> : std::formatter<YS::Float>
{
    std::format_context::iterator format(YS::Math::Vector2 const &v, std::format_context &format_ctx);
};
template <>
struct std::formatter<YS::Math::Vector3> : std::formatter<YS::Float>
{
    std::format_context::iterator format(YS::Math::Vector3 const &v, std::format_context &format_ctx);
};
template <>
struct std::formatter<YS::Math::Vector4> : std::formatter<YS::Float>
{
    std::format_context::iterator format(YS::Math::Vector4 const &v, std::format_context &format_ctx);
};