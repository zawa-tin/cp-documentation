#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2862"

#include "../../Src/GeometryR2/Real.hpp"
#include "../../Src/GeometryR2/Segment.hpp"
#include "../../Src/GeometryR2/Circle.hpp"
#include "../../Src/GeometryR2/Distance/PointAndSegment.hpp"

#include <iostream>
#include <vector>

using namespace zawa::geometryR2;

int main() {
    int n; std::cin >> n;
    std::vector<Real> r(n);
    std::vector<Point> s(n), t(n);
    for (int i{} ; i < n ; i++) {
        std::cin >> r[i] >> s[i] >> t[i];
    }
    std::vector<bool> dp((1 << n));
    dp[0] = true;
    for (int bit{} ; bit < (1 << n) ; bit++) {
        if (!dp[bit]) continue;
        for (int i{} ; i < n ; i++) if (!(bit & (1 << i))) {
            Segment seg{s[i], t[i]};
            bool can{true};
            for (int j{} ; j < n ; j++) if (i != j) {
                Circle c{(bit & (1 << j)) ? t[j] : s[j], r[j]};
                Real dist{Distance(c.center(), seg)};
                can &= Bigger(dist, c.radius() + r[i]);
            }
            if (can) dp[bit | (1 << i)] = true;
        }
    }
    int ans{};
    for (int bit{} ; bit < (1 << n) ; bit++) if (dp[bit]) {
        ans = std::max(ans, __builtin_popcount(bit));
    }
    std::cout << ans << '\n';
}
