#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_A"
#define ERROR 0.00000001

#include "../../Src/GeometryR2/Point.hpp"
#include "../../Src/GeometryR2/Line.hpp"
#include "../../Src/GeometryR2/Projection.hpp"
#include "../../Src/Template/IOSetting.hpp"

#include <iostream>

int main() {
    using namespace zawa;
    using namespace geometryR2;

    SetFastIO();
    SetPrecision(10);
    Line line{};
    std::cin >> line.p0() >> line.p1();
    int q; std::cin >> q;
    for (int _{} ; _ < q ; _++) {
        Point p{}; std::cin >> p;
        Point ans{Projection(p, line)};
        std::cout << ans.x() << ' ' << ans.y() << '\n';
    }
}
