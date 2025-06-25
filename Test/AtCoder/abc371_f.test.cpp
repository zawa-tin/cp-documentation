// #define PROBLEM "https://atcoder.jp/contests/abc371/tasks/abc371_f"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/DataStructure/SegmentTree/LazySegmentTree.hpp"

/*
 * AtCoder Beginner Contest 371 F - Takahashi in Narrow Road
 * https://atcoder.jp/contests/abc371/submissions/67058774
 */

#include <iostream>
const int INF = (int)1e9;
struct VD {
    long long sum = 0;
    int cnt = 0, min = INF, max = -INF;
    VD() = default;
    VD(int v) : sum{v}, cnt{1}, min{v}, max{v} {}
    VD(int v, int c) : sum{(long long)v * c}, cnt{c}, min{v}, max{v} {}
    VD(long long s, int c, int mn, int mx) : sum{s}, cnt{c}, min{mn}, max{mx} {}
};
struct VM {
    using Element = VD;
    static Element identity() { return VD{}; }
    static Element operation(Element L, Element R) {
        L.sum += R.sum;
        L.cnt += R.cnt;
        L.min = std::min(L.min, R.min);
        L.max = std::max(L.max, R.max);
        return L;
    }
};
struct OM {
    using Element = int;
    static Element identity() { return INF; }
    static Element operation(Element L, Element R) {
        return R == INF ? L : R;
    }
};
struct S {
    using ValueMonoid = VM;
    using OperatorMonoid = OM;
    static VM::Element mapping(VM::Element L, OM::Element R) {
        if (R == INF) return L;
        return VM::Element{R, L.cnt};
    }
};
long long solve() {
    int N;
    std::cin >> N;
    std::vector<VD> init(N);
    for (int i = 0 ; i < N ; i++) {
        int x;
        std::cin >> x;
        init[i] = VD{x - i};
    }
    zawa::LazySegmentTree<S> seg{init};
    int Q;
    std::cin >> Q;
    long long ans = 0;
    while (Q--) {
        int T, G;
        std::cin >> T >> G;
        T--;
        G -= T;
        const int cur = seg[T].min;
        if (G < cur) {
            const auto l = seg.minLeft(T + 1, [&](const VD& v) { return G <= v.min; });
            const auto prod = seg.product(l, T + 1);
            ans += prod.sum - (long long)G * prod.cnt;
            seg.operation(l, T + 1, G);
        }
        else if (cur < G) {
            const auto r = seg.maxRight(T, [&](const VD& v) { return v.max <= G; });
            const auto prod = seg.product(T, r);
            ans += (long long)G * prod.cnt - prod.sum;
            seg.operation(T, r, G);
        }
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
