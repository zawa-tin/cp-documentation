#define PROBLEM "https://atcoder.jp/contests/abc259/tasks/abc259_b"

#include "../../Src/GeometryR2/Point.hpp"
#include "../../Src/Template/IOSetting.hpp"

#include <iostream>

int main() {
    using namespace zawa;
    using namespace geometryR2;
    Point p; std::cin >> p;
    int d; std::cin >> d;
    p.rotateByArc(d);
    SetPrecision(10);
    std::cout << p.x() << ' ' << p.y() << '\n';
}
