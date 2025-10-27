// #define PROBLEM "https://atcoder.jp/contests/abc429/tasks/abc429_g"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/Number/SqrtHeuristicArithmetic.hpp"
#include "atcoder/modint"
using mint = atcoder::modint;

#include <iostream>
using namespace std;
mint f(long long a, long long b, long long x, long long n) {
    mint res = 0, pw = mint{x}.pow(a), sum = 1;
    while (n) {
        if (n & 1)
            res = res * pw + sum;
        sum += sum * pw;
        pw *= pw;
        n >>= 1;
    }
    return res * mint{x}.pow(b);
}
mint naive(long long N, long long M, long long A, long long B, long long X, long long R) {
    mint res = 0;
    for (long long i = 0 ; i < N ; i++) {
        res += mint{X}.pow((A * i + B) % M);
    }
    return res;
}
void solve() {
    long long N, M, A, B, X, R;
    cin >> N >> M >> A >> B >> X >> R;
    mint::set_mod(R);
    long long g = gcd(A, M);
    A /= g;
    long long BB = B % g;
    B /= g;
    M /= g;
    mint ans = 0; 
    if (N >= M) {
        mint kiyo = f(g, 0, X, M);
        ans += (N / M) * kiyo;
        N %= M;
    }
    for (const auto data : zawa::SqrtHeuristicArithmetic(A, B, M, N)) {
        if (X == 1)
            ans += mint{data.n};
        else {
            long long ar = data.a * g;
            assert(ar != 0);
            if (ar > 0)
                ans += f(ar, data(0)*g, X, data.n);
            else 
                ans += f(-ar, data(data.n - 1)*g, X, data.n);
        }
    }
    ans *= mint{X}.pow(BB);
    cout << ans.val() << '\n';
}
int main() {
#ifdef ATCODER
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
