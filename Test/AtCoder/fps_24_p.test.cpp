// #define PROBLEM "https://atcoder.jp/contests/fps-24/tasks/fps_24_p"
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

/*
 * FPS24題 P - ボール
 * https://atcoder.jp/contests/fps-24/submissions/75551782
 */

#include "../../Src/FPS/FPSNTTFriendly.hpp"
#include "../../Src/FPS/MultipointEvaluation.hpp"
using mint = atcoder::modint998244353;
using fps = zawa::FPSNTTFriendly<mint::mod()>;

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N,M,K;
    cin >> N >> M >> K;
    std::vector<mint> F(N+1,1),invF(N+1);
    for (int i = 1 ; i <= N ; i++)
        F[i] = F[i-1]*mint::raw(i);
    invF[N] = F[N].inv();
    for (int i = N ; i >= 1 ; i--)
        invF[i-1] = invF[i]*mint::raw(i);
    fps f(N+1);
    for (int k = 0 ; k <= std::min(N,K) ; k++)
        f[N-k] = F[N]*invF[k]*invF[N-k];
    std::vector<mint> x(M);
    iota(x.begin(),x.end(),mint{1});
    auto ans = zawa::MultipointEvaluation(f,x);
    for (int i = 0 ; i < M ; i++)
        cout << ans[i].val() << '\n';
#else
    int a,b;
    cin >> a >> b;
    cout << a+b << '\n';
#endif
}
