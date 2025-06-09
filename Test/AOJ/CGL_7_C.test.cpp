#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_C"
#define ERROR 0.000001

#include "../../Src/GeometryR2/CircumscribedCircle.hpp"
using namespace zawa::geometryR2;

#include <cassert>
#include <iostream>
#include <iomanip>

int main() {
    Point p, q, r;
    std::cin >> p >> q >> r;
    auto ans = CircumscribedCircle(p, q, r);
    assert(ans);
    std::cout << std::fixed << std::setprecision(10) << 
        ans->center().x() << ' ' << ans->center().y() << ' ' << ans->radius() << '\n';
}
