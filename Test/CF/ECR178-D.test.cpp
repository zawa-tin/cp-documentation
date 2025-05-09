// #define PROBLEM "https://codeforces.com/contest/2104/problem/D"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * Educational Codeforces Round 178 - D Array and GCD
 * https://codeforces.com/contest/2104/submission/318930773
 */

#include "../../Src/Number/EnumeratePrimes.hpp"

#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
int N, A[400040];
std::vector<int> P = zawa::EnumeratePrimes<int>(6000000);
int solve() {
    std::sort(A, A + N);
    long long p = std::accumulate(P.begin(), P.begin() + N, 0LL);
    long long a = std::accumulate(A, A + N, 0LL);
    for (int i = 0 ; i < N ; i++) {
        if (a >= p) return i;
        a -= A[i];
        p -= P[N - i - 1];
    }
    return N;
}
int main() {
#ifdef ONLINE_JUDGE
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int T;
    std::cin >> T;
    while (T--) {
        std::cin >> N;
        for (int i = 0 ; i < N ; i++) std::cin >> A[i];
        std::cout << solve() << '\n';
    }
#else
    std::cout << "Hello World\n";
#endif
}
