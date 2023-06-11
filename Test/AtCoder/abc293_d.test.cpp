#define PROBLEM "https://atcoder.jp/contests/abc293/tasks/abc293_d"

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
        u32 a, c;
        u8 b, d;
        std::cin >> a >> b >> c >> d;
        a--; c--;
        G.addUndirectedEdge(a, c);
    }

    ConnectedComponents cc(G);

    u32 yes{}, no{};

    for (u32 i = 0 ; i < cc.size() ; i++) {
        (cc.hasCycle(i) ? yes : no)++;
    }

    std::cout << yes << ' ' << no << std::endl;
}
