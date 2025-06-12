#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#include "../../Src/Graph/Components/BridgeTree.hpp"
using namespace zawa;

#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<int>> g(N);
    for (int i = 0 ; i < M ; i++) {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    BridgeTree bt(g);
    auto& ans = bt.components();
    std::cout << ans.size() << '\n';
    for (const std::vector<int>& comp : ans) {
        std::cout << comp.size();
        for (int v : comp) std::cout << ' ' << v;
        std::cout << '\n';
    }
}
