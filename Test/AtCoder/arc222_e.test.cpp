// #define PROBLEM "https://atcoder.jp/contests/arc222/tasks/arc222_e"
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
/*
 * AtCoder Regular Contest 222 E - XOR Matching
 * https://atcoder.jp/contests/arc222/submissions/80251457
 */
#include "../../Src/Sequence/BitwiseXORConvolution.hpp"
using namespace std;
#include <iostream>
#include <vector>
int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N,M;
    cin >> N >> M;
    vector<int> A(1<<M);
    for (int i = 0 ; i < N ; i++) {
        int a;
        cin >> a;
        A[a]++;
    }
    const int B=11;
    vector<int> ans(1<<M);
    for (int low = 1 ; low <= B ; low++) {
        vector<long long> cur(1<<M);
        for (int i = 0 ; i < (1<<M) ; i++)
            if (A[i] >= low)
                cur[i] = 1;
        auto conv=zawa::BitwiseXORConvolutionPower(cur,2);
        for (int i = 1 ; i < (1<<M) ; i++)
            ans[i]+=conv[i]/2;
    }
    vector<int> p;
    for (int i = 0 ; i < (1<<M) ; i++)
        if (A[i] > B)
            p.push_back(i);
    for (int i = 0 ; i < ssize(p) ; i++)
        for (int j = i+1 ; j < ssize(p) ; j++)
            ans[p[i]^p[j]]+=min(A[p[i]],A[p[j]])-B;
    for (int i = 0 ; i < (1<<M) ; i++)
        ans[0]+=A[i]/2;
    const long long MOD=998244353;
    long long out=0,base=1;
    for (int i = 0 ; i < (1<<M) ; i++) {
        out = (out+ans[i]*base)%MOD;
        base = (base*10)%MOD;
    }
    cout << out << '\n';
#else
    int a,b;
    cin >> a >> b;
    cout << a+b << '\n';
#endif
}
