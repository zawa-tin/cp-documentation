// #define PROBLEM "https://atcoder.jp/contests/abc403/tasks/abc403_g"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * AtCoder Beginner Contest 403 G - Odd Position Sum Query
 * https://atcoder.jp/contests/abc403/submissions/67039553
 */

#include "../../Src/DataStructure/SegmentTree/SparseSegmentTree.hpp"

#include <iostream>

struct D {
    int cnt{};
    long long sum[2]{0,0};
    D() = default;
    D(int c, long long x) : cnt{c} { // x ga c ko
        sum[0] = x * ((c + 1) / 2);
        sum[1] = x * (c / 2);
    }
};

struct M {
    using Element = D;
    static Element identity() {
        return D{};
    }
    static Element operation(Element L, Element R) {
        if (L.cnt % 2) std::swap(R.sum[0], R.sum[1]);
        L.cnt += R.cnt;
        L.sum[0] += R.sum[0];
        L.sum[1] += R.sum[1];
        return L;
    }
};

int main() {
#ifdef ATCODER
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int Q;
    std::cin >> Q;
    const int N = (int)1e9;
    long long z = 0;
    zawa::SparseSegmentTree<M> seg(N + 1);
    while (Q--) {
        long long y;
        std::cin >> y;
        y = (z + y) % N + 1;
        auto v = seg.get(y);
        seg.assign(y, D{v.cnt + 1, y});
        z = seg.product(0, N + 1).sum[0];
        std::cout << z << '\n';
    }
#else
    std::cout << "Hello World\n";
#endif
}
