#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_B"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/GeometryR2/Segment.hpp"

int main() {
    using namespace zawa;
    using namespace geometryR2;

    int q; std::cin >> q;
    for (int _{} ; _ < q ; _++) {
        Segment s0, s1;
        std::cin >> s0.p0() >> s0.p1() >> s1.p0() >> s1.p1();
        std::cout << Intersect(s0, s1) << '\n';
    }
}
