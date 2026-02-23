#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/0465"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Graph/Tree/HeavyLightDecomposition.hpp"

#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

#include "atcoder/modint"
using mint = atcoder::modint998244353;
using namespace zawa;

int main() {
    SetFastIO();

    int N;
    std::cin >> N;
    std::vector<std::vector<int>> T(N);
    for (int _{} ; _ < N - 1 ; _++) {
        int s, t;
        std::cin >> s >> t;
        s--; t--;
        T[s].push_back(t);
        T[t].push_back(s);
    }
    HeavyLightDecomposition hld(T, 0);
    std::vector<mint> prod(N), invprod(N);
    auto dfs{[&](auto dfs, int v, int p) -> void {
        prod[v] = (p == -1 ? mint::raw(1) : prod[p] * mint{hld.size(p) - hld.size(v)});
        invprod[v] = prod[v].inv();
        for (auto x : T[v]) if (x != p) dfs(dfs, x, v);
    }};
    dfs(dfs, 0, -1);
    int Q;
    std::cin >> Q;
    while (Q--) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
        if (hld.depth(u) < hld.depth(v)) std::swap(u, v);
        int lca{(int)hld.lca(u, v)};
        assert(u != lca);
        if (v == lca) {
            auto a{hld.levelAncestor(u, hld.depth(u) - hld.depth(v) - 1).value()};
            mint ans{prod[u] * invprod[a]};
            std::cout << ans.val() << '\n';
        } 
        else {
            auto a{hld.levelAncestor(u, hld.depth(u) - hld.depth(lca) - 1).value()};
            auto b{hld.levelAncestor(v, hld.depth(v) - hld.depth(lca) - 1).value()};
            mint ans{1};
            ans *= prod[u] * invprod[a];
            ans *= mint{N - hld.size(a) - hld.size(b)};
            ans *= prod[v] * invprod[b];
            std::cout << ans.val() << '\n';
        }
    }
}
