#define PROBLEM "https://judge.yosupo.jp/problem/range_set_range_composite"

#include "../../Src/DataStructure/SegmentTree/AssignmentSegmentTree.hpp"
#include "../../Src/Algebra/Monoid/AffineMonoid.hpp"
using namespace zawa;
#include "atcoder/modint"
using mint = atcoder::modint998244353;

#include <cassert>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int N, Q;
    std::cin >> N >> Q;
    std::vector<Affine<mint>> init(N);
    for (int i = 0 ; i < N ; i++) {
        int a, b;
        std::cin >> a >> b;
        init[i] = Affine{mint{a}, mint{b}};
    }
    AssignmentSegmentTree<AffineMonoid<mint>> seg{init};
    while (Q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int l, r, c, d;
            std::cin >> l >> r >> c >> d;
            seg.assign(l, r, Affine{mint{c}, mint{d}});
        }
        else if (t == 1) {
            int l, r, x;
            std::cin >> l >> r >> x;
            std::cout << seg.product(l, r)(x).val() << '\n';
        }
        else assert(false);
    }
}
