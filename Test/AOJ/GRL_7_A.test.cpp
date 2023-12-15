#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/7/GRL_7_A"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Graph/Flow/Dinic.hpp"

int main() {
    using namespace zawa;
    SetFastIO();
    int x, y, m; std::cin >> x >> y >> m;
    Dinic<int> maxflow(x + y + 2);
    for (int i{} ; i < x ; i++) {
        maxflow.addEdge(x + y, i, 1);
    }
    for (int i{} ; i < y ; i++) {
        maxflow.addEdge(x + i, x + y + 1, 1);
    }
    for (int i{} ; i < m ; i++) {
        int u, v; std::cin >> u >> v;
        maxflow.addEdge(u, x + v, 1);
    }
    int ans{maxflow.flow(x + y, x + y + 1)};
    std::cout << ans << '\n';
}
