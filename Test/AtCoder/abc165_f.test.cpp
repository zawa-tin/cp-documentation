#define PROBLEM "https://atcoder.jp/contests/abc165/tasks/abc165_f"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/DataStructure/Undoable/UndoableVector.hpp"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace zawa;


int main() {
    SetFastIO();
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (auto& a : A) std::cin >> a;
    std::vector<std::vector<int>> g(N);
    for (int i{} ; i < N - 1 ; i++) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    const int INF{(int)2e9};
    UndoableVector<int> dp(N, INF);
    std::vector<int> ans(N);
    auto dfs{[&](auto dfs, int v, int p) -> void {
        int pos{(int)std::distance(dp.begin(), std::lower_bound(dp.begin(), dp.end(), A[v]))};
        dp.assign(pos, A[v]);
        ans[v] = (int)std::distance(dp.begin(), std::lower_bound(dp.begin(), dp.end(), INF));
        for (auto x : g[v]) if (x != p) {
            dfs(dfs, x, v);
        }
        dp.undo();
    }};
    dfs(dfs, 0, -1);
    for (int i{} ; i < N ; i++) {
        std::cout << ans[i] << '\n';
    }
}
