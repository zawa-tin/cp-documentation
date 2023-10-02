#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F"

#include "../../Src/DataStructure/SegmentTree/LazySegmentTree.hpp"
#include "../../Src/Algebra/Monoid/MinMonoid.hpp"

struct oM {
    using Element = int;
    static int identity() {
        return -1;
    }
    static int operation(int a, int b) {
        return (b == -1 ? a : b);
    }
};

struct Structure {
    using ValueMonoid = zawa::MinMonoid<int>;
    using OperatorMonoid = oM;
    static int mapping(int a, int b) {
        return (b == -1 ? a : b);
    }
};

#include <iostream>

int main() {
    using namespace zawa;
    int n, q; std::cin >> n >> q;
    LazySegmentTree<Structure> seg(std::vector<int>(n, (1LL << 31) - 1));
    for (int _{} ; _ < q ; _++) {
        int t; std::cin >> t;
        // std::cout << "query: ";
        if (t == 0) {
            int s, t, x; std::cin >> s >> t >> x;
            t++;
            // std::cout << "update " << '[' << s << ',' << t << ')' << "-> " << x << std::endl;
            seg.operation(s, t, x);
        }
        else if (t == 1) {
            int s, t; std::cin >> s >> t;
            t++;
            // std::cout << "prod " << '[' << s << ',' << t << ')' << std::endl;
            std::cout << seg.product(s, t) << std::endl;
        }
        else {
            assert(false);
        }
        // std::cout << seg << std::endl;
    }
}
