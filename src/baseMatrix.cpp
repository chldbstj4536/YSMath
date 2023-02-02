// #pragma once

// #include "fmathdef.h"
// #include <concepts>
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

//     using SizeType = size_t;
    
//     template <DataType _Type = float>
//     struct MatrixBase
//     {
//     protected:
//         MatrixBase(SizeType row, SizeType col, _Type *pData) : r(row), c(col), pData(pData) {}
//         MatrixBase(std::initializer_list<std::initializer_list<_Type>> &m, SizeType row, SizeType col, _Type *_pData)
//         : MatrixBase<_Type>(row, col, _pData)
//         {
//             for (auto i = 0, col_iter = m.begin(); i < r && col_iter != m.end(); ++i, ++col_iter)
//                 for (auto j = 0, row_iter = col_iter->begin(); j < c && row_iter != col_iter->end(); ++j, ++row_iter)
//                     At(i, j) = (*row_iter);
//         }

//         SizeType index(SizeType i, SizeType j) const { return (i * c) + j; }
//         _Type At(SizeType _row, SizeType _col) const { return pData[index(_row, _col)]; }
//         _Type& At(SizeType _row, SizeType _col) { return pData[index(_row, _col)]; }

//         bool operator==(MatrixBase<_Type> const &m)
//         {
//             for (SizeType i = 0; i < r; ++i)
//                 for (SizeType j = 0; j < c; ++j)
//                     if (m.At(i, j) != At(i, j))
//                         return false;
//             return true;
//         }

//         template<SizeType _R1, SizeType _R2>
//         void RowExchange()
//         {
//             if (_R1 == _R2)
//                 return;
//             std::swap_ranges(pData + index(_R1, 0), c, pData + index(_R2, 0));
//         }
//         void RowExchange(SizeType r1, SizeType r2)
//         {
//             if (r1 == r2)
//                 return;
//             std::swap_ranges(pData + index(r1, 0), c, pData + index(r2, 0));
//         }
//         template<SizeType _C1, SizeType _C2>
//         void ColumnExchange()
//         {
//             if (_C1 == _C2) return;
//             for (int i = 0; i < r; ++i)
//                 std::swap(At(i, _C1), At(i, _C2));
//         }
//         void ColumnExchange(SizeType c1, SizeType c2)
//         {
//             if (c1 == c2)   return;
//             for (int i = 0; i < r; ++i)
//                 std::swap(At(i, c1), At(i, c2));
//         }
//         void GetTranspose(MatrixBase &t) const
//         {
//             for (int i = 0; i < r; ++i)
//                 for (int j = 0; j < c; ++j)
//                     t.At(i, j) = At(j, i);
//         }
//         void Print(std::ostream& o)
//         {
//             for (int i = 0; i < r; ++i)
//             {
//                 for (int j = 0; j < c; ++j)
//                     o << At(i, j) << ' ';
//                 o << '\n';
//             }
//         }

//         SizeType r, c;
//         _Type *pData;
//     };
//     template <DataType _Type>
//     struct SquareMatrixBase : public MatrixBase<_Type>
//     {
//         using MatrixBase<_Type>::r;
//         using MatrixBase<_Type>::At;
//     protected:
//         SquareMatrixBase(SizeType n, _Type *pData) : MatrixBase<_Type>(n, n, pData) {}
//         SquareMatrixBase(std::initializer_list<std::initializer_list<_Type>> &m, SizeType n, _Type *pData)
//          : MatrixBase<_Type>(m, n, n, pData) {}

//         SquareMatrixBase& Transpose()
//         {
//             for (int i = 0; i < r; ++i)
//                 for (int j = i + 1; j < r; ++j)
//                     std::swap(At(i, j), At(j, i));
//             return *this;
//         }
//         _Type Trace() const
//         {
//             _Type tr = 0;
//             for (int i = 0; i < r; ++i)
//                 tr += At(i, i);
//             return tr;
//         }
//     };
//     template <SizeType _N, SizeType _M, DataType _Type>
//     struct Matrix : private MatrixBase<_Type>
//     {
//         Matrix() : MatrixBase<_Type>(_N, _M, data), data() {}
//         Matrix(std::initializer_list<std::initializer_list<_Type>> m) : MatrixBase<_Type>(m, _N, _M, data) {}
//         Matrix(Matrix const &) = default;
//         Matrix(Matrix &&) = default;
//         ~Matrix() = default;
//         Matrix& operator=(Matrix const &m) = default;
//         Matrix& operator=(Matrix &&m) = default;

