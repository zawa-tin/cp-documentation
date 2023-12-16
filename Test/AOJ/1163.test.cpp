#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/1163"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Graph/Flow/Dinic.hpp"

#include <iostream>
#include <numeric>
#include <vector>

bool solve() {
    using namespace zawa;
    SetFastIO();
    int n, m; std::cin >> n >> m;
    if (n == 0 and m == 0) return false;
    std::vector<int> a(n), b(m);
    for (auto& x : a) std::cin >> x;
    for (auto& x : b) std::cin >> x;
    Dinic<int> maxflow(2 + n + m);
    for (int i{} ; i < n ; i++) {
        maxflow.addEdge(n + m, i, 1);
    }
    for (int i{} ; i < m ; i++) {
        maxflow.addEdge(n + i, n + m + 1, 1);
    }
    for (int i{} ; i < n ; i++) for (int j{} ; j < m ; j++) {
        if (std::gcd(a[i], b[j]) > 1) {
            maxflow.addEdge(i, n + j, 1);
        }
    }
    int ans{maxflow.flow(n + m, n + m + 1)};
    std::cout << ans << '\n';
    return true;
}

int main() {
    while (solve()) {}
}
