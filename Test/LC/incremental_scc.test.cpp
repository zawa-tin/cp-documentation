#define PROBLEM "https://judge.yosupo.jp/problem/incremental_scc"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Graph/Components/IncrementalSCC.hpp"
#include "../../Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp" 
#include "atcoder/modint"

#include <iostream>
#include <vector>

using namespace zawa;
using mint = atcoder::modint998244353;

int main() {
    SetFastIO();
    int N, M;
    std::cin >> N >> M;
    std::vector<mint> X(N);
    for (auto& x : X) {
        int v;
        std::cin >> v;
        x = mint::raw(v);
    }
    IncrementalSCC g(N);
    for (int _{} ; _ < M ; _++) {
        int u, v;
        std::cin >> u >> v;
        g.addEdge(u, v);
    }
    std::vector<std::vector<int>> event(M);
    auto T{g.build()};
    for (int i{} ; i < M ; i++) {
        if (T[i] == T.invalid()) continue;
        event[T[i]].push_back(i);
    }
    DisjointSetUnion dsu(N);
    mint ans{}; 
    for (int i{} ; i < M ; i++) {
        for (auto j : event[i]) {
            auto [u, v]{g.getEdge(j)};
            u = dsu.leader(u);
            v = dsu.leader(v);
            if (u == v) continue;
            ans += X[u] * X[v];
            mint next{X[u] + X[v]};
            dsu.merge(u, v);
            X[dsu.leader(u)] = next;
        }
        std::cout << ans.val() << '\n';
    }
}
