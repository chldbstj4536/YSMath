/**
 * @file ysMatrix.hpp
 * @author 최윤서 (choicoco1995@naver.com)
 * @brief Implementation matrix class
 * @version 0.1
 * @date 2023-06-22
 * 
 * @copyright Copyright (c) 2023 최윤서. All rights reserved.
 */
#pragma once
#include <format>
#include <ysDefine.hpp>
#include "ysVector.hpp"

namespace YS::Math
{
    class invertible_matrix : public std::exception { };

    class Matrix3x3;
    Matrix3x3 operator*(Matrix3x3 const &m1, Matrix3x3 const &m2) noexcept;
    inline Matrix3x3 operator*(Float k, Matrix3x3 const &m) noexcept;

    class Matrix3x3
    {
    public:
/// @cond
        Matrix3x3() = default;
        Matrix3x3(Matrix3x3 const &) = default;
        Matrix3x3(Matrix3x3 &&) = default;
        ~Matrix3x3() = default;
        Matrix3x3& operator=(Matrix3x3 const &) = default;
        Matrix3x3& operator=(Matrix3x3 &&) = default;
/// @endcond

        /**
         * @brief 행렬의 모든 요소를 입력받아 초기화해주는 Matrix3x3 생성자
         */
        Matrix3x3(Float _00, Float _01, Float _02,
                  Float _10, Float _11, Float _12,
                  Float _20, Float _21, Float _22) noexcept
        : data{ _00, _01, _02,
                _10, _11, _12,
                _20, _21, _22} { }

        /**
         * @brief 행렬의 열벡터들을 입력받아 초기화해주는 Matrix3x3 생성자
         */
        Matrix3x3(Vector3 const &_c0, Vector3 const &_c1, Vector3 const &_c2) noexcept
        : data{ _c0.x, _c1.x, _c2.x,
                _c0.y, _c1.y, _c2.y,
                _c0.z, _c1.z, _c2.z,} { }

        Matrix3x3& operator+=(Matrix3x3 const &m) noexcept
        {
            for (UInt i = 0; i < 9; ++i)
                data[i] += m.data[i];
            return *this;
        }
        Matrix3x3& operator-=(Matrix3x3 const &m) noexcept
        {
            for (UInt i = 0; i < 9; ++i)
                data[i] -= m.data[i];
            return *this;
        }
        Matrix3x3& operator*=(Matrix3x3 const &m) noexcept { return *this = *this * m; }
        Matrix3x3& operator*=(Float k) noexcept
        {
            for (UInt i = 0; i < 9; ++i)
                data[i] *= k;
            return *this;
        }
        bool operator==(Matrix3x3 const &m) const noexcept
        {
            for (UInt i = 0; i < 9; ++i)
                if (fabs(data[i] - m.data[i]) >= FLT_EPSILON)
                    return false;
            return true;
        }
        bool operator!=(Matrix3x3 const &m) const noexcept { return !(*this == m); }

        Float GetAt(UInt rowIndex, UInt colIndex) const
        {
            // rowIndex, colIndex 세너티 체크 필요
            return data[3 * rowIndex + colIndex];
        }
        void SetAt(UInt rowIndex, UInt colIndex, Float setData)
        {
            // rowIndex, colIndex 세너티 체크 필요
            data[3 * rowIndex + colIndex] = setData;
        }
        Matrix3x3& Transpose() noexcept
        {
            for (UInt i = 0; i < 3; ++i)
                for (UInt j = i + 1; j < 3; ++j)
                    std::swap(data[3 * i + j], data[3 * j + i]);
            return *this;
        }
        Float Det() const noexcept;
        Matrix3x3 Adjoint() const noexcept;
        bool IsInvertible() const noexcept                  { return !IsZero(Det()); }
        Matrix3x3 Inverse() const throw(invertible_matrix)  { if (!IsInvertible()) throw invertible_matrix(); return (1 / Det()) * Adjoint(); }

        static Matrix3x3 Transpose(Matrix3x3 const &m) noexcept
        {
            Matrix3x3 result = m;
            return result.Transpose();
        }
        static Float Det(Matrix3x3 const &m) noexcept                           { return m.Det(); }
        static Matrix3x3 Adjoint(Matrix3x3 const &m) noexcept                   { return m.Adjoint(); }
        static bool IsInvertible(Matrix3x3 const &m) noexcept                   { return m.IsInvertible(); }
        static Matrix3x3 Inverse(Matrix3x3 const &m) throw(invertible_matrix)   { if (!m.IsInvertible()) throw invertible_matrix(); return m.Inverse(); }

        static const Matrix3x3 Identity;
    
    public:
        Float data[9];
    };

    inline Matrix3x3 operator+(Matrix3x3 const &m1, Matrix3x3 const &m2) noexcept
    {
        Matrix3x3 result;
        for (UInt8 i = 0; i < 9; ++i)
            result.data[i] = m1.data[i] + m2.data[i];
        return result;
    }
    inline Matrix3x3 operator-(Matrix3x3 const &m1, Matrix3x3 const &m2) noexcept
    {
        Matrix3x3 result;
        for (UInt8 i = 0; i < 9; ++i)
            result.data[i] = m1.data[i] - m2.data[i];
        return result;
    }
    inline Matrix3x3 operator*(Float k, Matrix3x3 const &m) noexcept
    {
        Matrix3x3 result = m;
        return result *= k;
    }
    Vector3 operator*(Matrix3x3 const &m, Vector3 const &v) noexcept;
}
template <>
struct std::formatter<YS::Math::Matrix3x3> : std::formatter<YS::Math::Vector3>
{
    auto format(YS::Math::Matrix3x3 const &m, std::format_context &format_ctx)
    {
        auto out = format_ctx.out();
        out = std::format_to(out, "{{");
        out = std::formatter<YS::Math::Vector3>::format(YS::Math::Vector3{m.data[0], m.data[1], m.data[2]}, format_ctx);
        out = std::format_to(out, " ");
        out = std::formatter<YS::Math::Vector3>::format(YS::Math::Vector3{m.data[3], m.data[4], m.data[5]}, format_ctx);
        out = std::format_to(out, " ");
        out = std::formatter<YS::Math::Vector3>::format(YS::Math::Vector3{m.data[6], m.data[7], m.data[8]}, format_ctx);
        return std::format_to(out, "}}");
    }
};