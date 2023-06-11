#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_11_D"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Graph/Basis/AdjacentList.hpp"
#include "../../Src/Graph/ConnectedComponents.hpp"

#include <iostream>

using namespace zawa;

int main() {
    usize n, m;
    std::cin >> n >> m;

    Graph<u32> G(n);
    for (u32 _ = 0 ; _ < m ; _++) {
        u32 u, v;
        std::cin >> u >> v;
        G.addUndirectedEdge(u, v);
    }

    ConnectedComponents cc(G);

    usize q;
    std::cin >> q;
    for (u32 _ = 0 ; _ < q ; _++) {
        u32 s, t;
        std::cin >> s >> t;
        std::cout << (cc.same(s, t) ? "yes" : "no") << std::endl;
    }
}
