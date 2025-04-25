#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include "../../Src/DataStructure/RectangleSum/RectangleSumOfPointCloud.hpp"

#include <iostream>
#include <vector>

using namespace zawa;

struct Point {
    using P = int;
    using W = long long;
    P x, y;
    W w;
};

struct Rect {
    using P = int;
    int l, d, r, u;
};

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int N, Q;
    std::cin >> N >> Q;
    std::vector<Point> ps(N);
    for (int i{} ; i < N ; i++) {
        int x, y, w;
        std::cin >> x >> y >> w;
        ps[i] = {x, y, w};
    }
    std::vector<Rect> qs(Q);
    for (int i{} ; i < Q ; i++) {
        int l, d, r, u;
        std::cin >> l >> d >> r >> u;
        qs[i] = {l, d, r, u};
    }
    for (auto ans : RectangleSumOfPointCloud(ps, qs)) {
        std::cout << ans << '\n';
    }
}
