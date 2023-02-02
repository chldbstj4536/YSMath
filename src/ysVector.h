#pragma once

#include <cmath>
#include <exception>
#include <ysDefine.h>

namespace YS::Math
{
    bool IsZero(Float f) { return std::fabsf(f) <= FLT_EPSILON; }

    class Vector2;
    class Vector3;

    using Point3 = Vector3;
    using Point2 = Vector2;

    //-------------------------------------------
    // Vector2
    //-------------------------------------------
    inline Vector2 operator-(Vector2 const &v);
    inline Vector2 operator+(Vector2 const &v1, Vector2 const &v2);
    inline Vector2 operator-(Vector2 const &v1, Vector2 const &v2);
    inline Vector2 operator*(Float s, Vector2 const &v);
    inline Vector2 operator/(Vector2 const &v, Float s);

    struct Vector2
    {
        Vector2() = default;
        Vector2(Float _x, Float _y) : x(_x), y(_y) {}
        
        Vector2(Vector2 const &v) = default;
        Vector2(Vector2 &&v) = default;

        Vector2& operator=(Vector2 const &v) = default;
        Vector2& operator=(Vector2 &&v) = default;

        ~Vector2() = default;

        Vector2& operator+=(Vector2 const &v) { return *this = *this + v; }
        Vector2& operator-=(Vector2 const &v) { return *this = *this - v; }
        Vector2& operator*=(Float s) { return *this = s * *this; }
        Vector2& operator/=(Float s) { return *this = *this / s; }
        operator Vector3() const;

        Float LengthSquared() const { return x*x + y*y; }
        Float Length() const { return std::sqrtf(LengthSquared()); }
        Vector2& Normalize();
        Float Dot(const Vector2 &other) const { return x*other.x + y*other.y; }

        static Float LengthSquared(Vector2 const &v) { return v.LengthSquared(); }
        static Float Length(Vector2 const &v) { return v.Length(); }
        static Vector2 Normalize(Vector2 const &v) { return Vector2(v).Normalize(); }
        static Float Dot(const Vector2 &v1, const Vector2 &v2) { return v1.Dot(v2); }
        Float x, y;
    };

    #pragma region Vector2 Implementation
    inline Vector2 operator-(Vector2 const &v)
    {
        return Vector2(-v.x, -v.y);
    }
    inline Vector2 operator+(Vector2 const &v1, Vector2 const &v2)
    {
        return Vector2(v1.x + v2.x, v1.y + v2.y);
    }
    inline Vector2 operator-(Vector2 const &v1, Vector2 const &v2)
    {
        return v1 + -v2;
    }
    inline Vector2 operator*(Float s, Vector2 const &v)
    {
        return Vector2(s * v.x, s * v.y);
    }
    inline Vector2 operator/(Vector2 const &v, Float s)
    {
        return Vector2(v.x / s, v.y / s);
    }
    Vector2& Vector2::Normalize()
    {
        Float d = Length();

        if (IsZero(d))
            throw new std::exception("ZeroVector can't normalize");
        
        x = x / Length();
        y = y / Length();

        return *this;
    }
    #pragma endregion

    //-------------------------------------------
    // Vector 3
    //-------------------------------------------
    inline Vector3 operator-(Vector3 const &v);
    inline Vector3 operator+(Vector3 const &v1, Vector3 const &v2);
    inline Vector3 operator-(Vector3 const &v1, Vector3 const &v2);
    inline Vector3 operator*(Float s, Vector3 const &v);
    inline Vector3 operator/(Vector3 const &v, Float s);

    struct Vector3
    {
        Vector3() = default;
        Vector3(Float _x, Float _y, Float _z) : x(_x), y(_y), z(_z) {}

        Vector3(Vector3 const &v) = default;
        Vector3(Vector3 &&v) = default;
        
        Vector3& operator=(Vector3 const &v) = default;
        Vector3& operator=(Vector3 &&v) = default;

        ~Vector3() = default;

        Vector3& operator+=(Vector3 const &v) { return *this = *this + v; }
        Vector3& operator-=(Vector3 const &v) { return *this = *this - v; }
        Vector3& operator*=(Float s) { return *this = s * *this; }
        Vector3& operator/=(Float s) { return *this = *this / s; }
        operator Vector2() const;

        Float LengthSquared() const { return x*x + y*y + z*z; }
        Float Length() const { return std::sqrtf(LengthSquared()); }
        Vector3& Normalize();
        Float Dot(Vector3 const &v) const { return x*v.x + y*v.y + z*v.z; }
        Vector3 Cross(Vector3 const &v) const { return Vector3(y*v.z - v.y*z, z*v.x - v.z*x, x*v.y - v.x*y); }

        static Float LengthSquared(Vector3 const &v) { return v.LengthSquared(); }
        static Float Length(Vector3 const &v) { return v.Length(); }
        static Vector3 Normalize(Vector3 const &v) { return Vector3(v).Normalize(); }
        static Float Dot(Vector3 const &v1, Vector3 const &v2) { return v1.Dot(v2); }
        static Vector3 Cross(Vector3 const &v1, Vector3 const &v2) { return v1.Cross(v2); }

        Float x, y, z;
    };
    
    #pragma region Vector3 Implementation
    inline Vector3 operator-(Vector3 const &v)
    {
        return Vector3(-v.x, -v.y, -v.z);
    }
    inline Vector3 operator+(Vector3 const &v1, Vector3 const &v2)
    {
        return Vector3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
    }
    inline Vector3 operator-(Vector3 const &v1, Vector3 const &v2)
    {
        return v1 + -v2;
    }
    inline Vector3 operator*(Float s, Vector3 const &v)
    {
        return Vector3(s * v.x, s * v.y, s * v.z);
    }
    inline Vector3 operator/(Vector3 const &v, Float s)
    {
        return Vector3(v.x / s, v.y / s, v.z / s);
    }
    
    Vector3& Vector3::Normalize()
    {
        Float d = Length();

        if (IsZero(d))
            throw new std::exception("ZeroVector can't normalize");
        
        x = x / Length();
        y = y / Length();
        z = z / Length();

        return *this;
    }
    #pragma endregion

    #pragma region Vector4

    #pragma endregion

    inline Vector2::operator Vector3() const { return Vector3(x, y, 0.0f); }
    inline Vector3::operator Vector2() const { return Vector2(x, y); }

    #pragma region Utility Functions
    inline Float Distance(Vector2 const & v1, Vector2 const & v2) { return (v2 - v1).Length(); }
    inline Float Distance(Vector3 const & v1, Vector3 const & v2) { return (v2 - v1).Length(); }
    inline Float DistanceSquared(Vector2 const & v1, Vector2 const & v2) { return (v2 - v1).LengthSquared(); }
    inline Float DistanceSquared(Vector3 const & v1, Vector3 const & v2) { return (v2 - v1).LengthSquared(); }
    #pragma endregion
}