#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"
#include "../../Src/Graph/Tree/TreeCenters.hpp"
#include <iostream>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<vector<pair<int,long long>>> G(N);
    for (int i = 0 ; i < N-1 ; i++) {
        int u,v,c;
        cin >> u >> v >> c;
        G[u].push_back({v,c});
        G[v].push_back({u,c});
    }
    zawa::TreeCenters solver(move(G));
    const auto& ans=solver.diameterPath();
    cout << solver.diameterLength() << ' ' << ans.size() << '\n';
    for (int i = 0 ; i < ssize(ans) ; i++)
        cout << ans[i] << (i+1==ssize(ans)?'\n':' ');
}
