#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_point_get"

#include "../../Src/DataStructure/SegmentTree/DualSegmentTree.hpp"
#include "../../Src/Algebra/Monoid/AffineMonoid.hpp"

#include "atcoder/modint"

#include <iostream>
#include <cassert>

int main() {
    using namespace zawa;
    using mint = atcoder::modint998244353;
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, q; std::cin >> n >> q;
    std::vector<mint> a(n);
    for (auto& x : a) {
        int v;
        std::cin >> v;
        x = mint{v};
    }
    DualSegmentTree<AffineMonoid<mint>> seg(n);
    for (int _{} ; _ < q ; _++) {
        int t; std::cin >> t;
        if (t == 0) {
            int l, r, b, c; 
            std::cin >> l >> r >> b >> c;
            seg.operation(l, r, Affine{ mint{b}, mint{c} });
        }
        else if (t == 1) {
            int i; std::cin >> i;
            std::cout << seg[i](a[i]).val() << '\n';
        }
        else {
            assert(false);
        }
    }
}
