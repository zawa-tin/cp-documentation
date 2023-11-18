#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/1157"
#define ERROR 0.001

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/GeometryR2/Real.hpp"
#include "../../Src/GeometryR2/Point.hpp"
#include "../../Src/GeometryR2/Segment.hpp"
#include "../../Src/GeometryR2/Polygon.hpp"
#include "../../Src/GeometryR2/Intersect/PolygonAndSegment.hpp"
#include "../../Src/GeometryR2/Contain/PolygonContainsPoint.hpp"
#include "../../Src/GeometryR2/Distance/SegmentAndSegment.hpp"

#include <algorithm>
#include <iostream>

using namespace zawa;
using namespace geometryR2;

bool solve() {
    int n; std::cin >> n;
    if (n == 0) return false;
    Segment s;
    std::cin >> s.p0() >> s.p1();
    const Real INF{1e18};
    Real ans{INF};
    for (int _{} ; _ < n ; _++) {
        Polygon p;
        Point min, max; std::cin >> min >> max;
        p.emplaceBack(min.x(), min.y());
        p.emplaceBack(max.x(), min.y());
        p.emplaceBack(max.x(), max.y());
        p.emplaceBack(min.x(), max.y());
        Real h; std::cin >> h;
        if (Intersect(p, s)) {
            ans = 0;
            continue;
        }
        if (PolygonContainsPoint(p, s.p0()) == INSIDE and PolygonContainsPoint(p, s.p1()) == INSIDE) {
            ans = 0;
            continue;
        }
        Real dist{INF};
        for (size_t i{} ; i < p.size() ; i++) {
            Segment seg{p[i], p[i+1==p.size()?0u:i+1]};
            dist = std::min(dist, Distance(seg, s));
        }
        if (!Smaller(h, dist)) {
            ans = std::min(ans, dist);
        }
        else {
            Real value{(dist*dist + h*h)/(2*h)};
            ans = std::min(ans, value);
        }
    }
    std::cout << ans << '\n';
    return true;
}

int main() {
    SetFastIO();
    SetPrecision(5);
    for (int i{} ; solve() ; i++) {
    }
}
