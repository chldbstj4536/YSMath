#pragma once

#include "ysVector.hpp"

namespace YS::Math
{
    class Line3
    {
    public:
        explicit Line3(Vector3 const &dir, Point3 const &origin) : dir(dir), origin(origin) {}
    private:
        Point3 origin;
        Vector3 dir;
    };
}