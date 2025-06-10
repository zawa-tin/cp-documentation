#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_B"

#include "../../Src/Graph/Components/Lowlink.hpp"

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace zawa;

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, m; 
    std::cin >> n >> m;
    Lowlink g(n);
    for (int _{} ; _ < m ; _++) {
        int s, t; 
        std::cin >> s >> t;
        g.addEdge(s, t);
    }
    auto info{g.build()};
    std::vector<std::pair<int, int>> ans;
    for (int i{} ; i < m ; i++) {
        if (info.isBridge(i)) {
            auto [u, v]{g.edge(i)};
            ans.emplace_back(std::min(u, v), std::max(u, v));
        }
    }
    std::sort(ans.begin(), ans.end());
    for (auto [u, v] : ans) {
        std::cout << u << ' ' << v << '\n';
    }
}
