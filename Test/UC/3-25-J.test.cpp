// #define PROBLEM "https://contest.ucup.ac/contest/1893/problem/9735"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1"

/*
 * The 3rd Universal Cup. Stage 25: Hangzhou J. Japanese Bands
 * https://contest.ucup.ac/submission/1387025
 */

#include "../../Src/Sequence/BitwiseOrConvolution.hpp"

#include "atcoder/modint"
using mint = atcoder::modint1000000007;

#include <iostream>
#include <vector>
#include <bit>
#include <algorithm>
using namespace std;
mint comb(int n, int r) {
    if (n < r)
        return 0;
    if (r < 0)
        return 0;
    r = min(r, n - r);
    mint num = 1, den = 1;
    for (int i = 0 ; i < r ; i++) {
        num *= mint{n - i};
        den *= mint{i + 1};
    }
    return num / den;
}
void solve() {
    int N1, N2, M, K;
    cin >> N1 >> N2 >> M >> K;
    vector<int> A(K), B(K);
    int mask = 0;
    for (int i = 0 ; i < K ; i++) {
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
        mask |= 1 << A[i];
        mask |= 1 << B[i];
    }
    vector<mint> p(1 << M), q(1 << M);
    for (int b = 0 ; b < (1 << M) ; b++) {
        bool ok = 1;
        for (int i = 0 ; i < K ; i++) {
            if (b & (1 << A[i]))
                continue;
            if (b & (1 << B[i]))
                continue;
            ok = 0;
            break;
        }
        if (ok) {
            int cnt = popcount(unsigned(b));
            assert(cnt > 0);
            p[b] = comb(N1 - 1, N1 - cnt);
            q[b] = comb(N2 - 1, N2 - cnt);
        }
    }
    auto conv = zawa::BitwiseOrConvolution(p, q);
    mint ans = 0;
    for (int b = 0 ; b < (1 << M) ; b++)
        if ((mask & b) == mask)
            ans += conv[b];
    cout << ans.val() << '\n';
}
int main() {
#ifdef ONLINE_JUDGE
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--)
        solve();
#else
    cout << "Hello World\n";
#endif
}