//         _Type data[_N * _M];
//      };
//     template<SizeType _N, DataType _Type>
//     struct Matrix<_N, _N, _Type> : private SquareMatrixBase<_Type>
//     {
//         using MatrixBase<_Type>::At;

//         Matrix() : SquareMatrixBase<_Type>(_N, data), data() {}
//         Matrix(std::initializer_list<std::initializer_list<_Type>> m) : SquareMatrixBase<_Type>(m, _N, data) {}
//         Matrix(Matrix const &) = default;
//         Matrix(Matrix &&) = default;
//         ~Matrix() = default;
//         Matrix& operator=(Matrix const &m) = default;
//         Matrix& operator=(Matrix &&m) = default;

//         _Type Minor(SizeType i, SizeType j) const
//         {
//             Matrix<_N - 1, _N - 1, _Type> m;
//             for (SizeType r = 0; r < _N - 1; ++r)
//                 for (SizeType c = 0; c < _N - 1; ++c)
//                     m.At(r, c) = At(r < i ? r : r + 1, c < j ? c : c + 1);
            
//             return m.Determine();
//         }
//         _Type Cofactor(SizeType i, SizeType j) const
//         {
//             return (i + j) % 2 == 0 ? Minor(i, j) : -Minor(i, j);
//         }
//         _Type Determine() const
//         {
//             _Type det = 0;
//             SizeType pivot = 0, zeroMax = 0, curMax;
//             for (SizeType i = 0; i < _N; ++i)
//             {
//                 curMax = 0;
//                 for (SizeType j = 0; j < _N; ++j)
//                     if (At(i, j) == 0)
//                         ++curMax;
//                 if (curMax > zeroMax)
//                 {
//                     pivot = i;
//                     zeroMax = curMax;
//                 }
//             }
//             for (SizeType i = 0; i < _N; ++i)
//                 det += At(pivot, i) * Cofactor(pivot, i);
//             return det;
//         }
//         Matrix<_N, _N, _Type> CofactorMatrix() const
//         {
//             Matrix<_N, _N, _Type> m;
//             for (SizeType i = 0; i < _N; ++i)
//                 for (SizeType j = 0; j < _N; ++j)
//                     m.At(i, j) = Cofactor(i, j);
//             return m;
//         }
//         Matrix<_N, _N, _Type> Adjoint() const { return CofactorMatrix().Transpose(); }

//         _Type data[_N * _N];
//     };
//     template <DataType _Type>
//     struct Matrix<1, 1, _Type> : private SquareMatrixBase<_Type>
//     {
//         Matrix() : SquareMatrixBase<_Type>(1, 1, &data) {}
//         Matrix(_Type data) : SquareMatrixBase<_Type>(1, 1, &data), data(data) {}
//         Matrix(Matrix const &) = default;
//         Matrix(Matrix &&) = default;
//         ~Matrix() = default;
//         Matrix& operator=(Matrix const &m) = default;
//         Matrix& operator=(Matrix &&m) = default;

//         _Type Determine() const { return data; }

//         _Type data;
//     };

// #pragma region MatrixBase operator overload
//     template <DataType _Type>
//     inline MatrixBase<_Type> operator-(MatrixBase<_Type> const &m)
//     {
//         MatrixBase<_Type> result;
//         for (int i = 0; i < m.r; ++i)
//             for (int j = 0; j < m.c; ++j)
//                 result.At(i, j) = -m.At(i, j);
//         return result;
//     }
//     template <DataType _Type>
//     inline Matrix<_N, _M, _Type> operator+(Matrix<_N, _M, _Type> const &m1, Matrix<_N, _M, _Type> const &m2)
//     {
//         Matrix<_N, _M, _Type> m;
//         for (int i = 0; i < _N; ++i)
//             for (int j = 0; j < _M; ++j)
//                 m.At(i, j) = m1.At(i, j) + m2.At(i, j);
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
//                 m.At(i, j) = s * _m.At(i, j);
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
//                     m.At(i, j) += m1.At(i, k) * m2.At(k, j);
//         return m;
//     }
// #pragma endregion
// }

// #include <iostream>
// #include "fraction.h"

// using namespace std;
// using namespace FJ::Math;
// int main()
// {
//     Matrix<2, 2, int> sm1
//     {
//         {1, 2},
//         {3, 4}
//     };
//     Matrix<2, 2, int> sm2
//     {
//         {1, 2},
//         {3, 4}
//     };

//     sm1 = sm1 * sm2;

//     Matrix<4, 2, int> m1
//     {
//         {2, -3},
//         {1, 0},
//         {0, 1},
//         {-5, 5}
//     };
// }