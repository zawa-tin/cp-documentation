#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/0412"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/GeometryR2/Point.hpp"
#include "../../Src/GeometryR2/Polygon.hpp"
#include "../../Src/GeometryR2/Contain/ConvexPolygonContainsPoint.hpp"

int main() {
    using namespace zawa;
    using namespace geometryR2;
    Eps() = 5e-3;
    SetFastIO();
    int n; std::cin >> n;
    Polygon P(n);
    std::cin >> P;
    assert(P.isConvex());
    P.normalForm();
    int q; std::cin >> q;
    Real ratio{static_cast<Real>(1000000 - 100) / static_cast<Real>(1000000)};
    for (int _{} ; _ < q ; _++) {
        Real x, y; std::cin >> x >> y;
        x *= ratio;
        y *= ratio;
        Point p{x, y};
        auto state{ConvexPolygonContainsPoint(P, p)};
        std::cout << (state == OUTSIDE ? 0 : 1) << '\n';
    }
}
