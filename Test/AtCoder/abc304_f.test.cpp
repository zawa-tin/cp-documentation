// #define PROBLEM "https://atcoder.jp/contests/abc304/tasks/abc304_f"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * AtCoder Beginner Contest 304 F - Shift Table
 * https://atcoder.jp/contests/abc304/submissions/69569939
 */

#include "../../Src/Number/PrimeSubsetTransform.hpp"
#include "atcoder/modint"
using mint = atcoder::modint998244353;

#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
void solve() {
    int N;
    string S;
    cin >> N >> S;
    vector<mint> p2(N + 1, 1);
    for (int i = 1 ; i <= N ; i++)
        p2[i] = p2[i - 1] * mint::raw(2);
    vector<mint> a(N + 1);
    for (int m = 1 ; m <= N ; m++)
        if (N % m == 0) {
            vector<bool> ng(m);
            for (int i = 0 ; i < N ; i++)
                if (S[i] == '.')
                    ng[i % m] = 1;
            a[m] = p2[ranges::count(ng, 0)];
        }
    zawa::PrimeSubsetMobiusTransform(a);
    mint ans = 0;
    for (int m = 1 ; m < N ; m++)
        if (N % m == 0)
            ans += a[m];
    cout << ans.val() << '\n';
}
int main() {
#ifdef ATCODER
    solve();
#else
    cout << "Hello World\n";
#endif
}
