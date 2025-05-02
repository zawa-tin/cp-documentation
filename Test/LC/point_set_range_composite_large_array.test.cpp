#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite_large_array"

#include "../../Src/Algebra/Monoid/AffineMonoid.hpp"
#include "../../Src/DataStructure/SegmentTree/SparseSegmentTree.hpp"
#include "atcoder/modint"
using namespace zawa;
using mint = atcoder::modint998244353;

#include <cassert>
#include <iostream>

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int N, Q;
    std::cin >> N >> Q;
    using M = AffineMonoid<mint>;
    using V = M::Element;
    SparseSegmentTree<M> seg(N, Q);
    while (Q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int p, c, d;
            std::cin >> p >> c >> d;
            seg.set(p, V{mint{c}, mint{d}});
        }
        else if (t == 1) {
            int l, r, x;
            std::cin >> l >> r >> x;
            std::cout << seg.product(l, r)(x).val() << '\n';
        }
        else assert(false);
    }
}
