#define PROBLEM "https://atcoder.jp/contests/abc139/tasks/abc139_f"
#define ERROR 0.0000000001

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/GeometryZ2/PointCloud.hpp"
#include "../../Src/GeometryZ2/Point.hpp"

#include <algorithm>
#include <cmath>
#include <iostream>

int main() {
    using namespace zawa;
    using namespace geometryZ2;
    SetFastIO();
    SetPrecision(12);
    int n; std::cin >> n;
    PointCloud p(n);
    for (auto& v : p) std::cin >> v;
    ArgSort(p);
    Zahlen ans{};
    for (int i{} ; i < n ; i++) {
        Point now{};
        for (int j{} ; j < n ; j++) {
            now += p[i + j >= n ? i + j - n : i + j];
            ans = std::max(ans, now.normSquare());
        }
    }
    std::cout << sqrtl(ans) << '\n';
}
