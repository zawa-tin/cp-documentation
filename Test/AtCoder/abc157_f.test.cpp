#define PROBLEM "https://atcoder.jp/contests/abc157/tasks/abc157_f"
#define ERROR 0.000001

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Utility/BinarySearch.hpp"
#include "../../Src/GeometryR2/Point.hpp"
#include "../../Src/GeometryR2/Circle.hpp"
#include "../../Src/GeometryR2/Intersect/CircleAndCircle.hpp"
#include "../../Src/GeometryR2/CrossPoint/CircleAndCircle.hpp"
#include "../../Src/GeometryR2/Contain/CircleContainsPoint.hpp"

using namespace zawa;
using namespace geometryR2;

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    SetFastIO();
    SetPrecision(8);
    int n, k; std::cin >> n >> k;
    std::vector<Point> p(n);
    std::vector<Real> c(n);
    for (int i{} ; i < n ; i++) {
        std::cin >> p[i] >> c[i];
    }

    if (k == 1) {
        std::cout << 0 << '\n';
        return 0;
    }

    auto f{[&](Real t) -> bool {
        std::vector<Circle> circles(n);
        for (int i{} ; i < n ; i++) {
            circles[i] = Circle{p[i], t / c[i]};
        }
        std::vector<Point> cand{p};
        for (int i{} ; i < n ; i++) for (int j{i + 1} ; j < n ; j++) {
            if (!Intersect(circles[i], circles[j])) continue;
            auto v{CrossPoint(circles[i], circles[j])};
            cand.push_back(v.first);
            cand.push_back(v.second);
        }
        int max{};
        for (const auto& v : cand) {
            int cnt{};
            for (const auto& circle : circles) {
                cnt += CircleContainsPoint(circle, v) != OUTSIDE;
            }
            max = std::max(max, cnt);
        }
        return max >= k;
    }};

    Real ans{BinarySearch(Real{4000 * 100}, Real{}, f, 80)};
    std::cout << ans << '\n';
}
