#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/DataStructure/SegmentTree/SegmentTree.hpp"
#include "../../Src/Algebra/Monoid/AffineMonoid.hpp"

#include "atcoder/modint"

using namespace zawa;
using mint = atcoder::modint998244353;
using Monoid = AffineMonoid<mint>;

#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, q; std::cin >> n >> q;
    std::vector<Affine<mint>> init(n);
    for (int i{} ; i < n ; i++) {
        u64 a, b; std::cin >> a >> b;
        init[i] = Affine<mint>{ a, b };
    }
    SegmentTree<Monoid> seg(init);
    for (int _{} ; _ < q ; _++) {
        int t; std::cin >> t;
        if (t == 0) {
            int p, c, d; std::cin >> p >> c >> d;
            seg.assign(p, { c, d });
        }
        else if (t == 1) {
            int l, r, x; std::cin >> l >> r >> x;
            std::cout << seg.product(l, r)(x).val() << '\n';
        }
        else {
            assert(false);
        }
    }
}
