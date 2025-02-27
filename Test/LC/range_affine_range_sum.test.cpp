#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "atcoder/modint"

using mint = atcoder::modint998244353;
std::pair<mint, mint> operator+(const std::pair<mint, mint>& a, const std::pair<mint, mint>& b) {
    return {a.first+b.first,a.second+b.second};
}

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/DataStructure/SegmentTree/LazySegmentTree.hpp"
#include "../../Src/Algebra/Monoid/AdditionMonoid.hpp"
#include "../../Src/Algebra/Monoid/AffineMonoid.hpp"

#include <iostream>
#include <vector>
#include <cassert>
#include <utility>

using namespace zawa;

struct Structure {
    using ValueMonoid = AdditionMonoid<std::pair<mint, mint>>;
    using OperatorMonoid = AffineMonoid<mint>;
    static std::pair<mint, mint> mapping(const std::pair<mint, mint>& v, const Affine<mint>& o) {
        return { o.a() * v.first + o.b() * v.second, v.second };
    }
};


int main() {
    SetFastIO();
    int n, q; std::cin >> n >> q;
    std::vector<std::pair<mint, mint>> a(n);
    for (auto& x : a) {
        int v;
        std::cin >> v;
        x = {v, 1};
    }
    LazySegmentTree<Structure> seg(a);
    for (int _{} ; _ < q ; _++) {
        int t; std::cin >> t;
        if (t == 0) {
            int l, r, b, c; 
            std::cin >> l >> r >> b >> c;
            seg.operation(l, r, Affine{ mint{b}, mint{c} });
        }
        else if (t == 1) {
            int l, r; std::cin >> l >> r;
            std::cout << seg.product(l, r).first.val() << '\n';
        }
        else {
            assert(false);
        }
    }
}
