// #define PROBLEM "https://atcoder.jp/contests/abc298/tasks/abc298_h"
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
/*
 * AtCoder Beginner Contest 198 Ex - Sum of Min of Length
 * https://atcoder.jp/contests/abc298/submissions/80190158
 */
#include "../../Src/Graph/Tree/Rerooting.hpp"
#include "../../Src/Graph/Tree/HeavyLightDecomposition.hpp"
#include <iostream>
#include <utility>
#include <unordered_map>
#include <vector>
using namespace std;
using namespace zawa;
struct DP {
    using Tree = pair<long long,int>;
    using Cluster = pair<long long,int>;
    using Edge = struct {};
    using Vertex = struct {};
    static Tree Convert(Vertex) {
        return {0LL,1};
    }
    static Cluster AddEdge(Tree t,Edge) {
        return {t.first+t.second,t.second};
    }
    static Cluster Merge(Cluster l,Cluster r) {
        return {l.first+r.first,l.second+r.second};
    }
    static Tree AddVertex(Cluster c,Vertex) {
        return {c.first,c.second+1};
    }
};
int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<pair<int,int>> E(N-1);
    vector<vector<int>> G(N);
    vector<unordered_map<int,int>> id(N);
    for (int i = 0 ; auto& [a,b] : E) {
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
        id[a][b]=i;
        id[b][a]=i;
        i++;
    }
    Rerooting<DP,int> dp(N,E,vector<DP::Vertex>(N),vector<DP::Edge>(N-1));
    HeavyLightDecomposition hld{G};
    int Q;
    cin >> Q;
    while (Q--) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        if (u == v) 
            cout << dp[u].first << '\n';
        else {
            const int d=hld.distance(u,v);
            const int p=hld.jump(u,v,d/2).value(),q=hld.jump(p,v,1).value();
            long long ans=dp[u].first+dp[v].first;
            {
                auto side=dp.side(id[p][q],q);
                ans-=side.first+(long long)side.second*(d/2+1);
            }
            {
                auto side=dp.side(id[q][p],p);
                ans-=side.first+(long long)side.second*((d+1)/2);
            }
            cout << ans << '\n';
        }
    }
#else
    int a,b;
    cin >> a >> b;
    cout << a+b << '\n';
#endif
}
