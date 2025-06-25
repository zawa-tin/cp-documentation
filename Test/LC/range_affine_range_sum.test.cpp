#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "atcoder/modint"

using mint = atcoder::modint998244353;
std::pair<mint, mint> operator+(const std::pair<mint, mint>& a, const std::pair<mint, mint>& b) {
    return {a.first+b.first,a.second+b.second};
}

#include "../../Src/DataStructure/SegmentTree/LazySegmentTree.hpp"
#include "../../Src/Algebra/Monoid/AdditionMonoid.hpp"
#include "../../Src/Algebra/Monoid/AffineMonoid.hpp"

#include <iostream>
#include <vector>
#include <cassert>
#include <utility>

using namespace zawa;

struct S {
    using ValueMonoid = AdditionMonoid<std::pair<mint, mint>>;
    using OperatorMonoid = AffineMonoid<mint>;
    static std::pair<mint, mint> mapping(const std::pair<mint, mint>& v, const Affine<mint>& o) {
        return { o.a() * v.first + o.b() * v.second, v.second };
    }
};


int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, q; 
    std::cin >> n >> q;
    std::vector<std::pair<mint, mint>> a(n);
    for (auto& x : a) {
        int v;
        std::cin >> v;
        x = {v, 1};
    }
    LazySegmentTree<S> seg(a);
    while (q--) {
        int t, l, r; 
        std::cin >> t >> l >> r;
        if (t == 0) {
            int b, c; 
            std::cin >> b >> c;
            seg.operation(l, r, Affine{ mint{b}, mint{c} });
        }
        else if (t == 1) {
            std::cout << seg.product(l, r).first.val() << '\n';
        }
        else {
            assert(false);
        }
    }
}
