#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2009"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/GeometryR2/Point.hpp"
#include "../../Src/GeometryR2/Polygon.hpp"
#include "../../Src/GeometryR2/Line.hpp"
#include "../../Src/GeometryR2/Intersect/LineAndLine.hpp"
#include "../../Src/GeometryR2/CrossPoint/LineAndLine.hpp"
#include "../../Src/GeometryR2/Contain/PolygonContainsPoint.hpp"

#include <iostream>
#include <vector>
#include <set>

using namespace zawa;
using namespace geometryR2;

bool contain(const Point& p) {
    static Polygon sq(4);
    sq[0] = Point{-100, -100};
    sq[1] = Point{100, -100};
    sq[2] = Point{100, 100};
    sq[3] = Point{-100, 100};
    return PolygonContainsPoint(sq, p) == INSIDE;
}

bool solve() {
    int n; std::cin >> n;
    if (n == 0) return false;
    std::vector<Line> l;
    l.reserve(n);
    int ans{1};
    for (int _{} ; _ < n ; _++) {
        Line a;
        std::cin >> a.p0() >> a.p1();
        std::set<Point> set;
        for (const auto line : l) {
            if (!Intersect(line, a)) continue;
            Point p{CrossPoint(line, a)};
            if (contain(p)) set.insert(p);
        }
        ans += set.size() + 1;
        l.push_back(a); 
    }
    std::cout << ans << '\n';
    return true;
}

int main() {
    SetFastIO();
    for (int i{} ; solve() ; i++) {

    }
}
