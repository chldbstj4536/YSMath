/**
 * @file ysGeometry.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-29
 * 
 * @copyright Copyright (c) 2023
 */
#include "../inc/ysGeometry.hpp"

#define _YS_MATH_BEGIN namespace YS::Math {
#define _YS_MATH_END }

_YS_MATH_BEGIN
Float const Line::INF_DISTANCE = 1.0f;
bool HasIntersectionPoint(Line const &line, Plane const &plane, Point3 &outIntersectionPoint)
{
    // line 위의 한 점
    Point3 const &pL = line.GetOrigin();
    // line의 방향
    Vector3 const &dL = line.GetDirection();
    // plane의 법선벡터
    Vector3 const &nP = plane.GetNormalVector();
    // plane 위의 한 점
    Point3 const &pP = plane.GetPointOnPlane();

    // line의 방향이 plane의 법선벡터와 직교한다면 교점이 무수히 많거나 없으므로 교점이 없는것으로 판단한다.
    if (std::fabs(dL.Dot(nP)) < FLT_EPSILON)
        return false;

    outIntersectionPoint = pL + (nP.Dot(pP - pL) / dL.Dot(nP)) * dL;

    return true;
}
_YS_MATH_END