#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_D"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Graph/Components/ConnectedComponents.hpp"

#include <iostream>

using namespace zawa;

int main() {
    u32 n, m;
    std::cin >> n >> m;

    ConnectedComponents cc{ n };
    for (u32 _{} ; _ < m ; _++) {
        u32 u, v;
        std::cin >> u >> v;
        cc.addEdge(u, v);
    }

    cc.build();

    u32 q;
    std::cin >> q;

    for (u32 _{} ; _ < q ; _++) {
        u32 u, v;
        std::cin >> u >> v;
        std::cout << (cc.same(u, v) ? "yes" : "no") << std::endl;
    }
}
