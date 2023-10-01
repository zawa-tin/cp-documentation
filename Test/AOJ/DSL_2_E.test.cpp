#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E"

#include "../../Src/DataStructure/SegmentTree/CommutativeDualSegmentTree.hpp"
#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Algebra/Monoid/AdditionMonoid.hpp"

#include <iostream>

int main() {
    using namespace zawa;
    SetFastIO();
    int n, q; std::cin >> n >> q;
    CommutativeDualSegmentTree<AdditionMonoid<int>> seg(n);
    for (int _{} ; _ < q ; _++) {
        int com; std::cin >> com;
        if (com == 0) {
            int s, t, x; std::cin >> s >> t >> x;
            s--;
            seg.update(s, t, x);
        }
        else if (com == 1) {
            int i; std::cin >> i;
            i--;
            std::cout << seg[i] << std::endl;
        }
        else {
            assert(false);
        }
    }
}
