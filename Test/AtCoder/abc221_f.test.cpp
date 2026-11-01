// #define PROBLEM "https://atcoder.jp/contests/abc221/tasks/abc221_f"
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
/*
 * AtCoder Beginner Contest 221 F - Diameter set
 * https://atcoder.jp/contests/abc221/submissions/80544216
 */
#include "../../Src/Graph/Tree/TreeCenters.hpp"
#include "atcoder/modint"
#include <iostream>
#include <ranges>
#include <vector>
using namespace std;
using mint=atcoder::modint998244353;
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
    zawa::TreeCenters<int,int> cent{move(G)};
    auto dfs=[&](auto dfs,int v)->int {
        int res=0;
        res+=cent.farthest(v).second==cent.diameterLength();
        for (int x : cent[v]|views::keys)
            res+=dfs(dfs,x);
        return res;
    };
    vector<mint> dp(3);
    dp[0]=1;
    for (int v : cent[cent.root()]|views::keys) {
        int cnt=dfs(dfs,v);
        dp[2]+=(dp[2]+dp[1])*cnt; 
        dp[1]+=dp[0]*cnt;
    }
    cout << dp[2].val() << '\n';
#else
    int a,b;
    cin >> a >> b;
    cout << a+b << '\n';
#endif
}
