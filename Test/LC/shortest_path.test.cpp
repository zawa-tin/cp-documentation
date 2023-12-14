#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Graph/ShortestPath/Dijkstra.hpp"

int main() {
    using namespace zawa;
    SetFastIO();
    int n, m, s, t; std::cin >> n >> m >> s >> t;
    Dijkstra<u64> solver(n);
    for (int _{} ; _ < m ; _++) {
        int a, b, c; std::cin >> a >> b >> c;
        solver.addDirectedEdge(a, b, (u64)c);
    }
    auto tree{solver.build(s)};
    if (tree.connect(t)) {
        auto recover{tree.pathV(t)};
        std::cout << tree.dist(t) << ' ' << recover.size() - 1 << '\n';
        for (u32 i{} ; i + 1 < recover.size() ; i++) {
            std::cout << recover[i] << ' ' << recover[i + 1] << '\n';
        }
    }
    else {
        std::cout << -1 << '\n';
    }
}
