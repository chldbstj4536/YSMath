#include <iostream>
#include <format>
#include <YSMath/ysVector.hpp>

using namespace YS::Math;
using namespace std;

int main()
{
    Vector2 v2(1.0f, 2.0f);
    Vector3 v3(2.0f, 3.0f, 4.0f);
    Vector4 v4(2.0f, 3.0f, 4.0f, 5.0f);

    cout << format("v2: {}\n", v2);
    cout << format("v3: {}\n", v3);
    cout << format("v4: {}\n", v4);

    return 0;
}