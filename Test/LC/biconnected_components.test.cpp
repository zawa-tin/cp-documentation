#define PROBLEM "https://judge.yosupo.jp/problem/biconnected_components"

#include "../../Src/Graph/Components/BlockCutTree.hpp"
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
    BlockCutTree bct{g};
    auto& ans = bct.blocks();
    std::cout << ans.size() << '\n';
    for (const std::vector<int>& blk : ans) {
        std::cout << blk.size();
        for (int v : blk) std::cout << ' ' << v;
        std::cout << '\n';
    }
}
