#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_A"

#include "../../Src/Graph/Components/Lowlink.hpp"

using namespace zawa;

#include <iostream>

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, m; 
    std::cin >> n >> m;
    Lowlink g(n);
    for (int _{} ; _ < m ; _++) {
        int s, t; std::cin >> s >> t;
        g.addEdge(s, t);
    }
    auto ans{g.build()};
    for (int i{} ; i < n ; i++) {
        if (ans.isArticulation(i)) {
            std::cout << i << '\n';
        }
    }
}
