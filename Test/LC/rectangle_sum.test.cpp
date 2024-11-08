#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include "../../Src/DataStructure/RectangleSum/StaticPointAddRectangleSum.hpp"
#include "../../Src/Template/IOSetting.hpp"

#include <iostream>
#include <vector>

using namespace zawa;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int N, Q;
    std::cin >> N >> Q;
    std::vector<RSPoint<int, long long>> ps(N);
    for (int i{} ; i < N ; i++) {
        int x, y, w;
        std::cin >> x >> y >> w;
        ps[i] = {x, y, w};
    }
    std::vector<RSQuery<int>> qs(Q);
    for (int i{} ; i < Q ; i++) {
        int l, d, r, u;
        std::cin >> l >> d >> r >> u;
        qs[i] = {l, d, r, u};
    }
    for (auto ans : StaticPointAddRectangleSum(ps, qs)) {
        std::cout << ans << '\n';
    }
}
