#define PROBLEM "https://atcoder.jp/contests/abc302/tasks/abc302_h"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/DataStructure/DisjointSetUnion/UndoableDisjointSetUnion.hpp"
#include "../../Src/DataStructure/Undoable/UndoableValue.hpp"
#include "../../Src/DataStructure/Undoable/UndoableVector.hpp"

#include <cassert>
#include <iostream>
using namespace zawa;

int main() {
    SetFastIO();

    int N;
    std::cin >> N;
    std::vector<std::vector<int>> g(N);
    std::vector<int> A(N), B(N);
    for (int i{} ; i < N ; i++) {
        std::cin >> A[i] >> B[i];
        A[i]--; B[i]--;
    }
    for (int _{} ; _ < N - 1 ; _++) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    UndoableValue<int> cur{};
    UndoableVector<int> edge(N);
    UndoableDisjointSetUnion dsu(N);
    std::vector<int> ans(N);
    auto dfs{[&](auto dfs, int v, int p) -> void {
        int a{(int)dsu.leader(A[v])}, b{(int)dsu.leader(B[v])};
        if (a == b) {
            int old_val{std::min(edge[a], (int)dsu.size(a))};
            edge.assign(a, edge[a] + 1);
            int new_val{std::min(edge[a], (int)dsu.size(a))};
            cur.assign(cur.value() - old_val + new_val);
            dsu.merge(a, b);
        }
        else {
            int old_val{std::min(edge[a], (int)dsu.size(a)) + std::min(edge[b], (int)dsu.size(b))};
            dsu.merge(a, b);
            int led{(int)dsu.leader(a)};
            edge.assign(led, edge[a] + edge[b] + 1);
            int new_val{std::min(edge[led], (int)dsu.size(led))};
            cur.assign(cur.value() - old_val + new_val);
        }
        ans[v] = cur.value();
        for (auto x : g[v]) if (x != p) {
            dfs(dfs, x, v);
        }
        dsu.undo();
        cur.undo();
        edge.undo();
    }};
    dfs(dfs, 0, -1);
    for (int i{1} ; i < N ; i++) {
        std::cout << ans[i] << (i + 1 == N ? '\n' : ' ');
    }
}
