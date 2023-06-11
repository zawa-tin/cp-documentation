#define PROBLEM "https://atcoder.jp/contests/abc288/tasks/abc288_c"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Graph/Basis/AdjacentList.hpp"
#include "../../Src/Graph/ConnectedComponents.hpp"

#include <iostream>
#include <cassert>

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

    u32 ans{};
    for (u32 i = 0 ; i < cc.size() ; i++) {
        ans += cc.sizeE(i) - cc.sizeV(i) + 1;
    }

    std::cout << ans << std::endl;
}
