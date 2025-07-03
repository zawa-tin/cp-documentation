#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_B"
#define ERROR 0.000001

#include "../../Src/GeometryR2/InCircle.hpp"
using namespace zawa::geometryR2;

#include <iostream>
#include <iomanip>

int main() {
    Point p, q, r;
    std::cin >> p >> q >> r;
    auto ans = InCircle(p, q, r).value();
    std::cout << std::fixed << std::setprecision(8) << ans.center().x() << ' ' << ans.center().y() << ' ' << ans.radius() << '\n';
}
