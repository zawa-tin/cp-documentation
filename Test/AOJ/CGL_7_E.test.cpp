#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_E"
#define ERROR 0.000001

#include "../../Src/GeometryR2/Point.hpp"
#include "../../Src/GeometryR2/Circle.hpp"
#include "../../Src/GeometryR2/Intersect/CircleAndCircle.hpp"
#include "../../Src/GeometryR2/CrossPoint/CircleAndCircle.hpp"
#include "../../Src/Template/IOSetting.hpp"

int main() {
    using namespace zawa;
    using namespace geometryR2;
    SetFastIO();
    SetPrecision(10);
    Real x1, y1, r1; std::cin >> x1 >> y1 >> r1;
    Real x2, y2, r2; std::cin >> x2 >> y2 >> r2;
    Circle c1{x1, y1, r1}, c2{x2, y2, r2};
    auto ans{CrossPoint(c1, c2)};
    if (ans.first > ans.second) std::swap(ans.first, ans.second);
    std::cout << ans.first.x() << ' ' << ans.first.y() << ' ' << ans.second.x() << ' ' << ans.second.y() << '\n';
}
