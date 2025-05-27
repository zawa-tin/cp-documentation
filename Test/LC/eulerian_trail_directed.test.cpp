#define PROBLEM "https://judge.yosupo.jp/problem/eulerian_trail_directed"

#include "../../Src/Graph/EulerianTrail.hpp"
using namespace zawa;

#include <iostream>
#include <utility>
#include <vector>

void solve() {
    int N, M;
    std::cin >> N >> M;
    std::vector<std::pair<int, int>> E(M);
    for (auto& [u, v] : E) std::cin >> u >> v;
    auto ans = EulerianTrail(N, E, true);
    if (ans) {
        std::cout << "Yes\n";
        auto [vs, es] = std::move(*ans);
        for (int i = 0 ; i < std::ssize(vs) ; i++) std::cout << vs[i] << (i + 1 == std::ssize(vs) ? "" : " ");
        std::cout << '\n';
        for (int i = 0 ; i < std::ssize(es) ; i++) std::cout << es[i] << (i + 1 == std::ssize(es) ? "" : " ");
        std::cout << '\n';
    }
    else {
        std::cout << "No\n";
    }
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}
