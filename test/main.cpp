#include <iostream>
#include <YSMath/ysVector.hpp>

using namespace YS::Math;
using namespace std;

int main()
{
    Vector2 v1(2.5f, 2.5f);
    Vector2 v2(2.5f, 3.5f);

    cout << v1.Distance(v2);

    return 0;
}