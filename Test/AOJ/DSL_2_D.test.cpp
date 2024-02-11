#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/DataStructure/SegmentTree/DualSegmentTree.hpp"

#include <cassert>
#include <iostream>
#include <vector>

using namespace zawa;

struct M {
    using Element = int;
    static int identity() {
        return -1;
    }
    static int operation(int a, int b) {
        return (b == identity() ? a : b);
    }
};

int main() {
    SetFastIO();
    int n, q; std::cin >> n >> q;
    DualSegmentTree<M> seg(std::vector<int>(n, (1LL << 31) - 1));
    for (int _{} ; _ < q ; _++) {
        int t; std::cin >> t;
        if (t == 0) {
            int l, r, x; std::cin >> l >> r >> x;
            seg.operation(l, r + 1, x);
        }
        else if (t == 1) {
            int i; std::cin >> i;
            std::cout << seg[i] << '\n';
        }
        else {
            assert(false);
        }
    }
}
