#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2828"

#include "../../Src/Graph/Flow/SuccessiveShortestPath.hpp"
#include "../../Src/Template/IOSetting.hpp"

#include <algorithm>
#include <iostream>
#include <numeric>

bool solve() {
    using namespace zawa;
    int n; std::cin >> n;
    if (n == 0) return false;
    std::vector<std::array<int, 3>> a(n);
    for (auto& x : a) {
        for (auto& v : x) std::cin >> v;
        std::sort(x.begin(), x.end());
    }
    SuccessiveShortestPath<int, int> mcf(2 * n + 2);
    int source{2 * n}, sink{source + 1};
    for (int i{} ; i < n ; i++) {
        mcf.addEdge(source, i, 1, 0);
        mcf.addEdge(n + i, sink, 1, 0);
    }
    std::vector<int> big(n);
    for (int i{} ; i < n ; i++) {
        big[i] = a[i][0] * a[i][1] * a[i][2];
    }
    for (int i{} ; i < n ; i++) {
        for (int j{} ; j < n ; j++) {
            bool ok{true};
            for (int k{} ; k < 3 ; k++) ok &= a[i][k] > a[j][k];
            if (ok) {
                mcf.addEdge(i, n + j, 1, -big[j]);
            }
        }
    }
    mcf.dagdp(source, sink);
    mcf.updatePotential();
    int sum{std::accumulate(big.begin(), big.end(), 0)};
    int ans{sum};
    for (const auto& flow : mcf.slope(source, sink)) {
        ans = std::min(ans, sum + flow);
    }
    std::cout << ans << '\n';
    return true;
}

int main() {
    while (solve()) ;
}
