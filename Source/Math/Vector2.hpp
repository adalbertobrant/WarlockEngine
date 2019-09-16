//-------------------------------------------------------------------------------------------------
// Warlock® Application Engine
// Copyright © 2019 Miguel Nischor
//
// File: Source/Math/Vector2.hpp
// Description: Class to implement a 2D cartesian vector.
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
#ifndef WARLOCK_MATH_VECTOR2_HPP
#define WARLOCK_MATH_VECTOR2_HPP

#include "Platform/Platform.hpp"
#include <cmath>

namespace Warlock
{
    namespace Math
    {
        template <typename T> struct Vector2
        {
            Vector2() : x(0.0), y(0.0) {};
            Vector2(T Value), x(Value), y(Value) {};
            Vector2(T cx, T cy) : x(cx), y(cy) {};
            Vector2(const Vector2<T> &Value) : x(Value.x), y(Value.y) {};

            Vector2 &operator +(T Value)
            {
                return Vector2<T>(x + Value, y + Value);
            };

            Vector2 &operator +(const Vector2<T> &Other)
            {
                return Vector2<T>(x + Other.x, y + Other.y);
            };

            Vector2 &operator -(T Value)
            {
                return Vector2<T>(x - Value, y - Value);
            };

            Vector2 &operator -(const Vector2<T> &Other)
            {
                return Vector2<T>(x - Other.x, y - Other.y);
            };

            Vector2 &operator *(T Scalar)
            {
                return Vector2<T>(x * Scalar, y * Scalar);
            };

            void operator +=(T Value)
            {
                x += Value;
                y += Value;
            };

            void operator +=(const Vector2<T> &Other)
            {
                x += Other.x;
                y += Other.y;
            };

            void operator -=(T Value)
            {
                x -= Value;
                y -= Value;
            };

            void operator -=(const Vector2<T> &Other)
            {
                x -= Other.x;
                y -= Other.y;
            };

            void operator *=(T Scalar)
            {
                x *= Scalar;
                y *= Scalar;
            };

            bool operator ==(T Value)
            {
                return (x == Value && y == Value);
            };

            bool operator ==(const Vector2<T> &Other)
            {
                return (x == Other.x && y == Other.y);
            };

            bool operator !=(T Value)
            {
                return (x != Value || y != Value);
            };

            bool operator !=(const Vector2<T> &Other)
            {
                return (x != Other.x || y != Other.y);
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

            T Area(const Vector2<T> &Other)
            {
                static_assert(Other.x >= 0.0 && Other.y >= 0.0, "Coordinates must be zero or higher");

                return (Other.x * Other.y);
            };

            T Magnitude()
            {
                return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
            };

            T Magnitude(T cx, T cy)
            {
                return std::sqrt(std::pow(cx, 2) + std::pow(cy, 2));
            };

            T Magnitude(const Vector2<T> &Other)
            {
                return std::sqrt(std::pow(Other.x, 2) + std::pow(Other.y, 2));
            };

            T ScalarProduct(T cx, T cy)
            {
                return (x + cx * y + cy);
            };

            T ScalarProduct(const Vector2<T> &Other)
            {
                return (x + Other.x * y + Other.y);
            };

            T Distance(T cx, T cy)
            {
                return Magnitude(cx - x, cy - y);
            };

            T Distance(const Vector2<T> &Other)
            {
                return Magnitude(Other.x - x, Other.y - y);
            };

            bool IsNull()
            {
                return (x == 0.0 && y == 0.0);
            };

            bool IsNull(T cx, T cy)
            {
                return (cx == 0.0 && cy == 0.0);
            };

            bool IsNull(const Vector2<T> &Other)
            {
                return (Other.x == 0.0 && Other.y == 0.0);
            };

            bool IsUnit()
            {
                return (Magnitude() == 1.0);
            };

            bool IsUnit(T cx, T cy)
            {
                return (Magnitude(cx, cy) == 1.0);
            };

            bool IsUnit(const Vector2<T> &Other)
            {
                return (Magnitude(Other.x, Other.y) == 1.0);
            };

            T x;
            T y;
        };

        Vector2<int> Vector2I;
        Vector2<float> Vector2F;
        Vector2<short> Vector2S;
        Vector2<double> Vector2D;
    };
};

#endif // WARLOCK_MATH_VECTOR2_HPP
