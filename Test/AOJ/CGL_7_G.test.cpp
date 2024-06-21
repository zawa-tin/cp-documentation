#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_7_G"
#define ERROR 0.000001

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/GeometryR2/Circle.hpp"
#include "../../Src/GeometryR2/Tangent/CommonTangentBetweenCircles.hpp"

#include <iostream>
#include <utility>

int main() {
    using namespace zawa;
    using namespace geometryR2;
    SetFastIO();
    SetPrecision(8);
    Circle c0, c1;
    std::cin >> c0.center() >> c0.radius();
    std::cin >> c1.center() >> c1.radius();
    auto ans{CommonTangentBetweenCircles(c0, c1)};
    // ソート
    for (int i{} ; i < (int)ans.size() ; i++) {
        int min{i};
        for (int j{i + 1} ; j < (int)ans.size() ; j++) {
            if (ans[j].p0() < ans[min].p0()) {
                min = j;
            }
        }
        if (i != min) {
            std::swap(ans[i], ans[min]);
        }
        std::cout << ans[i].p0().x() << ' ' << ans[i].p0().y() << '\n';
    }
}
