#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/DataStructure/SegmentTree/SegmentTree.hpp"
#include "../../Src/Number/ModInt.hpp"
#include "../../Src/Algebra/Monoid/AffineMonoid.hpp"

using namespace zawa;
using mint = StaticModInt<u32, 998244353>;
using Monoid = AffineMonoid<mint>;

#include <iostream>
#include <vector>

int main() {
    SetFastIO();
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
            seg.set(p, { c, d });
        }
        else if (t == 1) {
            int l, r, x; std::cin >> l >> r >> x;
            std::cout << seg.product(l, r).mapping(x) << std::endl;
        }
        else {
            assert(false);
        }
    }
}
