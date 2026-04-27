// #define PROBLEM "https://codeforces.com/contest/2132/problem/F"
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

/*
 * Codeforces Round 1043 (Div. 3) F. Rada and the Chamomile Valley
 * https://codeforces.com/contest/2132/submission/372671082
 */

#include "../../Src/Graph/Components/BridgeTree.hpp"
#include <iostream>
#include <vector>
using namespace std;
void solve() {
    int N,M;
    cin >> N >> M;
    zawa::BridgeTreeBuilder<int> builder(N);
    vector<vector<int>> G(N);
    for (int i = 0 ; i < M ; i++) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        builder.addEdge(u,v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    auto BT = builder.build();
    vector<pair<int,int>> prev(BT.size(),{-1,-1});
    {
        vector<int> dist(BT.size(),-1);
        dist[BT.id(0)] = 0;
        vector<int> que{BT.id(0)};
        for (int t = 0 ; t < ssize(que) ; t++) {
            const int v = que[t];
            for (auto [x,i] : BT[v])
                if (dist[x] == -1) {
                    dist[x] = dist[v] + 1;
                    prev[x] = {v,i};
                    que.push_back(x);
                }
        }
    }
    const int INF = (int)1e9;
    vector<int> ans(N,INF),dist(N,-1);
    for (int v = BT.id(N-1) ; v != BT.id(0) ; ) {
        int i = prev[v].second;
        auto [p,q] = builder.getEdge(i);
        ans[p] = min(ans[p],i);
        ans[q] = min(ans[q],i);
        dist[p] = dist[q] = 0;
        v = prev[v].first;
    }
    vector<int> que;
    for (int i = 0 ; i < N ; i++)
        if (dist[i] == 0)
            que.push_back(i);
    for (int t = 0 ; t < ssize(que) ; t++) {
        int v = que[t];
        for (int x : G[v]) {
            if (dist[x] == -1) {
                dist[x] = dist[v]+1;
                ans[x] = ans[v];
                que.push_back(x);
            }
            else if (dist[x] == dist[v]+1)
                ans[x] = min(ans[x],ans[v]);
        }
    }
    int Q;
    cin >> Q;
    for (int i = 0 ; i < Q ; i++) {
        int v;
        cin >> v;
        v--;
        cout << (ans[v] == INF ? -1 : ans[v]+1) << (i + 1 == Q ? '\n' : ' ');
    }
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
    int a,b;
    cin >> a >> b;
    cout << a + b << '\n';
#endif
}
