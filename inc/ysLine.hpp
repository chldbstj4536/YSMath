/**
 * @file ysLine.hpp
 * @author 최윤서 (choicoco1995@naver.com)
 * @version 0.1
 * @date 2023-06-22
 * 
 * @copyright Copyright (c) 2023 최윤서. All rights reserved.
 */
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