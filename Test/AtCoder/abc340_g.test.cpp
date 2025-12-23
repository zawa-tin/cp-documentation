//#define PROBLEM "https://atcoder.jp/contests/abc340/tasks/abc340_g"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Graph/Tree/AuxiliaryTree.hpp"
#include "atcoder/modint"

#include <array>
#include <algorithm>
#include <iostream>
#include <set>

using namespace zawa;
using mint = atcoder::modint998244353;

int main() {
#ifdef ATCODER
    int N;
    std::cin >> N;
    std::vector<std::vector<int>> A(N);
    std::vector<int> col(N);
    for (int i{} ; i < N ; i++) {
        std::cin >> col[i];
        col[i]--;
        A[col[i]].push_back(i);
    }
    std::vector<std::vector<int>> g(N);
    for (int i{} ; i < N - 1 ; i++) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    AuxiliaryTree AT{g};
    mint ans{};
    for (int c{} ; c < N ; c++) {
        if (A[c].empty()) {
            continue;
        }
        int r{(int)AT.construct(A[c])};
        auto dfs{[&](auto dfs, int v, int p) -> mint {
            std::array<mint, 3> dp{ mint{1}, mint{0}, mint{0} };
            for (auto x : AT[v]) {
                if ((int)x == p) continue;
                std::array<mint, 3> next{ dp };
                mint chval{dfs(dfs, x, v)};
                for (int i{} ; i < 3 ; i++) {
                    next[std::min(2, i + 1)] += dp[i] * chval;
                }
                dp = next;
            }
            ans += dp[2];
            if (col[v] == c) {
                dp[1]++;
                ans += dp[1];
            }
            return dp[1] + dp[2];
        }};
        dfs(dfs, r, -1);
    }
    std::cout << ans.val() << '\n';
#else
    std::cout << "Hello World\n";
#endif
}
