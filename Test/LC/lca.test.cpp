#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Graph/Tree/LowestCommonAncestor.hpp"
using namespace zawa;

int main() {
    SetFastIO();
    int n, q; std::cin >> n >> q; 
    LowestCommonAncestor lca{n, 0};
    for (int i{1} ; i < n ; i++) {
        int p; std::cin >> p;
        lca.addEdge(p, i);
    }
    lca.build();
    for (int _{} ; _ < q ; _++) {
        int u, v; std::cin >> u >> v;
        int ans{lca(u, v)};
        std::cout << ans << '\n';
    }
}
