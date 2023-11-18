#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_C"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/GeometryR2/Point.hpp"
#include "../../Src/GeometryR2/Polygon.hpp"
#include "../../Src/GeometryR2/Contain/PolygonContainsPoint.hpp"

int main() {
    using namespace zawa;
    using namespace geometryR2;
    SetFastIO();
    int n; std::cin >> n;
    Polygon ps(n);
    std::cin >> ps;
    int q; std::cin >> q;
    for (int _{} ; _ < q ; _++) {
        Point p; std::cin >> p;
        auto ans{PolygonContainsPoint(ps, p)};
        std::cout << (ans == INSIDE ? 2 : (ans == ONLINE ? 1 : 0)) << '\n';
    }
}
