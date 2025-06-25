#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/DataStructure/SegmentTree/SegmentTree.hpp"
#include "../../Src/Algebra/Monoid/SameMonoid.hpp"

#include <cassert>
#include <iostream>
#include <vector>

using namespace zawa;
using M = SameMonoid<long long>;
using D = M::Element;

/*
 * AOJ3226 Range Same Query
 * https://onlinejudge.u-aizu.ac.jp/status/users/zawakasu/submissions/1/3326/judge/10635768/C++20
 */

void solve() {
    int n, q; std::cin >> n >> q;
    std::vector<long long> a(n);
    for (auto& x : a) std::cin >> x;
    SegmentTree<M> seg(n);
    for (int i{} ; i < n ; i++) seg.assign(i, D{a[i]});
    for (int _{} ; _ < q ; _++) {
        int t; std::cin >> t;
        if (t == 1) {
            int k; std::cin >> k;
            long long x; std::cin >> x;
            k--;
            a[k] += x;
            seg.assign(k, D{a[k]});
        }
        else if (t == 2) {
            int l, r; std::cin >> l >> r;
            l--;
            std::cout << (seg.product(l, r).same() ? "Yes" : "No") << '\n';
        }
        else {
            assert(false);
        }
    } 
}

int main() {
#ifdef ONLINE_JUDGE
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    solve();
#else
    std::cout << "Hello World" << '\n';
#endif
}
