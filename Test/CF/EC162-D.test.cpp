#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/DataStructure/PrefixSum1D/StaticRangeSumSolver.hpp"
#include "../../Src/Algebra/Monoid/SameMonoid.hpp"
#include "../../Src/DataStructure/SparseTable/SparseTable.hpp"
#include "../../Src/Utility/BinarySearch.hpp"

using namespace zawa;
using M = SameMonoid<long long>;
using D = M::Element;

#include <algorithm>
#include <iostream>

/*
 * Educational Codeforces Round 162 - D. Slimes
 * https://codeforces.com/contest/1923/submission/248125965
 */

void solve() {
    int testcase; std::cin >> testcase;
    while (testcase--) {
        int n; std::cin >> n;
        std::vector<long long> a(n);
        for (auto& x : a) std::cin >> x;
        const int INF{(int)1e9};
        std::vector<int> ans(n, INF);
        for (int t{} ; t < 2 ; t++) {
            Ruisekiwa<long long> s{a};
            std::vector<D> in(n);
            for (int i{} ; i < n ; i++) in[i] = D{a[i]};
            SparseTable<M> spt{in};
            for (int i{1} ; i < n ; i++) {
                if (a[i - 1] > a[i]) {
                    ans[i] = 1;
                    continue;
                }
                auto f{[&](int v) -> bool {
                    return s.product(v, i) > a[i];
                }};
                auto g{[&](int v) -> bool {
                    return !spt.product(v, i).same();
                }};
                int L1{-INF}, L2{-INF};
                if (f(0)) L1 = BinarySearch(0, i, f);
                if (g(0)) L2 = BinarySearch(0, i, g);
                ans[i] = std::min(ans[i], i - std::min(L1, L2));
            }
            if (t == 0) {
                std::reverse(a.begin(), a.end());
                std::reverse(ans.begin(), ans.end());
            }
        }
        for (int i{n - 1} ; i >= 0 ; i--) {
            std::cout << (ans[i] == INF ? -1 : ans[i]) << (i == 0 ? '\n' : ' ');
        }
    }
}

int main() {
#ifdef ONLINE_JUDGE
    SetFastIO();
    solve();
#else
    std::cout << "Hello World" << '\n';
#endif
}
