#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E"

#include "../../Src/DataStructure/SegmentTree/CommutativeDualSegmentTree.hpp"
#include "../../Src/Algebra/Monoid/AdditionMonoid.hpp"

#include <iostream>

int main() {
    using namespace zawa;
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, q; std::cin >> n >> q;
    CommutativeDualSegmentTree<AdditionMonoid<int>> seg(n);
    for (int _{} ; _ < q ; _++) {
        int com; std::cin >> com;
        if (com == 0) {
            int s, t, x; std::cin >> s >> t >> x;
            s--;
            seg.operation(s, t, x);
        }
        else if (com == 1) {
            int i; std::cin >> i;
            i--;
            std::cout << seg[i] << '\n';
        }
        else {
            assert(false);
        }
    }
}
