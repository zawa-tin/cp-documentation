// #define PROBLEM "https://atcoder.jp/contests/abc212/tasks/abc212_h"
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
/*
 * AtCoder Beginner Contest 212 H - Counting
 * https://atcoder.jp/contests/abc212/submissions/80252043
 */
#include "../../Src/Sequence/BitwiseXORConvolution.hpp"
#include "atcoder/modint"
using mint=atcoder::modint998244353;
#include <iostream>
#include <vector>
using namespace std;
int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    const int M=16;
    int N,K;
    cin >> N >> K;
    vector<mint> A(1<<M);
    for (int i = 0 ; i < K ; i++) {
        int a;
        cin >> a;
        A[a]++;
    }
    zawa::FastWalshHadamardTransform(A);
    for (int i = 0 ; i < (1<<M) ; i++) {
        if (A[i]==mint::raw(1))
            A[i]=N+1;
        else
            A[i]=(A[i].pow(N+1)-1)/(A[i]-1);
    }
    zawa::FastWalshHadamardTransform(A);
    const mint inv=mint::raw(2).pow(M).inv();
    mint ans=0;
    for (int i = 1 ; i < (1<<M) ; i++) 
        ans+=A[i]*inv;
    cout << ans.val() << '\n';
#else
    int a,b;
    cin >> a >> b;
    cout << a+b << '\n';
#endif
}
