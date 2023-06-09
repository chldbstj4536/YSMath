#pragma once

#include "ysVector.hpp"

namespace YS::Math
{
    class Plane
    {
    public:
        explicit Plane(Vector3 const &n, Float d) : n(n), d(d) {}
        explicit Plane(Float a, Float b, Float c, Float d) : n(a, b, c), d(d) {}
        explicit Plane(Vector3 const &n, Point3 const &p) : n(n), d(-Vector3::Dot(n, p)) {}
    private:
        Vector3 n;
        Float d;
    };
}