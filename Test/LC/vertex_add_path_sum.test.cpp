#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/DataStructure/FenwickTree/FenwickTree.hpp"
#include "../../Src/Algebra/Group/AdditiveGroup.hpp"
#include "../../Src/Graph/Tree/HeavyLightDecomposition.hpp"

#include <cassert>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
    using namespace zawa; 
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int N, Q;
    std::cin >> N >> Q;
    std::vector<int> A(N);
    for (int& a : A) std::cin >> a;
    std::vector<std::vector<int>> T(N);
    for (int _{} ; _ < N - 1 ; _++) {
        int u, v;
        std::cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    HeavyLightDecomposition hld(T);
    std::vector<long long> init(N);
    for (int v{} ; v < N ; v++) {
        init[hld[v]] = A[v];
    }
    FenwickTree<AdditiveGroup<long long>> fen{init};
    while (Q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int p, x;
            std::cin >> p >> x;
            fen.operation(hld[p], x);
        }
        else if (t == 1) {
            int u, v;
            std::cin >> u >> v;
            long long ans{};
            for (auto [u, v] : hld.pathQuery(u, v)) {
                if (u > v) std::swap(u, v);
                ans += fen.product(u, v + 1);
            }
            std::cout << ans << '\n';
        }
        else {
            assert(false);
        }
    }
}
