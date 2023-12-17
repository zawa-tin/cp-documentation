#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2872"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Graph/ShortestPath/Dijkstra.hpp"
#include "../../Src/Graph/Flow/Dinic.hpp"

#include <cassert>
#include <iostream>
#include <tuple>
#include <vector>

int main() {
    using namespace zawa;
    int n, m, s, t; std::cin >> n >> m >> s >> t;
    s--; t--;
    Dijkstra<unsigned> g(n);
    std::vector<std::tuple<int, int, int, int>> e(m);
    for (auto& [u, v, d, c] : e) {
        std::cin >> u >> v >> d >> c;
        u--; v--;
        g.addDirectedEdge(u, v, (unsigned)d);
    }
    auto tree{g.build(s)};
    assert(tree.connect(t));
    Dinic<int> mf(n);
    for (auto [u, v, d, c] : e) {
        if (!tree.connect(u)) continue;
        if (tree[u] + d == tree[v]) {
            mf.addEdge(u, v, c);
        }
    }
    int ans{mf.flow(s, t)};
    std::cout << ans << '\n';
}
