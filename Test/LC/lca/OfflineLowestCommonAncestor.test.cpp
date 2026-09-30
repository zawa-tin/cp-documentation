#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "../../../Src/Graph/Tree/OfflineLowestCommonAncestor.hpp"
#include <iostream>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N,Q;
    cin >> N >> Q;
    vector<vector<int>> G(N);
    for (int i = 1 ; i < N ; i++) {
        int p;
        cin >> p;
        G[p].push_back(i);
    }
    vector<pair<int,int>> query(Q);
    for (auto& [u,v] : query)
        cin >> u >> v;
    for (int ans : zawa::OfflineLowestCommonAncestor(G,query))
        cout << ans << '\n';
}
