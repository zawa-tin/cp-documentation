#define PROBLEM "https://judge.yosupo.jp/problem/static_convex_hull"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/GeometryZ2/Point.hpp"
#include "../../Src/GeometryZ2/PointCloud.hpp"
#include "../../Src/GeometryZ2/ConvexHull.hpp"

#include <iostream>

using namespace zawa;
using namespace geometryZ2;

int main() {
    SetFastIO();
    int T;
    std::cin >> T;
    while (T--) {
        int N;
        std::cin >> N;
        PointCloud P(N);
        for (auto& p : P) std::cin >> p;        
        auto ans{ConvexHull<true>(P)};
        std::cout << ans.size() << '\n';
        for (int i{} ; i < (int)ans.size() ; i++) {
            std::cout << ans[i].x() << ' ' << ans[i].y() << '\n';
        }
    }
}
