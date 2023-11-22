#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_F"
#define ERROR 0.00001

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/GeometryR2/Point.hpp"
#include "../../Src/GeometryR2/Circle.hpp"
#include "../../Src/GeometryR2/Tangent/TangentToCircle.hpp"

#include <iostream>
#include <utility>

int main() {
    using namespace zawa;
    using namespace geometryR2;
    SetPrecision(7);
    Point p; std::cin >> p;
    Circle c; std::cin >> c.center() >> c.radius();
    auto tangent{TangentToCircle(c, p)};
    std::pair<Point, Point> ans{tangent.first.p0(), tangent.second.p0()};
    if (ans.first > ans.second) std::swap(ans.first, ans.second);
    std::cout << ans.first.x() << ' ' << ans.first.y() << '\n';
    std::cout << ans.second.x() << ' ' << ans.second.y() << '\n';
}
