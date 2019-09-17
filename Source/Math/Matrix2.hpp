//-------------------------------------------------------------------------------------------------
// Warlock® Application Engine
// Copyright © 2019 Miguel Nischor
//
// File: Source/Math/Matrix2.hpp
// Description: Class to implement a 2x2 square matrix.
//-------------------------------------------------------------------------------------------------
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//-------------------------------------------------------------------------------------------------
#ifndef WARLOCK_MATH_MATRIX2_HPP
#define WARLOCK_MATH_MATRIX2_HPP

#include "Vector2.hpp"

namespace Warlock
{
    namespace Math
    {
        template <typename T> struct Matrix2
        {
            Matrix2()
            {
                m[0][0] = 0.0;
                m[0][1] = 0.0;

                m[1][0] = 0.0;
                m[1][1] = 0.0;
            };

            Matrix2(T Value)
            {
                m[0][0] = Value;
                m[0][1] = Value;

                m[1][0] = Value;
                m[1][1] = Value;
            };

            Matrix2(T m11, T m12, T m21, T m22)
            {
                m[0][0] = m11;
                m[0][1] = m12;

                m[1][0] = m21;
                m[1][1] = m22;
            };

            Matrix2(T Values[4])
            {
                m[0][0] = Values[0];
                m[0][1] = Values[1];

                m[1][0] = Values[2];
                m[1][1] = Values[3];
            };

            Matrix2(const Vector2<T> &First, const Vector2<T> &Second)
            {
                m[0][0] = First.x;
                m[0][1] = First.y;

                m[1][0] = Second.x;
                m[1][1] = Second.y;
            };

            Matrix2(const Matrix2<T> &Matrix)
            {
                m[0][0] = Matrix.m[0][0];
                m[0][1] = Matrix.m[0][1];

                m[1][0] = Matrix.m[1][0];
                m[1][1] = Matrix.m[1][1];
            };

            Matrix2 &operator +(T Value)
            {
                return Matrix2<T>(m[0][0] + Value,
                                  m[0][1] + Value,
                                  m[1][0] + Value,
                                  m[1][1] + Value);
            };

            Matrix2 &operator +(T Values[4])
            {
                return Matrix2<T>(m[0][0] + Values[0],
                                  m[0][1] + Values[1],
                                  m[1][0] + Values[2],
                                  m[1][1] + Values[3]);
            };

            Matrix2 &operator +(const Matrix2<T> &Matrix)
            {
                return Matrix2<T>(m[0][0] + Matrix.m[0][0],
                                  m[0][1] + Matrix.m[0][1],
                                  m[1][0] + Matrix.m[1][0],
                                  m[1][1] + Matrix.m[1][1]);
            };

            Matrix2 &operator -(T Value)
            {
                return Matrix2<T>(m[0][0] - Value,
                                  m[0][1] - Value,
                                  m[1][0] - Value,
                                  m[1][1] - Value);
            };

            Matrix2 &operator -(T Values[4])
            {
                return Matrix2<T>(m[0][0] - Values[0],
                                  m[0][1] - Values[1],
                                  m[1][0] - Values[2],
                                  m[1][1] - Values[3]);
            };

            Matrix2 &operator -(const Matrix2<T> &Matrix)
            {
                return Matrix2<T>(m[0][0] - Matrix.m[0][0],
                                  m[0][1] - Matrix.m[0][1],
                                  m[1][0] - Matrix.m[1][0],
                                  m[1][1] - Matrix.m[1][1]);
            };

            Matrix2 &operator *(T Value)
            {
                return Matrix2<T>(m[0][0] * Value,
                                  m[0][1] * Value,
                                  m[1][0] * Value,
                                  m[1][1] * Value);
            };

            Matrix2 &operator *(T Values[4])
            {
                return Matrix2<T>(m[0][0] * Values[0] + m[0][1] * Values[2],
                                  m[0][0] * Values[1] + m[1][0] * Values[3],
                                  m[1][0] * Values[0] + m[1][1] * Values[2],
                                  m[1][0] * Values[1] + m[1][1] * Values[3]);
            };

            Matrix2 &operator *(const Matrix2<T> &Matrix)
            {
                return Matrix2<T>(m[0][0] * Matrix.m[0][0] + m[0][1] * Matrix.m[1][0],
                                  m[0][0] * Matrix.m[0][1] + m[1][0] * Matrix.m[1][1],
                                  m[1][0] * Matrix.m[0][0] + m[1][1] * Matrix.m[1][0],
                                  m[1][0] * Matrix.m[0][1] + m[1][1] * Matrix.m[1][1]);
            };

            T operator [](int Index)
            {
                static_assert(Index >= 0, "Matrix index must be zero or higher");

                switch (Index)
                {
                    case 0:
                        return m[0][0];
                        break;

                    case 1:
                        return m[0][1];
                        break;

                    case 2:
                        return m[1][0];
                        break;

                    case 3:
                        return m[1][1];
                        break;

                    default:
                        return m[0][0];
                        break;
                };
            };

            void operator +=(T Value)
            {
                m[0][0] += Value;
                m[0][1] += Value;
                m[1][0] += Value;
                m[1][1] += Value;
            };

            void operator +=(T Values[4])
            {
                m[0][0] += Values[0];
                m[0][1] += Values[1];
                m[1][0] += Values[2];
                m[1][1] += Values[3];
            };

            void operator +=(const Matrix2<T> &Matrix)
            {
                m[0][0] += Matrix.m[0][0];
                m[0][1] += Matrix.m[0][1];
                m[1][0] += Matrix.m[1][0];
                m[1][1] += Matrix.m[1][1];
            };

            void operator -=(T Value)
            {
                m[0][0] -= Value;
                m[0][1] -= Value;
                m[1][0] -= Value;
                m[1][1] -= Value;
            };

            void operator -=(T Values[4])
            {
                m[0][0] -= Values[0];
                m[0][1] -= Values[1];
                m[1][0] -= Values[2];
                m[1][1] -= Values[3];
            };

            void operator -=(const Matrix2<T> &Matrix)
            {
                m[0][0] -= Matrix.m[0][0];
                m[0][1] -= Matrix.m[0][1];
                m[1][0] -= Matrix.m[1][0];
                m[1][1] -= Matrix.m[1][1];
            };

            void operator *=(T Value)
            {
                m[0][0] *= Value;
                m[0][1] *= Value;
                m[1][0] *= Value;
                m[1][1] *= Value;
            };

            void operator *=(T Values[4])
            {
                m[0][0] = m[0][0] * Values[0] + m[0][1] * Values[2];
                m[0][1] = m[0][0] * Values[1] + m[1][0] * Values[3];
                m[1][0] = m[1][0] * Values[0] + m[1][1] * Values[2];
                m[1][1] = m[1][0] * Values[1] + m[1][1] * Values[3];
            };

            void operator *=(const Matrix2<T> &Matrix)
            {
                m[0][0] = m[0][0] * Matrix.m[0][0] + m[0][1] * Matrix.m[1][0];
                m[0][1] = m[0][0] * Matrix.m[0][1] + m[1][0] * Matrix.m[1][1];
                m[1][0] = m[1][0] * Matrix.m[0][0] + m[1][1] * Matrix.m[1][0];
                m[1][1] = m[1][0] * Matrix.m[0][1] + m[1][1] * Matrix.m[1][1];
            };

            bool operator ==(T Values[4])
            {
                return (m[0][0] == Values[0] &&
                        m[0][1] == Values[1] &&
                        m[1][0] == Values[2] &&
                        m[1][1] == Values[3]);
            };

            bool operator ==(const Matrix2<T> &Matrix)
            {
                return (m[0][0] == Matrix.m[0][0] &&
                        m[0][1] == Matrix.m[0][1] &&
                        m[1][0] == Matrix.m[1][0] &&
                        m[1][1] == Matrix.m[1][1]);
            };

            bool operator !=(T Values[4])
            {
                return (m[0][0] != Values[0] ||
                        m[0][1] != Values[1] ||
                        m[1][0] != Values[2] ||
                        m[1][1] != Values[3]);
            };

            bool operator !=(const Matrix2<T> &Matrix)
            {
                return (m[0][0] != Matrix.m[0][0] ||
                        m[0][1] != Matrix.m[0][1] ||
                        m[1][0] != Matrix.m[1][0] ||
                        m[1][1] != Matrix.m[1][1]);
            };

            T Determinant()
            {
                return (m[0][0] * m[1][1] - m[0][1] * m[1][0]);
            };

            T Determinant(T Values[4])
            {
                return (Values[0] * Values[3] - Values[1] * Values[2]);
            };

            T Determinant(const Matrix2<T> &Matrix)
            {
                return (Matrix.m[0][0] * Matrix.m[1][1] - Matrix.m[0][1] * Matrix.m[1][0]);
            };

            void Transpose()
            {
                Matrix2<T> x = Matrix2<T>(m[0][0], m[1][0],
                                          m[0][1], m[1][1]);

                m[0][0] = x.m[0][0];
                m[0][1] = x.m[0][1];
                m[1][0] = x.m[1][0];
                m[1][1] = x.m[1][1];
            };

            void Transpose(T Values[4])
            {
                T x[4] = {Values[0], Values[2], Values[1], Values[3]};

                Values[0] = x[0];
                Values[1] = x[1];
                Values[2] = x[2];
                Values[3] = x[3];
            };

            void Transpose(Matrix2<T> &Matrix)
            {
                Matrix2<T> x = Matrix2<T>(Matrix.m[0][0], Matrix.m[1][0],
                                          Matrix.m[0][1], Matrix.m[1][1]);

                Matrix.m[0][0] = x[0][0];
                Matrix.m[0][1] = x[0][1];
                Matrix.m[1][0] = x[1][0];
                Matrix.m[1][1] = x[1][1];
            };

            Matrix2 &GetTransposed()
            {
                return Matrix2<T>(m[0][0], m[1][0],
                                  m[0][1], m[1][1]);
            };

            Matrix2 &GetTransposed(T Values[4])
            {
                return Matrix2<T>(Values[0], Values[2],
                                  Values[1], Values[3]);
            };

            Matrix2 &GetTransposed(const Matrix2<T> &Matrix)
            {
                return Matrix2<T>(Matrix.m[0][0], Matrix.m[1][0],
                                  Matrix.m[0][1], Matrix.m[1][1]);
            };

            void Inverse()
            {
                T det = 1.0 / Determinant();
                Matrix2<T> adj = Matrix2<T>(m[0][0], -m[0][1], -m[1][0], m[1][1]);
                Matrix2<T> ret = det * adj;

                m[0][0] = ret.m[0][0];
                m[0][1] = ret.m[0][1];
                m[1][0] = ret.m[1][0];
                m[1][1] = ret.m[1][1];
            };

            void Inverse(T Values[4])
            {
                T det = 1.0 / Determinant(Values);
                Matrix2<T> adj = Matrix2<T>(Values[0], -Values[1], -Values[2], Values[3]);
                Matrix2<T> ret = det * adj;

                Values[0] = ret.m[0][0];
                Values[1] = ret.m[0][1];
                Values[2] = ret.m[1][0];
                Values[3] = ret.m[1][1];
            };

            void Inverse(Matrix2<T> &Matrix)
            {
                T det = 1.0 / Determinant(Matrix);
                Matrix2<T> adj = Matrix2<T>(Matrix.m[0][0], -Matrix.m[0][1], -Matrix.m[1][0], Matrix.m[1][1]);
                Matrix2<T> ret = det * adj;

                Matrix.m[0][0] = ret.m[0][0];
                Matrix.m[0][1] = ret.m[0][1];
                Matrix.m[1][0] = ret.m[1][0];
                Matrix.m[1][1] = ret.m[1][1];
            };

            Matrix2 &GetInverse()
            {
                T det = 1.0 / Determinant();
                Matrix2<T> adj = Matrix2<T>(m[0][0], -m[0][1], -m[1][0], m[1][1]);

                return (det * adj);
            };

            Matrix2 &GetInverse(T Values[4])
            {
                T det = 1.0 / Determinant(Values);
                Matrix2<T> adj = Matrix2<T>(Values[0], -Values[1], -Values[2], Values[3]);

                return (det * adj);
            };

            Matrix2 &GetInverse(const Matrix2<T> &Matrix)
            {
                T det = 1.0 / Determinant(Matrix);
                Matrix2<T> adj = Matrix2<T>(Matrix.m[0][0], -Matrix.m[0][1], -Matrix.m[1][0], Matrix.m[1][1]);

                return (det * adj);
            };

            bool IsNull()
            {
                return (m[0][0] == 0.0 &&
                        m[0][1] == 0.0 &&
                        m[1][0] == 0.0 &&
                        m[1][1] == 0.0);
            };

            bool IsNull(T Values[4])
            {
                return (Values[0] == 0.0 &&
                        Values[1] == 0.0 &&
                        Values[2] == 0.0 &&
                        Values[3] == 0.0);
            };

            bool IsNull(const Matrix2<T> &Matrix)
            {
                return (Matrix.m[0][0] == 0.0 &&
                        Matrix.m[0][1] == 0.0 &&
                        Matrix.m[1][0] == 0.0 &&
                        Matrix.m[1][1] == 0.0);
            };

            bool IsIdentity()
            {
                return (m[0][0] == 1.0 &&
                        m[0][1] == 0.0 &&
                        m[1][0] == 0.0 &&
                        m[1][1] == 1.0);
            };

            bool IsIdentity(T Values[4])
            {
                return (Values[0] == 1.0 &&
                        Values[1] == 0.0 &&
                        Values[2] == 0.0 &&
                        Values[3] == 1.0);
            };

            bool IsIdentity(const Matrix2<T> &Matrix)
            {
                return (Matrix.m[0][0] == 1.0 &&
                        Matrix.m[0][1] == 0.0 &&
                        Matrix.m[1][0] == 0.0 &&
                        Matrix.m[1][1] == 1.0);
            };

            T m[2][2];
        };

        Matrix2<int> Matrix2I;
        Matrix2<float> Matrix2F;
        Matrix2<short> Matrix2S;
        Matrix2<double> Matrix2D;
    };
};

#endif // WARLOCK_MATH_MATRIX2_HPP
