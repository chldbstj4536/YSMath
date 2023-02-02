// #pragma once

// #include "fmathdef.h"
// #include <array>
// #include <initializer_list>
// #include <stdexcept>
// #include <iostream>

// namespace FJ::Math
// {
//     template <typename T>
//     concept DataType = requires(T x, T y, float s)
//     {
//         {-x} -> std::convertible_to<T>;
//         {x + y} -> std::convertible_to<T>;
//         {x += y} -> std::convertible_to<T>;
//         {x - y} -> std::convertible_to<T>;
//         {x -= y} -> std::convertible_to<T>;
//         {x * y} -> std::convertible_to<T>;
//         {s * x} -> std::convertible_to<T>;
//         {x * s} -> std::convertible_to<T>;
//     };

//     using SizeType = uint32;

//     template <SizeType _N = 3, SizeType _M = 3, DataType _Type = float>
//     struct Matrix
//     {
//         Matrix() : data() {}
//         Matrix(std::initializer_list<std::initializer_list<_Type>> m)
//         {
//             for (auto i = 0, col_iter = m.begin(); i < _N && col_iter != m.end(); ++i, ++col_iter)
//                 for (auto j = 0, row_iter = col_iter->begin(); j < _M && row_iter != col_iter->end(); ++j, ++row_iter)
//                     data[i][j] = (*row_iter);
//         }
//         Matrix(Matrix const &) = default;
//         Matrix(Matrix &&) = default;
//         ~Matrix() = default;

//         Matrix& operator=(Matrix const &) = default;
//         Matrix& operator=(Matrix &&) = default;

//         Matrix& operator+=(Matrix const &m) { *this = *this + m; return *this; }
//         Matrix& operator-=(Matrix const &m) { *this = *this - m; return *this; }
//         Matrix& operator*=(float s) { *this = s * *this; return *this; }
//         template <SizeType _COL>
//         Matrix& operator*=(Matrix<_M, _COL, _Type> const &m) { *this = *this * m; return *this; }


//         template<SizeType _ROW, SizeType _COL>
//         requires (_ROW < _N && _COL < _M)
//         _Type& At() const noexcept { return data[_ROW][_COL]; }
//         _Type At(SizeType _row, SizeType _col) const { if (_row >= _N || _col >= _M) throw std::out_of_range(); return data[_row][_col]; }
//         _Type& At(SizeType _row, SizeType _col) { if (_row >= _N || _col >= _M) throw std::out_of_range(); return data[_row][_col]; }

//         template<SizeType _R1, SizeType _R2>
//         void RowExchange() { if (_R1 == _R2) return; data[_R1].swap(data[_R2]); }
//         void RowExchange(SizeType r1, SizeType r2) { if (r1 == r2) return; data[r1].swap(data[r2]); }
//         template<SizeType _C1, SizeType _C2>
//         void ColumnExchange()
//         {
//             if (_C1 == _C2) return;
//             for (int i = 0; i < _N; ++i)
//                 swap(data[i][_C1], data[i][_C2]);
//         }
//         void ColumnExchange(uint32 c1, uint32 c2)
//         {
//             if (c1 == c2)   return;
//             for (int i = 0; i < _N; ++i)
//                 std::swap(data[i][c1], data[i][c2]);
//         }
//         Matrix<_M, _N, _Type> GetTranspose() const
//         {
//             Matrix<_M, _N, _Type> t;
//             for (int i = 0; i < _M; ++i)
//                 for (int j = 0; j < _N; ++j)
//                     t.data[i][j] = data[j][i];
//             return t;
//         }
//         void Print(std::ostream& o)
//         {
//             for (int i = 0; i < _N; ++i)
//             {
//                 for (int j = 0; j < _M; ++j)
//                     o << data[i][j] << ' ';
//                 o << '\n';
//             }
//         }

//         std::array<std::array<_Type, _M>, _N> data;
//     };

