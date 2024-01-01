#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_B"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Graph/Flow/SuccessiveShortestPath.hpp"

#include <iostream>

int main() {
    using namespace zawa;
    SetFastIO();
    int n, m, f; std::cin >> n >> m >> f;
    SuccessiveShortestPath<int, int> mcf(n);
    int source{}, sink{n - 1};
    for (int _{} ; _ < m ; _++) {
        int u, v, c, d; std::cin >> u >> v >> c >> d;
        mcf.addEdge(u, v, c, d);
    }
    if (mcf.flow(source, sink, f)) {
        std::cout << mcf.minCost() << '\n';
    }
    else {
        std::cout << -1 << '\n';
    }
}
