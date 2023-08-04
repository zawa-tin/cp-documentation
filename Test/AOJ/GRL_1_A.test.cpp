#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Template/Chmin.hpp"

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace zawa;

int main() {
    usize N, M; std::cin >> N >> M;
    u32 r; std::cin >> r;
    std::vector<std::vector<std::pair<u32, u32>>> G(N);
    for (u32 _{} ; _ < M ; _++) {
        u32 u, v, c; std::cin >> u >> v >> c;
        G[u].emplace_back(v, c);
    }

    const u64 inf{(1LL << 60)};
    std::vector<u64> dist(N, inf);
    dist[r] = 0;
    using qt = std::pair<u64, u32>;
    std::priority_queue<qt, std::vector<qt>, std::greater<qt>> que;
    que.emplace(0LL, r);
    while (que.size()) {
        auto [d, v]{ que.top() };
        que.pop();
        if (dist[v] < d) continue;
        for (auto [x, w] : G[v]) {
            if (Chmin(dist[x], d + w)) {
                que.emplace(dist[x], x);
            }
        }
    }

    for (auto d : dist) {
        if (d == inf) std::cout << "INF" << std::endl;
        else std::cout << d << std::endl;
    }
}
