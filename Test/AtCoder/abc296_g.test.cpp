#define PROBLEM "https://atcoder.jp/contests/abc296/tasks/abc296_g"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/GeometryZ2/Point.hpp"
#include "../../Src/GeometryZ2/Polygon.hpp"
#include "../../Src/GeometryZ2/Contain/ConvexPolygonContainsPoint.hpp"

#include <cassert>
#include <iostream>

int main() {
    using namespace zawa;
    using namespace zawa::geometryZ2;
    SetFastIO(); 
    int n; std::cin >> n;
    Polygon ps(n);
    std::cin >> ps;
    ps.headMinimize();
    assert(ps.isConvex());
    int q; std::cin >> q;
    for (int _{} ; _ < q ; _++) {
        Point p; std::cin >> p;
        auto ans{ConvexPolygonContainsPoint(ps, p)};
        if (ans == INSIDE) {
            std::cout << "IN\n";
        }
        else if (ans == ONLINE) {
            std::cout << "ON\n";
        }
        else {
            std::cout << "OUT\n";
        }
    }
}
