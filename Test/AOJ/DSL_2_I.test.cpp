#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I"

#include "../../Src/DataStructure/SegmentTree/AssignmentSegmentTree.hpp"
#include "../../Src/Template/TypeAlias.hpp"
using namespace zawa;

#include <iostream>

struct M {
    using Element = int;
    static constexpr int identity() {
        return 0;
    }
    static constexpr int operation(int l, int r) {
        return l + r;
    }
    static constexpr int power(int v, u64 exp) {
        return v * (int)exp;
    }
};

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int N, Q;
    std::cin >> N >> Q;
    AssignmentSegmentTree<M> seg(N);
    while (Q--) {
        int T, L, R;
        std::cin >> T >> L >> R;
        R++;
        if (T == 0) {
            int X;
            std::cin >> X;
            seg.assign(L, R, X);
        }
        else if (T == 1) {
            std::cout << seg.product(L, R) << '\n';
        }
        else assert(false);
    }
}
