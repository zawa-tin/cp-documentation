#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/DataStructure/SegmentTree/SegmentTree.hpp"
#include "../../Src/Algebra/Monoid/MinMonoid.hpp"

/*
 * AGC005-B Minimum Sum
 * https://atcoder.jp/contests/agc005/submissions/50116418
 */

#include <iostream>
#include <vector>

long long solve() {
    using namespace zawa;
    SetFastIO();
    using M = MinMonoid<int>;
    using MD = M::Element;
    int n; std::cin >> n;
    std::vector<MD> a(n);
    for (auto& x : a) {
        int v; std::cin >> v;
        x = v;
    }
    SegmentTree<M> seg(a);
    long long ans{};
    for (int i{} ; i < n ; i++) {
        auto f{[&](const MD& v) -> bool {
            return !(bool)v or v.value() >= a[i];
        }};
        unsigned left{ seg.minLeft(i, f) }, right{ seg.maxRight(i, f) };
        ans += (long long)(right - i) * (long long)(i - left + 1) * (long long)a[i].value();
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