//     template <SizeType _N, SizeType _M, DataType _Type>
//     inline bool operator==(Matrix<_N, _M, _Type> const &m1, Matrix<_N, _M, _Type> const &m2)
//     {
//         return m1.data == m2.data;
//     }
//     template <SizeType _N, SizeType _M, DataType _Type>
//     inline Matrix<_N, _M, _Type> operator-(Matrix<_N, _M, _Type> const &_m)
//     {
//         Matrix<_N, _M, _Type> m;
//         for (int i = 0; i < _N; ++i)
//             for (int j = 0; j < _M; ++j)
//                 m.data[i][j] = -_m.data[i][j];
//         return m;
//     }
//     template <SizeType _N, SizeType _M, DataType _Type>
//     inline Matrix<_N, _M, _Type> operator+(Matrix<_N, _M, _Type> const &m1, Matrix<_N, _M, _Type> const &m2)
//     {
//         Matrix<_N, _M, _Type> m;
//         for (int i = 0; i < _N; ++i)
//             for (int j = 0; j < _M; ++j)
//                 m.data[i][j] = m1.data[i][j] + m2.data[i][j];
//         return m;
//     }
//     template <SizeType _N, SizeType _M, DataType _Type>
//     inline Matrix<_N, _M, _Type> operator-(Matrix<_N, _M, _Type> const &m1, Matrix<_N, _M, _Type> const &m2)
//     {
//         return m1 + -m2;
//     }
//     template <SizeType _N, SizeType _M, DataType _Type>
//     inline Matrix<_N, _M, _Type> operator*(float s, Matrix<_N, _M, _Type> const &_m)
//     {
//         Matrix<_N, _M, _Type> m;
//         for (int i = 0; i < _N; ++i)
//             for (int j = 0; j < _M; ++j)
//                 m.data[i][j] = s * _m.data[i][j];
//         return m;
//     }
//     template <SizeType _N, SizeType _M, DataType _Type>
//     inline Matrix<_N, _M, _Type> operator*(Matrix<_N, _M, _Type> const &_m, float s)
//     {
//         return s * _m;
//     }
//     template <SizeType _N, SizeType _K, SizeType _M, DataType _Type>
//     inline Matrix<_N, _M, _Type> operator*(Matrix<_N, _K, _Type> const &m1, Matrix<_K, _M, _Type> const &m2)
//     {
//         Matrix<_N, _M, _Type> m;
//         for (int i = 0; i < _N; ++i)
//             for (int j = 0; j < _M; ++j)
//                 for (int k = 0; k < _K; ++k)
//                     m.data[i][j] += m1.data[i][k] * m2.data[k][j];
//         return m;
//     }

//     template<SizeType _N, DataType _Type>
//     struct SquareMatrix : public Matrix<_N, _N, _Type>
//     {
//         using Matrix<_N, _N, _Type>::data;

//         SquareMatrix() : Matrix<_N, _N, _Type>() { }
//         SquareMatrix(Matrix<_N, _N, _Type> const &m) : Matrix<_N, _N, _Type>(m) { }
//         SquareMatrix(std::initializer_list<std::initializer_list<_Type>> m) : Matrix<_N, _N, _Type>(m) { }
//         SquareMatrix(SquareMatrix const &m) : Matrix<_N, _N, _Type>(m) { }

//         SquareMatrix& Transpose()
//         {
//             for (int i = 0; i < _N; ++i)
//                 for (int j = i + 1; j < _N; ++j)
//                     std::swap(data[i][j], data[j][i]);
//             return *this;
//         }
//         _Type Trace() const
//         {
//             _Type tr = 0;
//             for (int i = 0; i < _N; ++i)
//                 tr += data[i][i];
//             return tr;
//         }
//         _Type Minor(SizeType i, SizeType j) const requires(_N > 1)
//         {
//             SquareMatrix<_N - 1, _Type> m;
//             for (SizeType r = 0; r < _N - 1; ++r)
//                 for (SizeType c = 0; c < _N - 1; ++c)
//                     m.data[r][c] = data[r < i ? r : r + 1][c < j ? c : c + 1];
            
//             return m.Determine();
//         }
//         _Type Cofactor(SizeType i, SizeType j) const requires(_N > 1)
//         {
//             return (i + j) % 2 == 0 ? Minor(i, j) : -Minor(i, j);
//         }
//         _Type Determine() const
//         {
//             _Type det = 0;
//             SizeType n = 0, zeroMax = 0, curMax;
//             for (SizeType i = 0; i < _N; ++i)
//             {
//                 curMax = 0;
//                 for (auto e : this->data[i])
//                     if (e == 0) ++curMax;
//                 if (curMax > zeroMax)
//                 {
//                     n = i;
//                     zeroMax = curMax;
//                 }
//             }
//             for (SizeType i = 0; i < _N; ++i)
//                 det += data[n][i] * Cofactor(n, i);
//             return det;
//         }
//         SquareMatrix<_N, _Type> CofactorMatrix() const
//         {
//             SquareMatrix<_N, _Type> m;
//             for (SizeType i = 0; i < _N; ++i)
//                 for (SizeType j = 0; j < _N; ++j)
//                     m.data[i][j] = Cofactor(i, j);
//             return m;
//         }
//         SquareMatrix<_N, _Type> Adjoint() const { return CofactorMatrix().Transpose(); }
//     };
//     template <DataType _Type>
//     struct SquareMatrix<1, _Type> : public Matrix<1, 1, _Type>
//     {
//         using Matrix<1, 1, _Type>::data;
//         _Type Determine() const { return data[0][0]; }
//     };
// }

// #include <iostream>
// #include "fraction.h"

// using namespace std;

// int main()
// {
//     FJ::Math::Matrix<2, 4, int> m1
//     {
//         {1, -8, 5, 0},
//         {0, 5, -3, 1}
//     };
//     auto m2 = m1.GetTranspose(); 
//     FJ::Math::SquareMatrix sm(m2*m1);
//     sm.Transpose();
//     sm.data[0][1] = -sm.data[0][1];
//     sm.data[1][0] = -sm.data[1][0];
//     (m1 * sm * m2).Print(cout);
//     cout << sm.Determine();
// }