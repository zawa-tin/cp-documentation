// #define PROBLEM "https://atcoder.jp/contests/ndpc/tasks/ndpc2026_l"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * Next DP Contest L - 最小公倍数
 * https://atcoder.jp/contests/ndpc/submissions/75550273
 */

#include "../../Src/Number/LinearSieve.hpp"
#include "atcoder/modint"
using mint = atcoder::modint998244353;

#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
using namespace std;

int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto& x : A)
        cin >> x;
    zawa::LinearSieve siv(N);
    vector<mint> table(N+1), inv(N+1);
    for (int i = 1 ; i <= N ; i++)
        inv[i] = mint::raw(i).inv();
    for (int d : siv.divisor<int>(A[0]))
        table[d] = A[0];
    for (int i = 1 ; i < N ; i++) {
        vector<int> ds = siv.divisor<int>(A[i]), ps = siv.primeFactors<int>(A[i]);
        ranges::sort(ds);
        // mobius
        for (int p : ps)
            for (int d : ds)
                if (A[i] % (p*d) == 0)
                    table[d] -= table[p*d];
        mint ans = 0;
        for (int d : ds)
            ans += inv[d] * table[d];
        ans *= mint::raw(A[i]);
        cout << ans.val() << '\n';
        // zeta
        for (int p : ps)
            for (int d : ds | views::reverse)
                if (d % p == 0)
                    table[d/p] += table[d];
        for (int d : ds)
            table[d] += mint::raw(A[i]) * ans;
    }
#else
    cout << "Hello World\n";
#endif
}
