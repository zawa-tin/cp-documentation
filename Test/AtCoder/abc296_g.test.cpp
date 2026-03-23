// #define PROBLEM "https://atcoder.jp/contests/abc296/tasks/abc296_g"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * AtCoder Beginner Contest 296 G - Polygon and Points
 * https://atcoder.jp/contests/abc296/submissions/74358438
 */

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/GeometryZ2/Point.hpp"
#include "../../Src/GeometryZ2/Polygon.hpp"
#include "../../Src/GeometryZ2/Contain/ConvexPolygonContainsPoint.hpp"

#include <cassert>
#include <iostream>

int main() {
#ifdef ATCODER
    using namespace zawa;
    using namespace zawa::geometryZ2;
    SetFastIO(); 
    int n; std::cin >> n;
    Polygon ps(n);
    std::cin >> ps;
    ps.normalForm();
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
#else
    std::cout << "Hello World\n";
#endif
}
