#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_I"
#define ERROR 0.000001

#include "../../Src/GeometryR2/CommonArea/CircleAndCircle.hpp"
using namespace zawa::geometryR2;

#include <iostream>
#include <iomanip>

int main() {
    Circle c1, c2;
    std::cin >> c1.center() >> c1.radius();
    std::cin >> c2.center() >> c2.radius();
    std::cout << std::fixed << std::setprecision(8) << CommonArea(c1, c2) << '\n';
}
