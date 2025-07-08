// #define PROBLEM "https://codeforces.com/contest/1927/problem/F"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/Graph/Components/Lowlink.hpp"

using namespace zawa;

#include <iostream>
#include <tuple>
#include <vector>

/*
 * Codeforces Round 923 (Div. 3) - F Microcycle
 * https://codeforces.com/contest/1927/submission/328032871
 */

void solve() {
    int t; std::cin >> t;
    while (t--) {
        int n, m; std::cin >> n >> m;
        std::vector<std::tuple<int, int, int>> e(m);
        Lowlink low(n);
        for (auto& [u, v, w] : e) {
            std::cin >> u >> v >> w;
            u--; v--;
            low.addEdge(u, v);
        }
        auto info{low.build()};
        int ans{(int)1e9}, ansId{-1};
        for (int i{} ; i < m ; i++) {
            if (info.isBridge(i)) continue;
            if (ans > std::get<2>(e[i])) {
                ans = std::get<2>(e[i]);
                ansId = i;
            }
        }
        std::vector<int> path;
        std::vector<bool> vis(n);
        auto dfs{[&](auto dfs, int v) -> bool {
            vis[v] = true;
            if (v == std::get<1>(e[ansId])) {
                path.push_back(v + 1);
                return true;
            }
            for (auto [x, i] : low[v]) {
                if ((int)i == ansId) continue;
                if (vis[x]) continue;
                if (dfs(dfs, x)) {
                    path.push_back(v + 1);
                    return true;
                }
            }
            return false;
        }};
        assert(dfs(dfs, std::get<0>(e[ansId])));
        std::cout << ans << ' ' << path.size() << '\n';
        for (int i{} ; i < (int)path.size() ; i++) {
            std::cout << path[i] << (i + 1 == (int)path.size() ? '\n' : ' ');
        }
    }
}

int main() {
#ifdef ONLINE_JUDGE
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    solve();
#else
    std::cout << "Hello World" << '\n';
#endif
}
