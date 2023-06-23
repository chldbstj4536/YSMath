#include <iostream>
#include <format>
#include <YSMath/ysVector.hpp>
#include <YSMath/ysMatrix.hpp>
#include <ysUtility.hpp>

using namespace YS::Math;
using namespace std;

static const int kMin = -5.0f;
static const int kMax = 5.0f;

Vector2 GetVector2Random() { return Vector2(YS::Random(kMin, kMax), YS::Random(kMin, kMax)); }
Vector3 GetVector3Random() { return Vector3(YS::Random(kMin, kMax), YS::Random(kMin, kMax), YS::Random(kMin, kMax)); }
Vector4 GetVector4Random() { return Vector4(YS::Random(kMin, kMax), YS::Random(kMin, kMax), YS::Random(kMin, kMax), YS::Random(kMin, kMax)); }
Matrix3x3 GetMatrix3x3Random() { return Matrix3x3(GetVector3Random(), GetVector3Random(), GetVector3Random()); }
Matrix3x3 BFMatrixMultiply(Matrix3x3 const& m1, Matrix3x3 const& m2)
{
    Matrix3x3 result;
    result.data[0] = m1.GetAt(0, 0) * m2.GetAt(0, 0) + m1.GetAt(0, 1) * m2.GetAt(1, 0) + m1.GetAt(0, 2) * m2.GetAt(2, 0);
    result.data[1] = m1.GetAt(0, 0) * m2.GetAt(0, 1) + m1.GetAt(0, 1) * m2.GetAt(1, 1) + m1.GetAt(0, 2) * m2.GetAt(2, 1);
    result.data[2] = m1.GetAt(0, 0) * m2.GetAt(0, 2) + m1.GetAt(0, 1) * m2.GetAt(1, 2) + m1.GetAt(0, 2) * m2.GetAt(2, 2);
    result.data[3] = m1.GetAt(1, 0) * m2.GetAt(0, 0) + m1.GetAt(1, 1) * m2.GetAt(1, 0) + m1.GetAt(1, 2) * m2.GetAt(2, 0);
    result.data[4] = m1.GetAt(1, 0) * m2.GetAt(0, 1) + m1.GetAt(1, 1) * m2.GetAt(1, 1) + m1.GetAt(1, 2) * m2.GetAt(2, 1);
    result.data[5] = m1.GetAt(1, 0) * m2.GetAt(0, 2) + m1.GetAt(1, 1) * m2.GetAt(1, 2) + m1.GetAt(1, 2) * m2.GetAt(2, 2);
    result.data[6] = m1.GetAt(2, 0) * m2.GetAt(0, 0) + m1.GetAt(2, 1) * m2.GetAt(1, 0) + m1.GetAt(2, 2) * m2.GetAt(2, 0);
    result.data[7] = m1.GetAt(2, 0) * m2.GetAt(0, 1) + m1.GetAt(2, 1) * m2.GetAt(1, 1) + m1.GetAt(2, 2) * m2.GetAt(2, 1);
    result.data[8] = m1.GetAt(2, 0) * m2.GetAt(0, 2) + m1.GetAt(2, 1) * m2.GetAt(1, 2) + m1.GetAt(2, 2) * m2.GetAt(2, 2);
    return result;
}

//#define VECTOR_TEST
//#define MATRIX_TEST

