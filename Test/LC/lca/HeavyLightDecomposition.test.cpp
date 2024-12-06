#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../../../Src/Template/IOSetting.hpp"
#include "../../../Src/Graph/Tree/HeavyLightDecomposition.hpp"

using namespace zawa;

int main() {
    SetFastIO();
    int N, Q;
    std::cin >> N >> Q;
    std::vector<std::vector<int>> T(N);
    for (int i{1} ; i < N ; i++) {
        int p;
        std::cin >> p;
        T[p].push_back(i);
        T[i].push_back(p);
    }
    HeavyLightDecomposition hld(T, 0);
    while (Q--) {
        int u, v;
        std::cin >> u >> v;
        std::cout << hld.lca(u, v) << '\n';
    }
}
