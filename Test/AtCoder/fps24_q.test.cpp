// #define PROBLEM "https://atcoder.jp/contests/fps-24/tasks/fps_24_q"
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
/*
 * FPS24題 Q - サイコロ
 * https://atcoder.jp/contests/fps-24/submissions/79892982
 */
#include "../../Src/FPS/FPSNTTFriendly.hpp"
#include "../../Src/FPS/EnumeratePowerSums.hpp"
#include <iostream>
using namespace std;
using mint=atcoder::modint998244353;
using fps=zawa::FPSNTTFriendly<mint::mod()>;
int main() {
#ifdef ATCODER
    int N,M,K;
    cin >> N >> M >> K;
    std::vector<mint> fac(K+1,1),ifac(K+1);
    for (int i = 1 ; i <= K ; i++)
        fac[i]=fac[i-1]*mint{i};
    ifac[K]=fac[K].inv();
    for (int i = K ; i >= 1 ; i--)
        ifac[i-1]=ifac[i]*mint{i};
    std::vector<mint> A(N),B(M);
    for (mint& a : A) {
        int x;
        cin >> x;
        a=mint::raw(x);
    }
    for (mint& a : B) {
        int x;
        cin >> x;
        a=mint::raw(x);
    }
    auto a=zawa::EnumeratePowerSums<fps>(A,K),b=zawa::EnumeratePowerSums<fps>(B,K);
    for  (int i = 0 ; i <= K ; i++) {
        a[i]*=ifac[i];
        b[i]*=ifac[i];
    }
    auto c=(a*b).resized(K+1);
    const mint inv=(mint{N}*mint{M}).inv();
    for (int k = 1 ; k <= K ; k++)
        cout << (c[k]*fac[k]*inv).val() << '\n';
#else
    int a,b;
    cin >> a >> b;
    cout << a+b << '\n';
#endif
}
