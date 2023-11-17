#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_B"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/GeometryZ2/Polygon.hpp"

#include <iostream>

int main() {
    using namespace zawa;
    using namespace geometryZ2;
    SetFastIO();
    int n; std::cin >> n;
    Polygon ps(n); 
    std::cin >> ps;
    std::cout << ps.isConvex() << '\n';
}
