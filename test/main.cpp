#include <iostream>
#include <format>
#include <YSMath/ysVector.hpp>
#include <ysUtility.hpp>

using namespace YS::Math;
using namespace std;

static const int kMin = -50.0f;
static const int kMax = 50.0f;

Vector2 GetVector2Random() { return Vector2(YS::Random(kMin, kMax), YS::Random(kMin, kMax)); }
Vector3 GetVector3Random() { return Vector3(YS::Random(kMin, kMax), YS::Random(kMin, kMax), YS::Random(kMin, kMax)); }
Vector4 GetVector4Random() { return Vector4(YS::Random(kMin, kMax), YS::Random(kMin, kMax), YS::Random(kMin, kMax), YS::Random(kMin, kMax)); }

int main()
{
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
    }

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
    return 0;
}