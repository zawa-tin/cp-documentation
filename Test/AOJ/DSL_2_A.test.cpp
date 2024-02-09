#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"

#include "../../Src/DataStructure/SegmentTree/SegmentTree.hpp"
#include "../../Src/Algebra/Monoid/MinMonoid.hpp"

#include <iostream>
#include <cassert>

int main() {
    using namespace zawa;
    using M = MinMonoid<int>;
    using MD = M::Element;
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, q; std::cin >> n >> q; 
    SegmentTree<MinMonoid<int>> seg(std::vector<MD>(n, ((1LL << 31) - 1)));
    for (int _{} ; _ < q ; _++) {
        int com, x, y; std::cin >> com >> x >> y;
        if (com == 0) {
            seg.set(x, y);
        }
        else if (com == 1) {
            std::cout << seg.product(x, y + 1).value() << '\n';
        }
        else {
            assert(false);
        }
    }
}
