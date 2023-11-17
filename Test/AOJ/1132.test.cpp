#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/1132"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/GeometryR2/Point.hpp"
#include "../../Src/GeometryR2/Circle.hpp"
#include "../../Src/GeometryR2/Distance/PointAndPoint.hpp"
#include "../../Src/GeometryR2/Bisector/PerpendicularBisector.hpp"
#include "../../Src/GeometryR2/Contain/CircleContainsPoint.hpp"

using namespace zawa;
using namespace geometryR2;

#include <iostream>
#include <vector>

bool solve() {
    int n; std::cin >> n;
    if (n == 0) return false;
    std::vector<Point> ps(n);
    for (auto& p : ps) std::cin >> p;
    auto f{[&](const Circle& c) -> int {
        int res{};
        for (auto p : ps) res += CircleContainsPoint(c, p) != OUTSIDE;
        return res;
    }};
    int ans{1};
    for (int i{} ; i < n ; i++) for (int j{i + 1} ; j < n ; j++) {
        if (Bigger(Distance(ps[i], ps[j]), Real{2})) continue;
        Segment seg{ps[i], ps[j]};
        Point mid{seg.midpoint()};
        Vector dir{PerpendicularBisector(seg).slope()};
        Real len{Sqrt(Real{1} - DistanceSquare(mid, ps[i]))};
        ans = std::max(ans, f(Circle{mid + len * dir, Real{1}}));
        ans = std::max(ans, f(Circle{mid - len * dir, Real{1}}));
    }
    std::cout << ans << '\n';
    return true;
}

int main() {
    SetFastIO(); 
    for (int i{} ; solve() ; i++) {

    }
}
