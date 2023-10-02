#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "../../Src/Number/ModInt.hpp"
#include "../../Src/Template/IOSetting.hpp"

#include <iostream>
#include <vector>
#include <cassert>
#include <utility>

using namespace zawa;

using mint = StaticModInt<u32, 998244353>;

std::ostream& operator<<(std::ostream& os, const std::pair<mint, mint>& a) {
    os << '(' << a.first << ',' << a.second << ')';
    return os;
}

std::pair<mint, mint> operator+(const std::pair<mint, mint>& a, const std::pair<mint, mint>& b) {
    return std::pair<mint, mint>{ a.first + b.first, a.second + b.second };
}

#include "../../Src/DataStructure/SegmentTree/LazySegmentTree.hpp"
#include "../../Src/Algebra/Monoid/AdditionMonoid.hpp"
#include "../../Src/Algebra/Monoid/AffineMonoid.hpp"

struct Structure {
    using ValueMonoid = AdditionMonoid<std::pair<mint, mint>>;
    using OperatorMonoid = AffineMonoid<mint>;
    static std::pair<mint, mint> mapping(const std::pair<mint, mint>& v, const Affine<mint>& o) {
        return { o.a() * v.first + o.b() * v.second, v.second };
    }
};

int main() {
    int n, q; std::cin >> n >> q;
    std::vector<std::pair<mint, mint>> a(n);
    for (auto& x : a) {
        std::cin >> x.first;
        x.second = 1;
    }
    LazySegmentTree<Structure> seg(a);
    for (int _{} ; _ < q ; _++) {
        int t; std::cin >> t;
        if (t == 0) {
            int l, r; std::cin >> l >> r;
            mint b, c; std::cin >> b >> c;
            seg.operation(l, r, Affine{ b, c });
        }
        else if (t == 1) {
            int l, r; std::cin >> l >> r;
            std::cout << seg.product(l, r).first << std::endl;
        }
        else {
            assert(false);
        }
    }
}
