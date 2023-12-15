#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/3168"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Graph/Flow/Dinic.hpp"

#include <iostream>
#include <utility>
#include <vector>

bool adjust(char a, char b) {
    if (a > b) std::swap(a, b);
    if (a == 'a' and b == 'z') return true;
    return (int)(b - a) == 1;
}

int main() {
    using namespace zawa;
    int n, m, k; std::cin >> n >> m >> k;
    std::vector<char> s(n);
    for (auto& c : s) std::cin >> c;
    const int INF{(int)1e9};
    std::vector g(n, std::vector<int>(n, INF));
    for (int i{} ; i < n ; i++) g[i][i] = 0;
    for (int _{} ; _ < m ; _++) {
        int u, v; std::cin >> u >> v;
        u--; v--;
        g[u][v] = g[v][u] = 1;
    }
    for (int k{} ; k < n ; k++) {
        for (int i{} ; i < n ; i++) {
            for (int j{} ; j < n ; j++) {
                g[i][j] = std::min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    Dinic<int> solver(2 * n + 2);
    for (int i{} ; i < n ; i++) {
        solver.addEdge(2 * n, i, 1);
        solver.addEdge(n + i, 2 * n + 1, 1);
    }
    for (int i{} ; i < n ; i++) {
        for (int j{i + 1} ; j < n ; j++) {
            if (g[i][j] > k) continue;
            if (!adjust(s[i], s[j])) continue;
            if (s[i] % 2) {
                solver.addEdge(i, n + j, 1);
            }
            else {
                solver.addEdge(j, n + i, 1);
            }
        }
    }
    int ans{solver.flow(2 * n, 2 * n + 1)};
    std::cout << ans << '\n';
}
