#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Graph/Flow/Dinic.hpp"

int main() {
    using namespace zawa;
    int n, m; std::cin >> n >> m;
    Dinic<int> solver(n);
    for (int _{} ; _ < m ; _++) {
        int u, v, c; std::cin >> u >> v >> c;
        solver.addEdge(u, v, c);
    }
    int ans{solver.flow(0, n - 1)};
    std::cout << ans << '\n';
}
