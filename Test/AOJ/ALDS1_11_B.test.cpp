#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_11_B"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Graph/Basis/AdjacentList.hpp"

#include <iostream>
#include <vector>
#include <cassert>

using namespace zawa;

int main() {
    usize N;
    std::cin >> N;
    Graph<u16> G(N);
    for (usize i = 0 ; i < N ; i++) {
        u32 u, k;
        std::cin >> u >> k;
        for (u32 j = 0 ; j < k ; j++) {
            u32 v;
            std::cin >> v;
            G.addDirectedEdge(u - 1, v - 1);
        }
    }

    for (u32 i = 0 ; i < N ; i++) {
        for (const auto& e : G[i]) 
            assert(i == e.from());
    }

    std::vector<bool> visited(N);
    std::vector<u32> d(N), f(N);
    u32 time = 0;

    auto dfs = [&](auto dfs, u32 v) -> void {
        visited[v] = true;
        d[v] = ++time;
        for (const auto& e : G[v]) if (!visited[e.to()])
            dfs(dfs, e.to());
        f[v] = ++time;
    };

    for (u32 i = 0 ; i < N ; i++) if (!visited[i]) 
        dfs(dfs, i);


    for (u32 i = 0 ; i < N ; i++) {
        std::cout << i + 1 << ' ' << d[i] << ' ' << f[i] << std::endl;
    }
}
