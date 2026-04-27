#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#include "../../Src/Graph/Components/BridgeTree.hpp"
using namespace zawa;

#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    BridgeTreeBuilder<int> g(N);
    for (int i = 0 ; i < M ; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u,v);
    }
    auto solver = g.build();
    const auto& ans = solver.components();
    cout << ans.size() << '\n';
    for (const std::vector<int>& comp : ans) {
        std::cout << comp.size();
        for (int v : comp) std::cout << ' ' << v;
        std::cout << '\n';
    }
}
