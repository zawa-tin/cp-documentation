// #define PROBLEM "https://atcoder.jp/contests/abc482/tasks/abc482_e"
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
/*
 * AtCoder Beginner Contest 482 E - Diameter Endpoint Colors
 * https://atcoder.jp/contests/abc482/submissions/80544207
 */
#include "../../Src/Graph/Tree/TreeCenters.hpp"
#include <algorithm>
#include <ranges>
#include <iostream>
using namespace std;
int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for (int i = 0 ; i < N - 1 ; i++) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> C(N);
    for (auto& x : C) {
        cin >> x;
        x--;
    }
    zawa::TreeCenters<int,int> cent{move(G)};
    const int diam=cent.diameterLength(); 
    auto dfs=[&](auto dfs,int v,vector<int>& upd)->void{
        if (cent.farthest(v).second==diam)
            upd.push_back(C[v]);
        for (int x : cent[v]|views::keys)
            dfs(dfs,x,upd);
    };
    vector dp(N,vector<long long>{1,0,0});
    for (int v : cent[cent.root()]|views::keys) {
        vector<int> upd;
        dfs(dfs,v,upd);
        ranges::sort(upd);
        for (int i = 0, j = 0 ; i < ssize(upd) ; i = j) {
            while (j < ssize(upd) and upd[i]==upd[j])
                j++;
            dp[upd[i]][2]+=dp[upd[i]][1]*(j-i);
            dp[upd[i]][1]+=dp[upd[i]][0]*(j-i);
        }
    }
    long long ans=0;
    for (auto d : dp)
        ans += d[2];
    cout << ans << '\n';
#else
    int a,b;
    cin >> a >> b;
    cout << a+b << '\n';
#endif
}
