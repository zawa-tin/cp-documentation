#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * 「みんなのプロコン 2018」決勝 オープンコンテスト - C 木の問題
 * https://atcoder.jp/contests/yahoo-procon2018-final-open/submissions/60475048
 */

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Graph/Tree/Centroid.hpp"

#include <iostream>
#include <utility>
#include <vector>

using namespace zawa;

void solve() {
    int N, Q;
    std::cin >> N >> Q;
    std::vector<std::vector<int>> g(N);
    for (int _{} ; _ < N - 1 ; _++) {
        int A, B;
        std::cin >> A >> B;
        A--; B--;
        g[A].push_back(B);
        g[B].push_back(A);
    }
    std::vector<std::vector<std::pair<int, int>>> query(N);
    for (int i{} ; i < Q ; i++) {
        int v, k;
        std::cin >> v >> k;
        v--;
        query[v].push_back(std::make_pair(k, i));
    }
    Centroid C(std::move(g));
    std::vector<int> dep(N);
    auto calc_dep{[&](auto dfs, int v, int p, int d) -> void {
        dep[v] = d;
        for (auto x : C[v]) if (!C.isRemoved(x) and (int)x != p) {
            dfs(dfs, x, v, d + 1);
        }
    }};
    std::vector<int> ans(Q);
    auto dfs{[&](auto dfs, int v) -> void {
        v = C.rooting(v);
        calc_dep(calc_dep, v, -1, 0);
        C.remove(v);
        std::vector<std::vector<int>> comp;
        for (auto x : C.adjlist(v)) {
            comp.push_back(C.component(x));
        }
        int max_d{};
        for (const auto& com : comp) {
            for (auto x : com) max_d = std::max(max_d, dep[x]);
        }
        std::vector<int> cnt(max_d + 1);
        cnt[0]++;
        for (const auto& com : comp) {
            for (auto x : com) cnt[dep[x]]++;
        }
        for (auto [k, i] : query[v]) {
            if (k <= max_d) {
                ans[i] += cnt[k];
            }
        }
        for (const auto& com : comp) {
            for (auto x : com) cnt[dep[x]]--;
            for (auto x : com) {
                for (auto [k, i] : query[x]) {
                    int d{k - dep[x]};
                    if (0 <= d and d <= max_d) ans[i] += cnt[d];
                }
            }
            for (auto x : com) cnt[dep[x]]++;
        }
        for (auto x : C.adjlist(v)) {
            dfs(dfs, x);
        }
    }};
    dfs(dfs, 0);
    for (int i{} ; i < Q ; i++) {
        std::cout << ans[i] << '\n';
    }
}

int main() {
#ifdef ATCODER
    SetFastIO();
    solve();
#else
    std::cout << "Hello World" << '\n';
#endif
}
