#define PROBLEM "https://atcoder.jp/contests/abc292/tasks/abc292_d"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Graph/Basis/AdjacentList.hpp"
#include "../../Src/Graph/ConnectedComponents.hpp"

#include <iostream>

using namespace zawa;

int main() {
    usize N, M;
    std::cin >> N >> M;
    Graph<u32> G(N);
    for (u32 _ = 0 ; _ < M ; _++) {
        u32 u, v;
        std::cin >> u >> v;
        u--; v--;
        G.addUndirectedEdge(u, v);
    }

    ConnectedComponents cc(G);

    bool ans = true;
    for (u32 i = 0 ; i < cc.size() ; i++) {
        ans &= cc.sizeV(i) == cc.sizeE(i);
    }

    std::cout << (ans ? "Yes" : "No") << std::endl;
}
