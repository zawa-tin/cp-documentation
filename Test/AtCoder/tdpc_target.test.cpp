// #define PROBLEM "https://atcoder.jp/contests/tdpc/tasks/tdpc_target"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * Typical DP Contest K - ターゲット
 * https://atcoder.jp/contests/tdpc/submissions/66823999
 * (verifyのための非想定解)
 */

#include "../../Src/DataStructure/SegmentTree/OfflineSegmentTree2D.hpp"
using namespace zawa;

#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <ranges>

struct M {
    using Element = int;
    static Element identity() { return 0; }
    static Element operation(Element L, Element R) { return std::max(L, R); }
};

int solve() {
    int N;
    std::cin >> N;
    std::vector<std::pair<int, int>> RX(N);
    for (auto& [r, x] : RX) std::cin >> x >> r;
    std::ranges::sort(RX);
    const int MAX = 100000000;
    OfflineSegmentTree2D<int, M> segL(N), segR(N);
    for (int i = 0 ; i < N ; i++) {
        const auto [r, x] = RX[i];
        segL.operation(x, r + MAX - x);
        segR.operation(x, r + x);
    }
    auto exeL = segL.build(), exeR = segR.build();
    int ans = 0;
    for (const auto& [r, x] : RX) {
        const int v = std::max(
                exeL.product(0, 0, x, r + MAX - x),
                exeR.product(x, 0, 2*MAX+1, r + x)
                ) + 1;
        ans = std::max(v, ans);
        exeL.operation(x, r + MAX - x, v);
        exeR.operation(x, r + x, v);
    }
    return ans;
}

int main() {
#ifdef ATCODER
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::cout << solve() << '\n';
#else
    std::cout << "Hello World\n";
#endif
}
