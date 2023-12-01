#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_A"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/GeometryZ2/ConvexHull.hpp"
#include "../../Src/GeometryZ2/Point.hpp"
#include "../../Src/GeometryZ2/PointCloud.hpp"
#include "../../Src/GeometryZ2/Polygon.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    using namespace zawa;
    using namespace geometryZ2;
    SetFastIO();
    int n; std::cin >> n;
    PointCloud p(n);
    for (auto& v : p) std::cin >> v;

    auto hull{ConvexHull<false>(p)};
    hull.normalForm([&](const Point& a, const Point& b) -> bool {
            if (a.y() != b.y()) return a.y() < b.y();
            else return a.x() < b.x();
            });    
    std::cout << hull.size() << '\n';
    for (size_t i{} ; i < hull.size() ; i++) {
        std::cout << hull[i].x() << ' ' << hull[i].y() << '\n';
    }
}
