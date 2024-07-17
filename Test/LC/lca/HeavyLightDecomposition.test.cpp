#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../../../Src/Template/IOSetting.hpp"
#include "../../../Src/Graph/Tree/Tree.hpp"
#include "../../../Src/Graph/Tree/HeavyLightDecomposition.hpp"

using namespace zawa;

int main() {
    SetFastIO();
    int N, Q;
    std::cin >> N >> Q;
    Tree T(N);
    for (int i{1} ; i < N ; i++) {
        int p;
        std::cin >> p;
        AddEdge(T, p, i);
    }
    HeavyLightDecomposition hld(T, 0);
    while (Q--) {
        int u, v;
        std::cin >> u >> v;
        std::cout << hld.lca(u, v) << '\n';
    }
}
