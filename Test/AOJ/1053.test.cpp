#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/1053"
#define ERROR 0.000001

#include "../../Src/GeometryR2/Real.hpp"
#include "../../Src/GeometryR2/Segment.hpp"
#include "../../Src/GeometryR2/Point.hpp"
#include "../../Src/GeometryR2/Circle.hpp"
#include "../../Src/GeometryR2/Distance/PointAndPoint.hpp"
#include "../../Src/GeometryR2/Distance/PointAndSegment.hpp"
#include "../../Src/GeometryR2/CrossPoint/CircleAndLine.hpp"
#include "../../Src/GeometryR2/Reflection.hpp"

#include <algorithm>
#include <iostream>
#include <iomanip>

bool solve() {
    using namespace zawa::geometryR2;
    Real d; std::cin >> d;
    if (Zero(d)) return false;
    Point p; std::cin >> p;
    Vector v; std::cin >> v;
    v.normalize();
    Circle R{Point{0, 0}, 1};

    auto getCrossPoint{[&](const Line& l) -> Point {
        auto cp{CrossPoint(R, l)};
        if (cp.first == p) return cp.second;
        if (cp.second == p) return cp.first;
        if (Positive(Dot(v, cp.first - p))) return cp.first;
        return cp.second;
    }};

    auto getEnd{[&](const Point& cp) -> Point {
        Real len{std::min(Distance(cp, p), d)};
        return p + v * len;
    }};

    auto reflect{[&](const Point& collision) -> void {
        Vector dir{Vector(collision - R.center()).rotatedByArc(90)};
        Line ref{collision, collision - dir};
        R.center() = Reflection(R.center(), ref);
    }};

    Real ans{};

    while (Positive(d)) {
        Line line{p, p + v};
        auto collision{getCrossPoint(line)};
        auto end{getEnd(collision)};
        if (PointOnSegment(R.center(), Segment{p, end})) {
            Real dist{Distance(Point{0, 0}, p)};
            ans += dist;
            break;
        }
        d -= Distance(end, p);
        ans += Distance(end, p);
        reflect(end);
        p = end;
    }

    if (!Zero(d)) {
        std::cout << ans << '\n';
    }
    else {
        std::cout << "impossible\n";
    }

    return true;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(7);

    for (int i{} ; solve() ; i++) {

    }
}
