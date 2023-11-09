#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_A"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/GeometryR2/Line.hpp"

#include <iostream>

int main() {
    using namespace zawa;
    using namespace geometryR2;
    SetFastIO();
    int q; std::cin >> q;
    for (int _{} ; _ < q ; _++) {
        Line l1, l2;
        std::cin >> l1.p0() >> l1.p1() >> l2.p0() >> l2.p1();
        if (Parallel(l1, l2)) std::cout << 2 << '\n';
        else if (Orthgonal(l1, l2)) std::cout << 1 << '\n';
        else std::cout << 0 << '\n';
    }
}
