// #define PROBLEM "https://judge.tuna.camp/contests/73d937b6-89c4-4931-929c-f0b820567799/problems/master0918_matrix/statement"
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../Src/Combinatorics/StirlingNumberSecondKindFixedN.hpp"
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int a,b;
    cin >> a >> b;
    cout << a+b << '\n';
    // cin.tie(0);
    // cout.tie(0);
    // ios::sync_with_stdio(0);
    // int N,M;
    // cin >> N >> M;
    // vector<vector<int>> G(2*N);
    // for (int i = 0 ; i < M ; i++) {
    //     int r,c,x;
    //     cin >> r >> c >> x;
    //     r--; c--;
    //     G[r].push_back(N+c);
    //     G[N+c].push_back(r);
    // }
    // vector<int> col(2*N,-1);
    // int n=0;
    // auto dfs=[&](auto dfs,int v) -> void {
    //     col[v]=n;
    //     for (int x : G[v])
    //         if (col[x] == -1)
    //             dfs(dfs,x);
    // }; 
    // for (int i = 0 ; i < 2*N ; i++)
    //     if (col[i] == -1) {
    //         dfs(dfs,i);
    //         n++;
    //     }
    // using mint = atcoder::modint998244353;
    // auto stir=zawa::StirlingNumberSecondKindFixedN(n);
    // mint ans=0,fac=1;
    // for (int i=1 ; i<=n ; i++) {
    //     fac*=mint::raw(i);
    //     ans+=stir[i]*fac;
    // }
    // cout << ans.val() << '\n';
}
