#define PROBLEM "https://atcoder.jp/contests/abc267/tasks/abc267_f"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Graph/Tree/LevelAncestor.hpp"
using namespace zawa;

#include <algorithm>
#include <iostream>
#include <iterator>
#include <utility>
#include <queue>
#include <vector>

int main() {
    SetFastIO();
    int n; std::cin >> n;
    std::vector g(n, std::vector<u32>{});
    for (u32 _{} ; _ < (u32)n - 1 ; _++) {
        u32 a, b; std::cin >> a >> b;
        a--; b--;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    auto bfs{[&](int s) -> std::vector<int> {
        std::vector<int> dist(n, n);
        dist[s] = 0;
        std::queue<int> que{ { s } };
        while (que.size()) {
            int v{que.front()};
            que.pop();
            for (auto x : g[v]) if (dist[x] > dist[v] + 1) {
                dist[x] = dist[v] + 1;
                que.emplace(x);
            }
        }
        return dist;
    }};

    auto dist1{bfs(0)};
    u32 L{(u32)std::distance(dist1.begin(), std::max_element(dist1.begin(), dist1.end()))};
    auto dist2{bfs(L)};
    u32 R{(u32)std::distance(dist2.begin(), std::max_element(dist2.begin(), dist2.end()))};

    LevelAncestor laL{g, L}, laR{g, R};
    int q; std::cin >> q;
    for (int _{} ; _ < q ; _++) {
        int u, k; std::cin >> u >> k;
        u--;
        auto vL{laL(u, k)};
        if (LevelAncestor::invalid(vL)) {
            auto vR{laR(u, k)};
            if (LevelAncestor::invalid(vR)) {
                std::cout << -1 << '\n';
            }
            else {
                std::cout << vR + 1 << '\n';
            }
        }
        else {
            std::cout << vL + 1 << '\n';
        }
    }
}
