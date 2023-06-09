#pragma once

#include <cmath>
#include <exception>
#include <ysDefine.hpp>

namespace YS::Math
{
    bool IsZero(Float f) { return std::fabsf(f) <= FLT_EPSILON; }

    class Vector2;
    class Vector3;
    class Vector4;

    using Point3 = Vector3;
    using Point2 = Vector2;

    //-------------------------------------------
    // Vector2
    //-------------------------------------------
    inline Vector2 operator-(Vector2 const &v);
    inline Vector2 operator+(Vector2 const &v1, Vector2 const &v2);
    inline Vector2 operator-(Vector2 const &v1, Vector2 const &v2);
    inline Vector2 operator*(Float s, Vector2 const &v);
    inline Vector2 operator/(Vector2 const &v, Float s) throw(division_by_zero);

    struct Vector2
    {
        Vector2() = default;
        Vector2(Vector2 const &v) = default;
        Vector2(Vector2 &&v) = default;
        ~Vector2() = default;
        Vector2& operator=(Vector2 const &v) = default;
        Vector2& operator=(Vector2 &&v) = default;

        Vector2(Float _x, Float _y) : x(_x), y(_y) {}
        
        Vector2& operator+=(Vector2 const &v) { return *this = *this + v; }
        Vector2& operator-=(Vector2 const &v) { return *this = *this - v; }
        Vector2& operator*=(Float s) { return *this = s * *this; }
        Vector2& operator/=(Float s) throw(division_by_zero) { return *this = *this / s; }
        operator Vector3();

        Float LengthSquared() const { return x*x + y*y; }
        Float Length() const { return std::sqrtf(LengthSquared()); }
        Vector2& Normalize() throw(division_by_zero)
        {
            Float d = Length();
            if (IsZero(d)) throw division_by_zero();

            x = x / Length();
            y = y / Length();

            return *this;
        }
        Float Dot(const Vector2 &other) const { return x*other.x + y*other.y; }

        static Float LengthSquared(Vector2 const &v) { return v.LengthSquared(); }
        static Float Length(Vector2 const &v) { return v.Length(); }
        static Vector2 Normalize(Vector2 const &v) throw(division_by_zero) { return Vector2(v).Normalize(); }
        static Float Dot(const Vector2 &v1, const Vector2 &v2) { return v1.Dot(v2); }

        Float x, y;
    };
    #pragma region Vector2 Implementation
    inline Vector2 operator-(Vector2 const &v) { return Vector2(-v.x, -v.y); }
    inline Vector2 operator+(Vector2 const &v1, Vector2 const &v2) { return Vector2(v1.x + v2.x, v1.y + v2.y); }
    inline Vector2 operator-(Vector2 const &v1, Vector2 const &v2) { return v1 + -v2; }
    inline Vector2 operator*(Float s, Vector2 const &v) { return Vector2(s * v.x, s * v.y); }
    inline Vector2 operator/(Vector2 const &v, Float s) { if (IsZero(s)) throw division_by_zero(); return Vector2(v.x / s, v.y / s); }
    #pragma endregion

    //-------------------------------------------
    // Vector 3
    //-------------------------------------------
    inline Vector3 operator-(Vector3 const &v);
    inline Vector3 operator+(Vector3 const &v1, Vector3 const &v2);
    inline Vector3 operator-(Vector3 const &v1, Vector3 const &v2);
    inline Vector3 operator*(Float s, Vector3 const &v);
    inline Vector3 operator/(Vector3 const &v, Float s) throw(division_by_zero);

    struct Vector3
    {
        Vector3() = default;
        Vector3(Vector3 const &v) = default;
        Vector3(Vector3 &&v) = default;
        ~Vector3() = default;
        Vector3& operator=(Vector3 const &v) = default;
        Vector3& operator=(Vector3 &&v) = default;

        Vector3(Float _x, Float _y, Float _z) : x(_x), y(_y), z(_z) {}

        Vector3& operator+=(Vector3 const &v) { return *this = *this + v; }
        Vector3& operator-=(Vector3 const &v) { return *this = *this - v; }
        Vector3& operator*=(Float s) { return *this = s * *this; }
        Vector3& operator/=(Float s) throw(division_by_zero) { return *this = *this / s; }
        operator Vector2();

