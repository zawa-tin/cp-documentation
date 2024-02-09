#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/DataStructure/SegmentTree/LazySegmentTree.hpp"
#include "../../Src/Algebra/Monoid/MinMonoid.hpp"

using vM = zawa::MinMonoid<int>;
using vD = vM::Element;

struct oM {
    using Element = vD;
    static vD identity() {
        return std::nullopt;
    }
    static vD operation(const vD& a, const vD& b) {
        return (b ? b : a);
    }
};

struct Structure {
    using ValueMonoid = vM;
    using OperatorMonoid = oM;
    static vD mapping(const vD& a, const vD& b) {
        return oM::operation(a, b);
    }
};

#include <iostream>

int main() {
    using namespace zawa;
    using vD = vM::Element;
    SetFastIO();

    int n, q; std::cin >> n >> q;
    LazySegmentTree<Structure> seg(std::vector<vD>(n, (1LL << 31) - 1));
    for (int _{} ; _ < q ; _++) {
        int t; std::cin >> t;
        if (t == 0) {
            int s, t, x; std::cin >> s >> t >> x;
            t++;
            seg.operation(s, t, x);
        }
        else if (t == 1) {
            int s, t; std::cin >> s >> t;
            t++;
            std::cout << seg.product(s, t).value() << '\n';
        }
        else {
            assert(false);
        }
    }
}
