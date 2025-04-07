#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
// #define PROBLEM "https://atcoder.jp/contests/arc196/tasks/arc196_a"

/*
 * AtCoder Regular Contest 196 (Div. 1) A - Adjacent Delete
 * https://atcoder.jp/contests/arc196/submissions/64618439
 */

#include "../../Src/DataStructure/Other/PriorityProductSet.hpp"
#include "../../Src/Algebra/Group/AdditiveGroup.hpp"

#include <algorithm>
#include <iostream>
#include <vector>
using namespace zawa;
int N, A[300030];
long long solve() {
    std::vector<long long> pref(N + 1);
    {
        PriorityProductSet<AdditiveGroup<long long>> set;
        for (int i = 0 ; i < N ; i += 2) {
            set.setK(i/2);
            pref[i] = set.productRemain().value() - set.product().value();
            set.insert(A[i]);
            if (i + 1 < N) set.insert(A[i + 1]);
        }
        if (N % 2 == 0) {
            set.setK(N/2);
            pref[N] = set.productRemain().value() - set.product().value();
            return pref[N];
        }
    }
    std::vector<long long> suf(N + 1);
    {
        PriorityProductSet<AdditiveGroup<long long>> set;
        for (int i = N ; i >= 0 ; i -= 2) {
            set.setK((N-i)/2);
            suf[i] = set.productRemain().value() - set.product().value();
            if (i - 1 >= 0) set.insert(A[i - 1]);
            if (i - 2 >= 0) set.insert(A[i - 2]);
        }
    }
    // for (auto p : pref) std::cout << p << ' ';
    // std::cout << std::endl;
    // for (auto p : suf) std::cout << p << ' ';
    // std::cout << std::endl;
    long long ans = 0;
    for (int i = 0 ; i < N ; i += 2) {
        ans = std::max(ans, pref[i] + suf[i + 1]);
    }
    return ans;
}
int main() {
#ifdef ATCODER
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::cin >> N;
    for (int i = 0 ; i < N ; i++) std::cin >> A[i];
    std::cout << solve() << '\n';
#else
    std::cout << "Hello World\n";
#endif
}
