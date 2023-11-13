#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_C"
#define ERROR 0.00000001

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/GeometryR2/Segment.hpp"
#include "../../Src/GeometryR2/CrossPoint/SegmentAndSegment.hpp"

#include <iostream>

int main() {
    using namespace zawa;
    using namespace geometryR2;
    SetFastIO();
    SetPrecision(10);
    int q; std::cin >> q;
    for (int _{} ; _ < q ; _++) {
        Segment s0, s1;
        std::cin >> s0.p0() >> s0.p1() >> s1.p0() >> s1.p1();
        Point ans{CrossPoint(s0, s1)};
        std::cout << ans.x() << ' ' << ans.y() << '\n';
    }
}
