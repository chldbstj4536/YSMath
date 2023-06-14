#pragma once

#include <cmath>
#include <exception>
#include <ysDefine.hpp>

namespace YS::Math
{
    bool IsZero(Float f) { return std::fabsf(f) <= FLT_EPSILON; }

    struct Vector2;
    struct Vector3;
    struct Vector4;

    //-------------------------------------------
    // Vector2
    //-------------------------------------------
    inline Vector2 operator-(Vector2 const &v) noexcept;
    inline Vector2 operator+(Vector2 const &v1, Vector2 const &v2) noexcept;
    inline Vector2 operator-(Vector2 const &v1, Vector2 const &v2) noexcept;
    inline Vector2 operator*(Float s, Vector2 const &v) noexcept;
    inline Vector2 operator/(Vector2 const &v, Float s) throw(division_by_zero);

    struct Vector2
    {
        Vector2() = default;
        Vector2(Vector2 const &v) = default;
        Vector2(Vector2 &&v) = default;
        ~Vector2() = default;
        Vector2& operator=(Vector2 const &v) = default;
        Vector2& operator=(Vector2 &&v) = default;

        Vector2(Float x, Float y) noexcept : x(x), y(y) {}
        
        Vector2& operator+=(Vector2 const &v) noexcept                              { return *this = *this + v; }
        Vector2& operator-=(Vector2 const &v) noexcept                              { return *this = *this - v; }
        Vector2& operator*=(Float s) noexcept                                       { return *this = s * *this; }
        Vector2& operator/=(Float s) throw(division_by_zero)                        { return *this = *this / s; }
        operator YS::Math::Vector3() noexcept;
        operator Vector4() noexcept;

        Float           LengthSquared() const noexcept                              { return x*x + y*y; }
        Float           Length() const noexcept                                     { return std::sqrtf(LengthSquared()); }
        Float           DistanceSquared(Vector2 const &v) const noexcept            { return (*this - v).LengthSquared(); }
        Float           Distance(Vector2 const &v) const noexcept            { return (*this - v).Length(); }
        Float           Dot(const Vector2 &other) const noexcept                    { return x*other.x + y*other.y; }
        Vector2&        Normalize() throw(division_by_zero);

        static Float    LengthSquared(Vector2 const &v) noexcept                        { return v.LengthSquared(); }
        static Float    Length(Vector2 const &v) noexcept                               { return v.Length(); }
        static Float    DistanceSquared(Vector2 const &v1, Vector2 const &v2) noexcept  { return v1.DistanceSquared(v2); }
        static Float    Distance(Vector2 const &v1, Vector2 const &v2) noexcept         { return v1.Distance(v2); }
        static Vector2  Normalize(Vector2 const &v) throw(division_by_zero)             { return Vector2(v).Normalize(); }
        static Float    Dot(const Vector2 &v1, const Vector2 &v2) noexcept              { return v1.Dot(v2); }

        Float x, y;
    };
    #pragma region Vector2_Implementation
    inline Vector2 operator-(Vector2 const &v) noexcept                             { return Vector2(-v.x, -v.y); }
    inline Vector2 operator+(Vector2 const &v1, Vector2 const &v2) noexcept         { return Vector2(v1.x + v2.x, v1.y + v2.y); }
    inline Vector2 operator-(Vector2 const &v1, Vector2 const &v2) noexcept         { return v1 + -v2; }
    inline Vector2 operator*(Float s, Vector2 const &v) noexcept                    { return Vector2(s * v.x, s * v.y); }
    inline Vector2 operator/(Vector2 const &v, Float s) throw(division_by_zero)     { if (IsZero(s)) throw division_by_zero(); return Vector2(v.x / s, v.y / s); }
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

        Vector3(Float x, Float y, Float z) : x(x), y(y), z(z) {}

        Vector3& operator+=(Vector3 const &v) { return *this = *this + v; }
        Vector3& operator-=(Vector3 const &v) { return *this = *this - v; }
        Vector3& operator*=(Float s) { return *this = s * *this; }
        Vector3& operator/=(Float s) throw(division_by_zero) { return *this = *this / s; }
        operator Vector2();
        operator Vector4();

        Float LengthSquared() const { return x*x + y*y + z*z; }
        Float Length() const { return std::sqrtf(LengthSquared()); }
        Vector3& Normalize() throw(division_by_zero);
        Float Dot(Vector3 const &v) const { return x*v.x + y*v.y + z*v.z; }
        Vector3 Cross(Vector3 const &v) const { return Vector3(y*v.z - v.y*z, z*v.x - v.z*x, x*v.y - v.x*y); }

        static Float LengthSquared(Vector3 const &v) { return v.LengthSquared(); }
        static Float Length(Vector3 const &v) { return v.Length(); }
        static Vector3 Normalize(Vector3 const &v) { return Vector3(v).Normalize(); }
        static Float Dot(Vector3 const &v1, Vector3 const &v2) { return v1.Dot(v2); }
        static Vector3 Cross(Vector3 const &v1, Vector3 const &v2) { return v1.Cross(v2); }

        Float x, y, z;
    };
    
    #pragma region Vector3_Implementation
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

        Vector4(Float x, Float y, Float z, Float w) : x(x), y(y), z(z), w(w) {}

        Vector4& operator+=(Vector4 const &v) { return *this = *this + v; }
        Vector4& operator-=(Vector4 const &v) { return *this = *this - v; }
        Vector4& operator*=(Float s) { return *this = s * *this; }
        Vector4& operator/=(Float s) throw(division_by_zero) { return *this = *this / s; }
        operator Vector2();
        operator Vector3();

        Float LengthSquared() const { return x*x + y*y + z*z + w*w; }
        Float Length() const { return std::sqrtf(LengthSquared()); }
        Vector4& Normalize() throw(division_by_zero);
        Float Dot(Vector4 const &v) const { return x*v.x + y*v.y + z*v.z + w*v.w; }

        static Float LengthSquared(Vector4 const &v) { return v.LengthSquared(); }
        static Float Length(Vector4 const &v) { return v.Length(); }
        static Vector4 Normalize(Vector4 const &v) { return Vector4(v).Normalize(); }
        static Float Dot(Vector4 const &v1, Vector4 const &v2) { return v1.Dot(v2); }

        Float x, y, z, w;
    };
    
    #pragma region Vector4_Implementation
    inline Vector4 operator-(Vector4 const &v) { return Vector4(-v.x, -v.y, -v.z, -v.w); }
    inline Vector4 operator+(Vector4 const &v1, Vector4 const &v2) { return Vector4(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w); }
    inline Vector4 operator-(Vector4 const &v1, Vector4 const &v2) { return v1 + -v2; }
    inline Vector4 operator*(Float s, Vector4 const &v) { return Vector4(s * v.x, s * v.y, s * v.z, s * v.w); }
    inline Vector4 operator/(Vector4 const &v, Float s) { if (IsZero(s)) throw division_by_zero(); return Vector4(v.x / s, v.y / s, v.z / s, v.w / s); }
    #pragma endregion

    #pragma region Utility_Functions
    inline Float Distance(Vector3 const & v1, Vector3 const & v2) { return (v2 - v1).Length(); }
    inline Float Distance(Vector4 const & v1, Vector4 const & v2) { return (v2 - v1).Length(); }
    inline Float DistanceSquared(Vector3 const & v1, Vector3 const & v2) { return (v2 - v1).LengthSquared(); }
    inline Float DistanceSquared(Vector4 const & v1, Vector4 const & v2) { return (v2 - v1).LengthSquared(); }
    #pragma endregion
}