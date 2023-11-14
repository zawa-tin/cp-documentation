#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_D"
#define ERROR 0.000001

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/GeometryR2/Circle.hpp"
#include "../../Src/GeometryR2/Line.hpp"
#include "../../Src/GeometryR2/CrossPoint/CircleAndLine.hpp"

#include <iostream>
#include <utility>

int main() {
    using namespace zawa;
    using namespace geometryR2;
    SetFastIO();
    SetPrecision(12);
    Circle c;
    std::cin >> c.center() >> c.radius();
    int q; std::cin >> q;
    for (int _{} ; _ < q ; _++) {
        Line l; std::cin >> l.p0() >> l.p1();
        auto [p, q]{CrossPoint(c, l)};
        if (p > q) std::swap(p, q);
        std::cout << p.x() << ' ' << p.y() << ' ' << q.x() << ' ' << q.y() << '\n';
    }
}
