#define PROBLEM "https://judge.yosupo.jp/problem/sort_points_by_argument"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/GeometryZ2/PointCloud.hpp"

int main() {
    using namespace zawa;
    using namespace geometryZ2;
    SetFastIO();
    int n; std::cin >> n;
    PointCloud p(n);
    for (auto& v : p) std::cin >> v;
    ArgSort(p);
    for (const auto& v : p) std::cout << v.x() << ' ' << v.y() << '\n';
}
