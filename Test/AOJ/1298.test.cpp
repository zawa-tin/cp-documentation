#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/1298"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/GeometryZ2/PointCloud.hpp"
#include "../../Src/GeometryZ2/Polygon.hpp"
#include "../../Src/GeometryZ2/Relation.hpp"
#include "../../Src/GeometryZ2/Intersect/PolygonAndPolygon.hpp"
#include "../../Src/GeometryZ2/Contain/ConvexPolygonContainsPoint.hpp"
#include "../../Src/GeometryZ2/ConvexHull.hpp"

bool solve() {
    using namespace zawa::geometryZ2;
    int n, m; std::cin >> n >> m;
    if (n == 0 and m == 0) return false;
    PointCloud p(n), q(m);
    for (auto& v : p) std::cin >> v;
    for (auto& v : q) std::cin >> v;
    if (n == 1 and m == 1) {
        std::cout << "YES" << '\n';
    }
    else if (n == 1 or m == 1) {
        if (n == 1) {
            std::swap(n, m);
            std::swap(p, q);
        }
        auto h1{ConvexHull<true>(p)};
        if (h1.size() == 2u) {
            std::cout << (Relation(h1[0], q[0], h1[1]) != ONLINE_FRONT ? "YES" : "NO") << '\n';
        }
        else {
            std::cout << (ConvexPolygonContainsPoint(h1, q[0]) == OUTSIDE ? "YES" : "NO") << '\n';
        }
    }
    else {
        auto h1{ConvexHull<true>(p)}, h2{ConvexHull<true>(q)};
        if (h1.size() == 2u and h2.size() == 2u) {
            std::cout << (Intersect(Segment{h1[0],h1[1]}, Segment{h2[0],h2[1]}) ? "NO" : "YES") << '\n';
        }
        else if (h1.size() == 2u or h2.size() == 2u) {
            if (h1.size() == 2u) std::swap(h1, h2);
            bool ok{true};
            ok &= ConvexPolygonContainsPoint(h1, h1[0]) == OUTSIDE;
            ok &= ConvexPolygonContainsPoint(h1, h2[1]) == OUTSIDE;
            for (size_t i{} ; i < h1.size() ; i++) {
                ok &= !Intersect(Segment{h1[i], h1[(i+1)%h1.size()]}, Segment{h2[0],h2[1]});
            }
            std::cout << (ok ? "YES" : "NO") << '\n';
        }
        else {
            bool ok{true};
            for (int i{} ; i < (int)h1.size() ; i++) {
                ok &= ConvexPolygonContainsPoint(h2, h1[i]) == OUTSIDE;
            }
            for (int i{} ; i < (int)h2.size() ; i++) {
                ok &= ConvexPolygonContainsPoint(h1, h2[i]) == OUTSIDE;
            }
            for (int i{} ; i < (int)h1.size() ; i++) {
                for (int j{} ; j < (int)h2.size() ; j++) {
                    Segment s0{h1[i], h1[(i + 1) % h1.size()]};
                    Segment s1{h2[j], h2[(j + 1) % h2.size()]};
                    ok &= !Intersect(s0, s1);
                }
            }
            std::cout << (ok ? "YES" : "NO") << '\n';
        }
    }
    return true;
}

int main() {
    using namespace zawa;
    SetFastIO();
    while (solve()) ;
}
