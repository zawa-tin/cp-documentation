#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"

#include "../../Src/DataStructure/SegmentTree/SegmentTree.hpp"

#include <cassert>
#include <iostream>
#include <limits>
struct M {
    using Element = int;
    static Element identity() { return std::numeric_limits<int>::max(); }
    static Element operation(Element L, Element R) { return std::min(L, R); }
};
int main() {
    using namespace zawa;
    using MD = M::Element;
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, q; 
    std::cin >> n >> q; 
    SegmentTree<M> seg(std::vector(n, M::identity()));
    while (q--) {
        int com, x, y; 
        std::cin >> com >> x >> y;
        if (com == 0) {
            seg.assign(x, y);
        }
        else if (com == 1) {
            std::cout << seg.product(x, y + 1) << '\n';
        }
        else {
            assert(false);
        }
    }
}
