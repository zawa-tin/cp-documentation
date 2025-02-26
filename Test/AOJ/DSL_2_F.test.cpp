#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/DataStructure/SegmentTree/AssignmentSegmentTree.hpp"
using namespace zawa;

#include <cassert>
#include <iostream>
#include <algorithm>
#include <limits>

struct vM {
    using Element = int;
    static constexpr Element identity() {
        return std::numeric_limits<Element>::max();
    } 
    static constexpr Element operation(Element L, Element R) {
        return std::min(L, R);
    }
    static constexpr Element power(Element L, u32 op) {
        return (op == 0 ? identity() : L);
    }
};

int main() {
    SetFastIO();
    int N, Q;
    std::cin >> N >> Q;
    AssignmentSegmentTree<vM> seg(N);
    while (Q--) {
        int t;
        int l, r;
        std::cin >> t >> l >> r;
        r++;
        if (t == 0) {
            int x;
            std::cin >> x;
            seg.assign(l, r, x);
        }
        else if (t == 1) {
            std::cout << seg.product(l, r) << '\n';
        }
        else assert(false);
    }
}