        Float LengthSquared() const { return x*x + y*y + z*z; }
        Float Length() const { return std::sqrtf(LengthSquared()); }
        Vector3& Normalize() throw(division_by_zero)
        {
            Float d = Length();
            if (IsZero(d)) throw division_by_zero();
            
            x = x / Length();
            y = y / Length();
            z = z / Length();

            return *this;
        }
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
    inline Vector3 operator-(Vector3 const &v) { return Vector3(-v.x, -v.y, -v.z); }
    inline Vector3 operator+(Vector3 const &v1, Vector3 const &v2) { return Vector3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z); }
    inline Vector3 operator-(Vector3 const &v1, Vector3 const &v2) { return v1 + -v2; }
    inline Vector3 operator*(Float s, Vector3 const &v) { return Vector3(s * v.x, s * v.y, s * v.z); }
    inline Vector3 operator/(Vector3 const &v, Float s) { if (IsZero(s)) throw division_by_zero(); return Vector3(v.x / s, v.y / s, v.z / s); }
    #pragma endregion

    //-------------------------------------------
    // Vector 4
    //-------------------------------------------
    inline Vector4 operator-(Vector4 const &v);
    inline Vector4 operator+(Vector4 const &v1, Vector4 const &v2);
    inline Vector4 operator-(Vector4 const &v1, Vector4 const &v2);
    inline Vector4 operator*(Float s, Vector4 const &v);
    inline Vector4 operator/(Vector4 const &v, Float s) throw(division_by_zero);

    struct Vector4
    {
        Vector4() = default;
        Vector4(Vector4 const &v) = default;
        Vector4(Vector4 &&v) = default;
        ~Vector4() = default;
        Vector4& operator=(Vector4 const &v) = default;
        Vector4& operator=(Vector4 &&v) = default;

        Vector4(Float _x, Float _y, Float _z, Float _w) : x(_x), y(_y), z(_z), w(_w) { }

        Vector4& operator+=(Vector4 const &v) { return *this = *this + v; }
        Vector4& operator-=(Vector4 const &v) { return *this = *this - v; }
        Vector4& operator*=(Float s) { return *this = s * *this; }
        Vector4& operator/=(Float s) throw(division_by_zero) { return *this = *this / s; }

        Float LengthSquared() const { return x*x + y*y + z*z + w*w; }
        Float Length() const { return std::sqrtf(LengthSquared()); }
        Vector4& Normalize() throw(division_by_zero)
        {
            Float d = Length();
            if (IsZero(d)) throw division_by_zero();
            
            x = x / Length();
            y = y / Length();
            z = z / Length();
            w = w / Length();

            return *this;
        }
        Float Dot(Vector4 const &v) const { return x*v.x + y*v.y + z*v.z + w*v.w; }

        static Float LengthSquared(Vector4 const &v) { return v.LengthSquared(); }
        static Float Length(Vector4 const &v) { return v.Length(); }
        static Vector4 Normalize(Vector4 const &v) { return Vector4(v).Normalize(); }
        static Float Dot(Vector4 const &v1, Vector4 const &v2) { return v1.Dot(v2); }

        Float x, y, z, w;
    };
    
    #pragma region Vector4 Implementation
    inline Vector4 operator-(Vector4 const &v) { return Vector4(-v.x, -v.y, -v.z, -v.w); }
    inline Vector4 operator+(Vector4 const &v1, Vector4 const &v2) { return Vector4(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w); }
    inline Vector4 operator-(Vector4 const &v1, Vector4 const &v2) { return v1 + -v2; }
    inline Vector4 operator*(Float s, Vector4 const &v) { return Vector4(s * v.x, s * v.y, s * v.z, s * v.w); }
    inline Vector4 operator/(Vector4 const &v, Float s) { if (IsZero(s)) throw division_by_zero(); return Vector4(v.x / s, v.y / s, v.z / s, v.w / s); }
    #pragma endregion

    #pragma region Utility Functions
    inline Float Distance(Vector2 const & v1, Vector2 const & v2) { return (v2 - v1).Length(); }
    inline Float Distance(Vector3 const & v1, Vector3 const & v2) { return (v2 - v1).Length(); }
    inline Float Distance(Vector4 const & v1, Vector4 const & v2) { return (v2 - v1).Length(); }
    inline Float DistanceSquared(Vector2 const & v1, Vector2 const & v2) { return (v2 - v1).LengthSquared(); }
    inline Float DistanceSquared(Vector3 const & v1, Vector3 const & v2) { return (v2 - v1).LengthSquared(); }
    inline Float DistanceSquared(Vector4 const & v1, Vector4 const & v2) { return (v2 - v1).LengthSquared(); }
    #pragma endregion
}