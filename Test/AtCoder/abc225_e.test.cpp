#define PROBLEM "https://atcoder.jp/contests/abc225/tasks/abc225_e"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/GeometryZ2/Point.hpp"
#include "../../Src/GeometryZ2/PointCloud.hpp"

int main() {
    using namespace zawa;
    using namespace geometryZ2;
    SetFastIO();
    int n; std::cin >> n;
    PointCloud p(n);
    for (auto& v : p) std::cin >> v;
    for (auto& v : p) v.x()--;
    ArgSort(p);
    int ans{1};
    Point now{p[0]};
    for (int i{1} ; i < n ; i++) {
        Point tar{p[i] + Point{1, -1}};
        if (Cross(now, tar) >= 0) {
            ans++;
            now = p[i];
        }
    }
    std::cout << ans << '\n';
}
