#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/5/CGL_5_B"
#define ERROR 0.000001

#include "../../Src/GeometryR2/Contain/SmallestEnclosingDisc.hpp"
using namespace zawa;
using namespace geometryR2;

#include <iostream>
#include <iomanip>

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int N;
    std::cin >> N;
    PointCloud P(N);
    for (auto& p : P) std::cin >> p;
    auto ans = SmallestEnclosingDisc(P);
    std::cout << std::fixed << std::setprecision(8) << ans.center().x() << ' ' << ans.center().y() << ' ' << ans.radius() << '\n';
}
