#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_point_get"

#include "../../Src/DataStructure/SegmentTree/DualSegmentTree.hpp"
#include "../../Src/Algebra/Monoid/AffineMonoid.hpp"
using namespace zawa;

#include "atcoder/modint"
using mint = atcoder::modint998244353;

#include <iostream>
#include <cassert>
using namespace std;

struct M : public AffineMonoid<mint> {
    static mint action(const M::Element& f,mint x) {
        return f(x);
    }
};

int main() {
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
    DualSegmentTree<M,mint> seg(std::move(a));
    while (q--) {
        int t; std::cin >> t;
        if (t == 0) {
            int l, r, b, c; 
            std::cin >> l >> r >> b >> c;
            seg.operation(l, r, Affine{ mint{b}, mint{c} });
        }
        else if (t == 1) {
            int i; std::cin >> i;
            std::cout << seg[i].val() << '\n';
        }
        else {
            assert(false);
        }
    }
}
