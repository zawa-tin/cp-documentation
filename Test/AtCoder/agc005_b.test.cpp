#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/DataStructure/SegmentTree/SegmentTree.hpp"

/*
 * AtCoder Grand Contest 005 B - Minimum Sum
 * https://atcoder.jp/contests/agc005/submissions/68182027
 */

#include <iostream>
#include <vector>

struct M {
    using Element = int;
    static Element identity() { return (int)1e9; }
    static Element operation(Element L, Element R) { return std::min(L, R); }
};

long long solve() {
    using namespace zawa;
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    using MD = M::Element;
    int n; 
    std::cin >> n;
    std::vector<MD> a(n);
    for (auto& x : a) {
        int v; std::cin >> v;
        x = v;
    }
    SegmentTree<M> seg(a);
    long long ans{};
    for (int i{} ; i < n ; i++) {
        auto f{[&](MD v) -> bool {
            return v >= a[i];
        }};
        auto left{ seg.minLeft(i, f) }, right{ seg.maxRight(i, f) };
        ans += (long long)(right - i) * (long long)(i - left + 1) * (long long)a[i];
    }
    return ans;
}

int main() {
#ifdef ATCODER
    std::cout << solve() << '\n';
#else
    std::cout << "Hello World" << '\n';
#endif
}
