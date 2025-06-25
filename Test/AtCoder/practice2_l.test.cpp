// #define PROBLEM "https://atcoder.jp/contests/practice2/tasks/practice2_l"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * AtCoder Library Practice Contest - L Lazy Segment Tree
 * https://atcoder.jp/contests/practice2/submissions/67059099
 */

#include "../../Src/DataStructure/SegmentTree/LazySegmentTree.hpp"

struct vDat {
    long long zero{}, one{}, inv{};
    vDat() {}
    vDat(long long z, long long o, long long i) : zero{z}, one{o}, inv{i} {}
    vDat flip() const {
        return vDat{one, zero, one * zero - inv};
    }
};

struct vM {
    using Element = vDat;
    static vDat identity() {
        return vDat();
    }
    static vDat operation(const vDat& a, const vDat& b) {
        return vDat{
            a.zero + b.zero,
            a.one + b.one,
            a.inv + b.inv + a.one * b.zero
        };
    }
};

struct oM {
    using Element = bool;
    static bool identity() {
        return false;
    }
    static bool operation(bool a, bool b) {
        return a ^ b;
    }
};

struct Structure {
    using ValueMonoid = vM;
    using OperatorMonoid = oM;
    static vDat mapping(const vDat& a, bool b) {
        return (b ? a.flip() : a);
    }
};

#include <iostream>
#include <vector>
#include <cassert>

void solve() {
    using namespace zawa;
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, q; std::cin >> n >> q;
    std::vector<vDat> a(n);
    for (auto& x : a) {
        int v; std::cin >> v;
        if (v == 0) x = vDat{ 1, 0, 0 };
        else if (v == 1) x = vDat{ 0, 1, 0 };
        else assert(false);
    } 
    LazySegmentTree<Structure> seg(a); 
    for (int _{} ; _ < q ; _++) {
        int t; std::cin >> t;
        int l, r; std::cin >> l >> r;
        l--;
        if (t == 1) {
            seg.operation(l, r, true);
        } 
        else if (t == 2) {
            std::cout << seg.product(l, r).inv << std::endl;
        }
    }
}

int main() {
#ifdef ATCODER
    solve();
#else
    std::cout << "Hello World" << std::endl;
#endif
}
