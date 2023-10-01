#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_point_get"

#include "../../Src/DataStructure/SegmentTree/DualSegmentTree.hpp"
#include "../../Src/Number/ModInt.hpp"
#include "../../Src/Algebra/Monoid/AffineMonoid.hpp"
#include "../../Src/Template/IOSetting.hpp"

#include <iostream>
#include <cassert>

int main() {
    using namespace zawa;
    using mint = StaticModInt<u32, 998244353>;
    SetFastIO();
    int n, q; std::cin >> n >> q;
    std::vector<mint> a(n);
    for (auto& x : a) std::cin >> x;
    DualSegmentTree<AffineMonoid<mint>> seg(n);
    for (int _{} ; _ < q ; _++) {
        int t; std::cin >> t;
        if (t == 0) {
            int l, r; std::cin >> l >> r;
            mint b, c; std::cin >> b >> c;
            seg.update(l, r, Affine{ b, c });
        }
        else if (t == 1) {
            int i; std::cin >> i;
            std::cout << seg[i].transformation(a[i]) << std::endl;
        }
        else {
            assert(false);
        }
    }
}
