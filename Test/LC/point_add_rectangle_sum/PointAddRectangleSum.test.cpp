#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include "../../../Src/Template/IOSetting.hpp"
#include "../../../Src/DataStructure/RectangleSum/PointAddRectangleSum.hpp"

#include <cassert>
#include <iostream>

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
    SetFastIO();
    int N, Q;
    std::cin >> N >> Q;
    PointAddRectangleSum<Point, Rect> solver;
    for (int i{} ; i < N ; i++) {
        int x, y, w;
        std::cin >> x >> y >> w;
        solver.add({x, y, w});
    }
    while (Q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int x, y, w;
            std::cin >> x >> y >> w;
            solver.add({x, y, w});
        }
        else if (t == 1) {
            int l, d, r, u;
            std::cin >> l >> d >> r >> u;
            solver.product({l, d, r, u});
        }
        else {
            assert(false);
        }
    }
    for (auto ans : solver.execute()) {
        std::cout << ans << '\n';
    }
}
