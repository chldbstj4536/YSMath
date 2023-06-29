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
    /// @brief 기하학에서의 선을 표현하는 클래스
    class Line
    {
    public:
        static Float const INF_DISTANCE;

        /**
         * @brief 선위의 한 점과 방향으로 Line 생성
         * 
         * @param origin 선 위의 기준점
         * @param direction 선의 방향
         * @param distance 선의 길이 (default = INF_DISTANCE)
         */
        explicit Line(Point3 const &origin, Vector3 const &direction, Float const length = INF_DISTANCE) noexcept
            : origin(origin), direction(Vector3::Normalize(direction)), length(length) {}
        /**
         * @brief 선 위의 두 점으로 Line 생성
         * 
         * @param startPoint 시작 점
         * @param endPoint 끝 점
         */
        explicit Line(Point3 const &startPoint, Point3 const &endPoint) noexcept
            : origin(startPoint), direction(Vector3::Normalize(endPoint - startPoint)), length(Vector3::Distance(startPoint, endPoint)) {}

    private:
        /// @brief 선 위의 기준점
        Point3 origin;
        /// @brief 선의 방향
        Vector3 direction;
        /// @brief 선의 길이 (음수 (-1)은 무한데를 표현)
        Float length;
    };

    /// @brief 기하학에서 평면을 표현하는 클래스
    class Plane
    {
    public:
        /**
         * @brief 평면의 법선(Normal) 벡터와 평면 위의 한 점으로 Plane 생성
         * 
         * @param normal 평면에 수직인 방향벡터
         * @param point 평면 위의 한 점
         */
        explicit Plane(Vector3 const &normal, Point3 const &point) noexcept
            : normal(Vector3::Normalize(normal)), d(-Vector3::Dot(normal, point)) {}
        /**
         * @brief 평면의 법선(Normal) 벡터와 평면의 방정식의 상수항으로 Plane 구성
         *
         * @param normal 평면에 수직인 방향벡터
         * @param d 상수항 (-(n dot p), p = 평면 위의 한 점)
         */
        explicit Plane(Vector3 const &normal, Float d) noexcept
            : normal(Vector3::Normalize(normal)), d(d) {}
        /**
         * @brief 평면 위의 세 점으로 Plane 구성
         * 
         * @param v1 평면 위의 점1
         * @param v2 평면 위의 점2
         * @param v3 평면 위의 점3
         */
        explicit Plane(Point3 const &v1, Point3 const &v2, Point3 const &v3) noexcept
            : Plane(Vector3::Normalize((v2 - v1).Cross(v3 - v1)), v1) {}

        Vector3 GetNormalVector() const noexcept { return normal; }

    private:
        /// @brief 평면에 수직인 방향벡터
        Vector3 normal;
        /// @brief 평면의 방정식에서 상수항
        Float d;
    };
}