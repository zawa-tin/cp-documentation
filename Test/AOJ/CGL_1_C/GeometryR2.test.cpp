#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_C"
#define ERROR 0.00000001

#include "../../../Src/GeometryR2/Point.hpp"
#include "../../../Src/GeometryR2/Relation.hpp"
#include "../../../Src/Template/IOSetting.hpp"

#include <iostream>

int main() {
    using namespace zawa;
    using namespace geometryR2;

    SetFastIO();
    Point p0, p1; std::cin >> p0 >> p1;
    int q; std::cin >> q;
    for (int _{} ; _ < q ; _++) {
        Point p2; std::cin >> p2;
        auto ans{Relation(p0, p1, p2)};
        if (ans == COUNTER_CLOCKWISE) std::cout << "COUNTER_CLOCKWISE\n";
        else if (ans == CLOCKWISE) std::cout << "CLOCKWISE\n";
        else if (ans == ONLINE_BACK) std::cout << "ONLINE_BACK\n";
        else if (ans == ONLINE_FRONT) std::cout << "ONLINE_FRONT\n";
        else std::cout << "ON_SEGMENT\n";
    }
}
