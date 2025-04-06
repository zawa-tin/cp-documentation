#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
// #define PROBLEM "https://codeforces.com/contest/2084/problem/C"
/*
 * Teza Round 1 (Codeforces Round 1015, Div. 1 + Div. 2) C. You Soared Afar With Grace
 * https://codeforces.com/contest/2084/submission/314231212
 */
#include "../../Src/Sequence/PermutationSwapSort.hpp"
#include <iostream>
int N, A[200020], B[200020], invA[200020];
void solve() {
    std::cin >> N;
    for (int i = 0 ; i < N ; i++) {
        std::cin >> A[i];
        invA[--A[i]] = i;
    }
    for (int i = 0 ; i < N ; i++) {
        std::cin >> B[i];
        B[i]--;
    }
    int same = 0;
    for (int i = 0 ; i < N ; i++) {
        if (A[i] == B[i]) same++;
        else {
            int id = invA[B[i]];
            if (B[id] != A[i]) {
                std::cout << -1 << '\n';
                return;
            }
        }
    }
    if (same != (N & 1)) {
        std::cout << -1 << '\n';
        return;
    }
    int L = 0, R = N - 1;
    std::vector<int> P(N, -1);
    for (int i = 0 ; i < N ; i++) if (P[i] == -1) {
        if (A[i] == B[i]) {
            P[i] = N / 2;
        }
        else {
            int j = invA[B[i]];
            assert(P[j] == -1);
            P[i] = L++;
            P[j] = R--;
        }
    }
    auto ans = zawa::PermutationSwapSort(P.begin(), P.end());
    std::cout << ans.size() << '\n';
    for (auto [i, j] : ans) std::cout << i + 1 << ' ' << j + 1 << '\n';
}
int main() {
#ifdef ONLINE_JUDGE
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int T;
    std::cin >> T;
    while (T--) solve();
#else
    std::cout << "Hello World\n";
#endif
}
