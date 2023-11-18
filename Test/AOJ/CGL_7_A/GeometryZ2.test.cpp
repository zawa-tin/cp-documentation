#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_A"

#include "../../../Src/GeometryZ2/Circle.hpp"

#include <iostream>

int main() {
    using namespace zawa::geometryZ2;
    Circle a, b;
    std::cin >> a.center() >> a.radius();
    std::cin >> b.center() >> b.radius();
    std::cout << NumberCommonTangent(a, b) << '\n';
}
