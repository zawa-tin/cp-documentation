#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2003"

#include "../../Src/GeometryR2/Real.hpp"
#include "../../Src/GeometryR2/Segment.hpp"
#include "../../Src/GeometryR2/Distance/PointAndPoint.hpp"
#include "../../Src/GeometryR2/Distance/PointAndSegment.hpp"
#include "../../Src/GeometryR2/Intersect/SegmentAndSegment.hpp"
#include "../../Src/GeometryR2/CrossPoint/SegmentAndSegment.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

using namespace zawa::geometryR2;

struct item {
    Segment seg{};
    int have{};
    int h{};
    item() = default;
};

void solve() {
    Segment s;
    std::cin >> s.p0() >> s.p1(); 
    int n; std::cin >> n;
    std::vector<item> a(n);
    for (auto& i : a) {
        std::cin >> i.seg.p0() >> i.seg.p1();
        std::cin >> i.have >> i.h;
    }
    std::vector<Point> cross(n);
    std::vector<int> index;
    for (int i{} ; i < n ; i++) {
        if (a[i].seg.valid()) {
            if (!Intersect(s, a[i].seg)) continue;
            cross[i] = CrossPoint(s, a[i].seg);
            index.emplace_back(i);
        }
        else {
            if (!PointOnSegment(a[i].seg.p0(), s)) continue;
            cross[i] = a[i].seg.p0();
            index.emplace_back(i);
        }
    }
    std::sort(index.begin(), index.end(), [&](int i, int j) -> bool {
            return Smaller(Distance(s.p0(), cross[i]), Distance(s.p0(), cross[j]));
            });
    int dp[2]{0,0};
    for (auto i : index) {
        int nxt[2]{100000,100000};
        if (a[i].have == 0) {
            if (a[i].h == 0) {
                nxt[1] = std::min(dp[0] + 1, dp[1]);
            }
            else {
                nxt[0] = std::min(dp[0], dp[1] + 1);
            }
        }
        else {
            if (a[i].h == 0) {
                nxt[0] = std::min(dp[0], dp[1] + 1);
            }
            else {
                nxt[1] = std::min(dp[0] + 1, dp[1]);
            }
        }
        dp[0] = nxt[0];
        dp[1] = nxt[1];
    }
    int ans{std::min(dp[0], dp[1])};
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n; std::cin >> n;
    for (int i{} ; i < n ; i++) {
        solve();
    }
}
