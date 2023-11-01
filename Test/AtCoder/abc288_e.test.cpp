#define PROBLEM "https://atcoder.jp/contests/abc288/tasks/abc288_e"

#include "../../Src/DataStructure/SparseTable/SparseTable.hpp"
#include "../../Src/Algebra/Monoid/MaxMonoid.hpp"

#include <iostream>
#include <vector>

int main() {
    int n, m; std::cin >> n >> m;
    std::vector<int> a(n);
    for (auto& v : a) std::cin >> v;
    std::vector<int> c(n);
    for (auto& v : c) {
        std::cin >> v;
        v *= -1;
    }
    std::vector<int> x(n);
    for (int _{} ; _ < m ; _++) {
        int v; std::cin >> v;
        x[v - 1] = true;
    }

    using namespace zawa;
    SparseTable<MaxMonoid<int>> spt(c);
    
    const long long INF{(long long)1e18};
    std::vector<long long> dp(n + 1, INF);
    dp[0] = 0;

    for (int i{} ; i < n ; i++) {
        std::vector<long long> nxt(n + 1, INF);
        for (int j{} ; j <= i ; j++) {
            if (!x[i]) {
                nxt[j] = std::min(nxt[j], dp[j]);
            }
            long long cost{(long long)a[i] - spt.product(i - j, i + 1)};
            nxt[j + 1] = std::min(nxt[j + 1], dp[j] + cost);
        }
        dp = std::move(nxt);
    }

    long long ans{*std::min_element(dp.begin(), dp.end())};
    std::cout << ans << std::endl;
}
