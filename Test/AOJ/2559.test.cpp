#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2559"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/DataStructure/SparseTable/DualSparseTable.hpp"
#include "../../Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp"
#include "../../Src/Graph/Tree/HeavyLightDecomposition.hpp"

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cassert>

using namespace zawa;

struct MIN {
    using Element = int;
    static Element operation(Element L, Element R) {
        return std::min(L, R);
    }
};

int main() {
    SetFastIO();

    int N, M;
    std::cin >> N >> M;
    std::vector<std::tuple<int, int, int, int>> E(M);
    for (int i{} ; auto& [w, a, b, id] : E) {
        std::cin >> a >> b >> w;
        a--; b--;
        id = i++;
    }
    std::sort(E.begin(), E.end());
    DisjointSetUnion dsu(N);  
    std::vector<int> id(M, -1);
    int use_edge{};
    long long base{};
    for (auto [w, a, b, i] : E) {
        if (dsu.same(a, b)) continue;
        base += w;
        dsu.merge(a, b);
        id[i] = N + use_edge++;
    }
    assert(use_edge <= N - 1);
    if (use_edge < N - 1) {
        for (int i{} ; i < M ; i++) std::cout << -1 << '\n';
        return 0;
    }
    Tree T(N + N - 1);
    for (auto [_, a, b, i] : E) if (id[i] != -1) {
        AddEdge(T, a, id[i]);
        AddEdge(T, b, id[i]);
    }
    HeavyLightDecomposition hld{T};
    const int INF{(int)2e9};
    DualSparseTable<MIN> spt{std::vector<int>(N + N - 1, INF)};
    for (auto [w, a, b, i] : E) if (id[i] == -1) {
        for (auto [l, r] : hld(a, b)) {
            l = hld[l];
            r = hld[r];
            if (l > r) std::swap(l, r);
            spt.operation(l, r + 1, w);
        }
    }
    auto prod{spt.build()};
    std::vector<long long> ans(M, -1LL);
    for (auto [w, a, b, i] : E) {
        if (id[i] == -1) ans[i] = base;
        else {
            int find{prod[hld[id[i]]]};
            ans[i] = (find == INF ? -1LL : base - w + find);
        }
    }
    for (int i{} ; i < M ; i++) {
        std::cout << ans[i] << '\n';
    }
}
