//-------------------------------------------------------------------------------------------------
// Warlock® Application Engine
// Copyright © 2019 Miguel Nischor
//
// File: Source/Math/Vector3.hpp
// Description: Class to implement a 3D cartesian vector.
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
#ifndef WARLOCK_MATH_VECTOR3_HPP
#define WARLOCK_MATH_VECTOR3_HPP

#include "Platform/Platform.hpp"
#include <cmath>

namespace Warlock
{
    namespace Math
    {
        template <typename T> struct Vector3
        {
            Vector3() : x(0.0), y(0.0), z(0.0) {};
            Vector3(T Value), x(Value), y(Value), z(Value) {};
            Vector3(T cx, T cy, T cz) : x(cx), y(cy), z(cz) {};
            Vector3(const Vector3<T> &Value) : x(Value.x), y(Value.y), z(Value.z) {};

            Vector3 &operator +(T Value)
            {
                return Vector3<T>(x + Value, y + Value, z + Value);
            };

            Vector3 &operator +(const Vector3<T> &Vector)
            {
                return Vector3<T>(x + Vector.x, y + Vector.y, z + Vector.z);
            };

            Vector3 &operator -(T Value)
            {
                return Vector3<T>(x - Value, y - Value, z - Value);
            };

            Vector3 &operator -(const Vector3<T> &Vector)
            {
                return Vector3<T>(x - Vector.x, y - Vector.y, z - Vector.z);
            };

            Vector3 &operator *(T Scalar)
            {
                return Vector3<T>(x * Scalar, y * Scalar, z * Scalar);
            };

            bool operator >(const Vector3<T> &Vector)
            {
                return (Magnitude() > Magnitude(Vector));
            };

            bool operator <(const Vector3<T> &Vector)
            {
                return (Magnitude() < Magnitude(Vector));
            };

            T operator [](int Index)
            {
                static_assert(Index >= 0, "Vector index must be zero or higher");

                switch (Index)
                {
                    case 0:
                        return x;
                        break;

                    case 1:
                        return y;
                        break;

                    case 2:
                        return z;
                        break;

                    default:
                        return x;
                        break;
                };
            };

            void operator +=(T Value)
            {
                x += Value;
                y += Value;
                z += Value;
            };

            void operator +=(const Vector3<T> &Vector)
            {
                x += Vector.x;
                y += Vector.y;
                z += Vector.z;
            };

            void operator -=(T Value)
            {
                x -= Value;
                y -= Value;
                z -= Value;
            };

            void operator -=(const Vector3<T> &Vector)
            {
                x -= Vector.x;
                y -= Vector.y;
                z -= Vector.z;
            };

            void operator *=(T Scalar)
            {
                x *= Scalar;
                y *= Scalar;
                z *= Scalar;
            };

            bool operator >=(const Vector3<T> &Vector)
            {
                return (Magnitude() >= Magnitude(Vector));
            };

            bool operator <=(const Vector3<T> &Vector)
            {
                return (Magnitude() <= Magnitude(Vector));
            };

            bool operator ==(T Value)
            {
                return (x == Value && y == Value && z == Value);
            };

            bool operator ==(const Vector3<T> &Vector)
            {
                return (x == Vector.x && y == Vector.y && z == Vector.z);
            };

            bool operator !=(T Value)
            {
                return (x != Value || y != Value || z != Value);
            };

            bool operator !=(const Vector3<T> &Vector)
            {
                return (x != Vector.x || y != Vector.y || z != Vector.z);
            };

            T Area()
            {
                static_assert(x >= 0.0 && y >= 0.0, "Coordinates must be zero or higher");

                return (x * y);
            };

            T Area(T cx, T cy)
            {
                static_assert(cx >= 0.0 && cy >= 0.0, "Coordinates must be zero or higher");

                return (cx * cy);
            };

            T Area(const Vector3<T> &Vector)
            {
                static_assert(Vector.x >= 0.0 && Vector.y >= 0.0, "Coordinates must be zero or higher");

                return (Vector.x * Vector.y);
            };

            T Volume()
            {
                static_assert(x >= 0.0 && y >= 0.0 && z >= 0.0, "Coordinates must be zero or higher");

                return (x * y * z);
            };

            T Volume(T cx, T cy, T cz)
            {
                static_assert(cx >= 0.0 && cy >= 0.0 && cz >= 0.0, "Coordinates must be zero or higher");

                return (cx * cy * cz);
            };

            T Volume(const Vector3<T> &Vector)
            {
                return (Vector.x * Vector.y * Vector.z);
            };

            T Magnitude()
            {
                return std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2));
            };

            T Magnitude(T cx, T cy, T cz)
            {
                return std::sqrt(std::pow(cx, 2) + std::pow(cy, 2) + std::pow(cz, 2));
            };

            T Magnitude(const Vector3<T> &Vector)
            {
                return std::sqrt(std::pow(Vector.x, 2) + std::pow(Vector.y, 2) + std::pow(Vector.z, 2));
            };

            T ScalarProduct(T cx, T cy, T cz)
            {
                return (x + cx * y + cy * z + cz);
            };

            T ScalarProduct(const Vector3<T> &Vector)
            {
                return (x + Vector.x * y + Vector.y * z + Vector.z);
            };

            Vector3 &VectorProduct(T cx, T cy, T cz)
            {
                return Vector3<T>(y * cz - z * cy,
                                  z * cx - x * cz,
                                  x * cy - y * cx);
            };

            Vector3 &VectorProduct(const Vector3<T> &Vector)
            {
                return Vector3<T>(y * Vector.z - z * Vector.y,
                                  z * Vector.x - x * Vector.z,
                                  x * Vector.y - y * Vector.x);
            };

            T Distance(T cx, T cy, T cz)
            {
                return Magnitude(cx - x, cy - y, cz - z);
            };

            T Distance(const Vector3<T> &Vector)
            {
                return Magnitude(Vector.x - x, Vector.y - y, Vector.z - z);
            };

            bool IsNull()
            {
                return (x == 0.0 && y == 0.0 && z == 0.0);
            };

            bool IsNull(T cx, T cy, T cz)
            {
                return (cx == 0.0 && cy == 0.0 && cz == 0.0);
            };

            bool IsNull(const Vector3<T> &Vector)
            {
                return (Vector.x == 0.0 && Vector.y == 0.0 && Vector.z == 0.0);
            };

            bool IsUnit()
            {
                return (Magnitude() == 1.0);
            };

            bool IsUnit(T cx, T cy, T cz)
            {
                return (Magnitude(cx, cy, cz) == 1.0);
            };

            bool IsUnit(const Vector3<T> &Vector)
            {
                return (Magnitude(Vector.x, Vector.y, Vector.z) == 1.0);
            };

            T x;
            T y;
            T z;
        };

        Vector3<int> Vector3I;
        Vector3<float> Vector3F;
        Vector3<short> Vector3S;
        Vector3<double> Vector3D;
    };
};

#endif // WARLOCK_MATH_VECTOR3_HPP
