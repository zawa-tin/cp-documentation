#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/DataStructure/SegmentTree/SegmentTree.hpp"
#include "../../Src/Algebra/Monoid/MinMonoid.hpp"

/*
 * AGC005-B Minimum Sum
 * https://atcoder.jp/contests/agc005/submissions/50115755
 */

#include <iostream>
#include <vector>

long long solve() {
    using namespace zawa;
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    SegmentTree<MinMonoid<int>> seg(a);
    long long ans{};
    for (int i{} ; i < n ; i++) {
        auto f{[&](int v) -> bool {
            return v >= a[i];
        }};
        unsigned left{ seg.minLeft(i, f) }, right{ seg.maxRight(i, f) };
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
