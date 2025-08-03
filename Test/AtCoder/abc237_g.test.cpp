// #define PROBLEM "https://atcoder.jp/contests/abc237/tasks/abc237_g"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * AtCoder Beginner Contest 237 G - Range Sort Query
 * https://atcoder.jp/contests/abc237/submissions/68181908
 */

#include "../../Src/DataStructure/SegmentTree/AssignmentSegmentTree.hpp"
#include "../../Src/Template/TypeAlias.hpp"
using namespace zawa;

struct M {
    using Element = int;
    static constexpr int identity() {
        return 0;
    }
    static constexpr int operation(int l, int r) {
        return l + r;
    }
    static constexpr int power(int v, u64 exp) {
        return v * (int)exp;
    }
};

#include <iostream>

void solve() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int N, Q, X;
    std::cin >> N >> Q >> X;
    std::vector<int> init(N);
    for (int i = 0 ; i < N ; i++) {
        int P;
        std::cin >> P;
        init[i] = (P < X ? 0 : (P == X ? 1 : 2));
    }
    AssignmentSegmentTree<M> seg{init};
    int z = 0, o = 0, t = 0;
    auto prod = [&](int l, int r) -> void {
        int sum = seg.product(l, r);
        o = sum % 2;
        t = sum / 2;
        z = r - l - o - t;
        assert(o + t + z == r - l);
    };
    while (Q--) {
        int C, L, R;
        std::cin >> C >> L >> R;
        L--;
        prod(L, R);
        if (C == 1) {
            seg.assign(L, L + z, 0);
            seg.assign(L + z, L + z + o, 1);
            seg.assign(L + z + o, L + z + o + t, 2);
        }
        else if (C == 2) {
            seg.assign(L, L + t, 2);
            seg.assign(L + t, L + t + o, 1);
            seg.assign(L + t + o, L + t + o + z, 0);
        }
        else assert(false);
    }
    for (int i = 0 ; i < N ; i++) if (seg.product(0, i + 1) % 2) {
        std::cout << i + 1 << '\n';
        return;
    }
}

int main() {
#ifdef ATCODER
    solve();
#else
    std::cout << "Hello World\n";
#endif    
}
