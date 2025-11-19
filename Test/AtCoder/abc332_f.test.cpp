// #define PROBLEM "https://atcoder.jp/contests/abc332/tasks/abc332_f"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/DataStructure/SegmentTree/DualSegmentTree.hpp"
#include "../../Src/Algebra/Monoid/AffineMonoid.hpp"

/*
 * AtCoder Beginner Contest 332 F - Random Update Query
 * https://atcoder.jp/contests/abc332/submissions/71071551
 */

#include <iostream>
#include <vector>

using namespace zawa;
#include "atcoder/modint"
using mint = atcoder::modint998244353;
void solve() {
    int N, M;
    std::cin >> N >> M;
    std::vector<Affine<mint>> init(N);
    for (int i = 0 ; i < N ; i++) {
        int A;
        std::cin >> A;
        init[i] = Affine{mint{}, mint{A}};
    }
    DualSegmentTree<AffineMonoid<mint>> seg{init};
    while (M--) {
        int L, R, X;
        std::cin >> L >> R >> X;
        L--;
        mint inv = mint::raw(R - L).inv();
        seg.operation(L, R, Affine{mint::raw(R-L-1)*inv, mint::raw(X)*inv});
    }
    for (int i = 0 ; i < N ; i++) std::cout << seg[i].b().val() << (i + 1 == N ? '\n' : ' ');
}
int main() {
#ifdef ATCODER
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    solve();
#else
    std::cout << "Hello World\n";
#endif
}
