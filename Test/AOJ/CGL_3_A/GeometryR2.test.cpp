#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_A"

#include "../../../Src/Template/IOSetting.hpp"
#include "../../../Src/GeometryR2/Polygon.hpp"

#include <iostream>

int main() {
    using namespace zawa;
    using namespace geometryR2;
    SetFastIO();
    SetPrecision(1);
    int n; std::cin >> n;
    Polygon ps(n);
    std::cin >> ps;
    Real area{ps.area()};
    std::cout << area << '\n';
}