int main()
{
#ifdef VECTOR_TEST
#pragma region Constructor Tset
{
    cout << format("----------Constructor Test!----------\n");

    cout << format("v2: {}\n", GetVector2Random());
    cout << format("v3: {}\n", GetVector3Random());
    cout << format("v4: {}\n", GetVector4Random());

    cout << format("----------Constructor Test End!----------\n");
}
#pragma endregion

    cout << '\n';

#pragma region Operator Test
{
    cout << format("----------Operator Test----------\n");

    float s = YS::Random(kMin, kMax);
    float s_temp = YS::Random(kMin, kMax);

    {
        cout << format("----------Vector2----------\n");
        Vector2 v1 = GetVector2Random();
        Vector2 v2 = GetVector2Random();
        Vector2 v_temp = GetVector2Random();

        cout << format("{} = -{}\n", -v1, v1);
        cout << format("{} + {} = {}\n", v1, v2, v1 + v2);
        cout << format("{} - {} = {}\n", v1, v2, v1 - v2);
        cout << format("{} * {} = {}\n", s, v1, s * v1);
        cout << format("{} / {} = {}\n", v2, s, v2 / s);
        cout << format("v1 = {}, v2 = {}\n", v1, v2);
        cout << format("v1 += {}\n", v_temp);
        v1 += v_temp;
        cout << format("v1 = {}\n", v1);
        cout << format("v2 -= {}\n", v_temp);
        v2 -= v_temp;
        cout << format("v2 = {}\n", v2);
        cout << format("v1 *= {}\n", s_temp);
        v1 *= s_temp;
        cout << format("v1 = {}\n", v1);
        cout << format("v2 /= {}\n", s_temp);
        v2 /= s_temp;
        cout << format("v2 = {}\n", v2);

        cout << format("{} == {} : {}\n", v1, v2, v1 == v2);
        cout << format("{} != {} : {}\n", v1, v2, v1 != v2);
        cout << format("{} == {} : {}\n", v1, v1, v1 == v1);
        cout << format("{} != {} : {}\n", v1, v1, v1 != v1);
    }

    {
        cout << format("\n----------Vector3----------\n");
        Vector3 v1 = GetVector3Random();
        Vector3 v2 = GetVector3Random();
        Vector3 v_temp = GetVector3Random();

        cout << format("{} = -{}\n", -v1, v1);
        cout << format("{} + {} = {}\n", v1, v2, v1 + v2);
        cout << format("{} - {} = {}\n", v1, v2, v1 - v2);
        cout << format("{} * {} = {}\n", s, v1, s * v1);
        cout << format("{} / {} = {}\n", v2, s, v2 / s);
        cout << format("v1 = {}, v2 = {}\n", v1, v2);
        cout << format("v1 += {}\n", v_temp);
        v1 += v_temp;
        cout << format("v1 = {}\n", v1);
        cout << format("v2 -= {}\n", v_temp);
        v2 -= v_temp;
        cout << format("v2 = {}\n", v2);
        cout << format("v1 *= {}\n", s_temp);
        v1 *= s_temp;
        cout << format("v1 = {}\n", v1);
        cout << format("v2 /= {}\n", s_temp);
        v2 /= s_temp;
        cout << format("v2 = {}\n", v2);

        cout << format("{} == {} : {}\n", v1, v2, v1 == v2);
        cout << format("{} != {} : {}\n", v1, v2, v1 != v2);
        cout << format("{} == {} : {}\n", v1, v1, v1 == v1);
        cout << format("{} != {} : {}\n", v1, v1, v1 != v1);
    }

    {
        cout << format("\n----------Vector4----------\n");
        Vector4 v1 = GetVector4Random();
        Vector4 v2 = GetVector4Random();
        Vector4 v_temp = GetVector4Random();

        cout << format("{} = -{}\n", -v1, v1);
        cout << format("{} + {} = {}\n", v1, v2, v1 + v2);
        cout << format("{} - {} = {}\n", v1, v2, v1 - v2);
        cout << format("{} * {} = {}\n", s, v1, s * v1);
        cout << format("{} / {} = {}\n", v2, s, v2 / s);
        cout << format("v1 = {}, v2 = {}\n", v1, v2);
        cout << format("v1 += {}\n", v_temp);
        v1 += v_temp;
        cout << format("v1 = {}\n", v1);
        cout << format("v2 -= {}\n", v_temp);
        v2 -= v_temp;
        cout << format("v2 = {}\n", v2);
        cout << format("v1 *= {}\n", s_temp);
        v1 *= s_temp;
        cout << format("v1 = {}\n", v1);
        cout << format("v2 /= {}\n", s_temp);
        v2 /= s_temp;
        cout << format("v2 = {}\n", v2);

        cout << format("{} == {} : {}\n", v1, v2, v1 == v2);
        cout << format("{} != {} : {}\n", v1, v2, v1 != v2);
        cout << format("{} == {} : {}\n", v1, v1, v1 == v1);
        cout << format("{} != {} : {}\n", v1, v1, v1 != v1);
    }

    cout << format("----------Operator Test End!----------\n");
}
#pragma endregion

    cout << '\n';

#pragma region Function Test
{
    cout << format("----------Function Test!----------\n");

    {
        Vector2 v1 = GetVector2Random();
        Vector2 v2 = GetVector2Random();
        cout << format("----------Vector2----------\n");
        cout << format("v1: {}\nv2: {}\n", v1, v2);

        cout << format("v1.LengthSquared() = {}\n", v1.LengthSquared());
        cout << format("v1.Length() = {}\n", v1.Length());
        cout << format("v1.DistanceSquared(v2) = {}\n", v1.DistanceSquared(v2));
        cout << format("v1.Distance(v2) = {}\n", v1.Distance(v2));
        cout << format("v1.Dot(v2) = {}\n", v1.Dot(v2));
        cout << format("v1.Normalize() = {}\n", v1.Normalize());

        cout << format("Vector2::LengthSquared(v1) = {}\n", Vector2::LengthSquared(v1));
        cout << format("Vector2::Length(v1) = {}\n", Vector2::Length(v1));
        cout << format("Vector2::DistanceSquared(v1, v2) = {}\n", Vector2::DistanceSquared(v1, v2));
        cout << format("Vector2::Distance(v1, v2) = {}\n", Vector2::Distance(v1, v2));
        cout << format("Vector2::Dot(v1, v2) = {}\n", Vector2::Dot(v1, v2));
        cout << format("Vector2::Normalize(v1) = {}\n", Vector2::Normalize(v1));
    }

    cout << '\n';

    {
        Vector3 v1 = GetVector3Random();
        Vector3 v2 = GetVector3Random();
        cout << format("----------Vector3----------\n");
        cout << format("v1: {}\nv2: {}\n", v1, v2);

        cout << format("v1.LengthSquared() = {}\n", v1.LengthSquared());
        cout << format("v1.Length() = {}\n", v1.Length());
        cout << format("v1.DistanceSquared(v2) = {}\n", v1.DistanceSquared(v2));
        cout << format("v1.Distance(v2) = {}\n", v1.Distance(v2));
        cout << format("v1.Dot(v2) = {}\n", v1.Dot(v2));
        cout << format("v1.Cross(v2) = {}\n", v1.Cross(v2));
        cout << format("v1.Normalize() = {}\n", v1.Normalize());

        cout << format("Vector3::LengthSquared(v1) = {}\n", Vector3::LengthSquared(v1));
        cout << format("Vector3::Length(v1) = {}\n", Vector3::Length(v1));
        cout << format("Vector3::DistanceSquared(v1, v2) = {}\n", Vector3::DistanceSquared(v1, v2));
        cout << format("Vector3::Distance(v1, v2) = {}\n", Vector3::Distance(v1, v2));
        cout << format("Vector3::Dot(v1, v2) = {}\n", Vector3::Dot(v1, v2));
        cout << format("Vector3::Cross(v1, v2) = {}\n", Vector3::Cross(v1, v2));
        cout << format("Vector3::Normalize(v1) = {}\n", Vector3::Normalize(v1));
    }

    cout << '\n';

    {
        Vector4 v1 = GetVector4Random();
        Vector4 v2 = GetVector4Random();
        cout << format("----------Vector4----------\n");
        cout << format("v1: {}\nv2: {}\n", v1, v2);

        cout << format("v1.LengthSquared() = {}\n", v1.LengthSquared());
        cout << format("v1.Length() = {}\n", v1.Length());
        cout << format("v1.DistanceSquared(v2) = {}\n", v1.DistanceSquared(v2));
        cout << format("v1.Distance(v2) = {}\n", v1.Distance(v2));
        cout << format("v1.Dot(v2) = {}\n", v1.Dot(v2));
        cout << format("v1.Normalize() = {}\n", v1.Normalize());

        cout << format("Vector4::LengthSquared(v1) = {}\n", Vector4::LengthSquared(v1));
        cout << format("Vector4::Length(v1) = {}\n", Vector4::Length(v1));
        cout << format("Vector4::DistanceSquared(v1, v2) = {}\n", Vector4::DistanceSquared(v1, v2));
        cout << format("Vector4::Distance(v1, v2) = {}\n", Vector4::Distance(v1, v2));
        cout << format("Vector4::Dot(v1, v2) = {}\n", Vector4::Dot(v1, v2));
        cout << format("Vector4::Normalize(v1) = {}\n", Vector4::Normalize(v1));
    }

    cout << format("----------Function Test End!----------\n");
}
#pragma endregion

    cout << '\n';

#pragma region Conversion Operator Test
{
    cout << format("----------Conversion Test!----------\n");

    Vector2 v2 = GetVector2Random();
    Vector3 v3 = GetVector3Random();
    Vector4 v4 = GetVector4Random();

    cout << format("----------Conversion Vector2----------\n");
    cout << format("{} = Vector2({})\n", Vector2(v3), v3);
    cout << format("{} = Vector2({})\n", Vector2(v4), v4);
    cout << format("\n----------Conversion Vector3----------\n");
    cout << format("{} = Vector3({})\n", Vector3(v2), v2);
    cout << format("{} = Vector3({})\n", Vector3(v4), v4);
    cout << format("\n----------Conversion Vector4----------\n");
    cout << format("{} = Vector4({})\n", Vector4(v2), v2);
    cout << format("{} = Vector4({})\n", Vector4(v3), v3);

    cout << format("----------Conversion Test End!----------\n");
}
#pragma endregion
#endif

#ifdef MATRIX_TEST
#pragma region Constructor Test
    {
        cout << format("----------Constructor Test!----------\n");

        Matrix3x3 m3x3_1{ static_cast<float>(YS::Random(kMin, kMax)), static_cast<float>(YS::Random(kMin, kMax)), static_cast<float>(YS::Random(kMin, kMax)),
                          static_cast<float>(YS::Random(kMin, kMax)), static_cast<float>(YS::Random(kMin, kMax)), static_cast<float>(YS::Random(kMin, kMax)),
                          static_cast<float>(YS::Random(kMin, kMax)), static_cast<float>(YS::Random(kMin, kMax)), static_cast<float>(YS::Random(kMin, kMax)) };

        Matrix3x3 m3x3_2{ GetVector3Random(), GetVector3Random(), GetVector3Random() };

        cout << format("m3x3_1, init with elemets: {}\n", m3x3_1);
        cout << format("m3x3_2, init with colVectors: {}\n", m3x3_2);
        cout << format("----------Constructor Test End!----------\n");
    }
#pragma endregion

    cout << '\n';

#pragma region Operator Test
    {
        cout << format("----------Operator Test!----------\n");

        Matrix3x3 m3x3_1 = GetMatrix3x3Random();
        Matrix3x3 m3x3_2 = GetMatrix3x3Random();
        Vector3 v3 = GetVector3Random();
        YS::Float k = YS::Random(kMin, kMax);

        cout << format("{} + {} = {}\n", m3x3_1, m3x3_2, m3x3_1 + m3x3_2);
        cout << format("{} - {} = {}\n", m3x3_1, m3x3_2, m3x3_1 - m3x3_2);
        cout << format("{} * {} = {}\n", m3x3_1, m3x3_2, m3x3_1 * m3x3_2);
        cout << format("{} * {} = {}\n", m3x3_1, v3, m3x3_1 * v3);
        cout << format("{} * {} = {}\n", k, m3x3_2, k * m3x3_2);

        cout << format("m3x3_1: {}\n", m3x3_1);
        cout << format("m3x3_1 += {}\n", m3x3_1 += GetMatrix3x3Random());
        cout << format("m3x3_1: {}\n", m3x3_1);
        cout << format("m3x3_1 -= {}\n", m3x3_1 -= GetMatrix3x3Random());
        cout << format("m3x3_1: {}\n", m3x3_1);
        cout << format("m3x3_1 *= {}\n", m3x3_1 *= GetMatrix3x3Random());
        cout << format("m3x3_1: {}\n", m3x3_1);
        cout << format("m3x3_1 *= {}\n", m3x3_1 *= k);
        cout << format("m3x3_1: {}\n", m3x3_1);

        cout << format("{} == {} : {}\n", m1, m2, m1 == m2);
        cout << format("{} != {} : {}\n", m1, m2, m1 != m2);
        cout << format("{} == {} : {}\n", m1, m1, m1 == m1);
        cout << format("{} != {} : {}\n", m1, m1, m1 != m1);

        cout << format("----------Operator Test End!----------\n");
    }
#pragma endregion
#endif

    //for (int i = 0; i < 100; ++i)
    //{
    //    Matrix3x3 m1 = GetMatrix3x3Random();
    //    Matrix3x3 m2 = GetMatrix3x3Random();
    //    cout << format("{}\n{}\n\n", m1 * m2, BFMatrixMultiply(m1, m2));
    //}

    return 0;
}