#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/DataStructure/FenwickTree/FenwickTree.hpp"
#include "../../Src/Algebra/Group/AdditiveGroup.hpp"
#include "../../Src/Graph/Tree/HeavyLightDecomposition.hpp"

#include <cassert>
#include <iostream>
#include <vector>

int main() {
    using namespace zawa; 
    SetFastIO();
    int n, q; std::cin >> n >> q;
    std::vector<long long> a(n);
    for (auto& x : a) std::cin >> x;

    HeavyLightDecomposition hld(n);
    for (int _{} ; _ < n - 1 ; _++) {
        int u, v; std::cin >> u >> v;
        hld.addEdge(u, v);
    }
    hld.build(0);

    FenwickTree<AdditiveGroup<long long>> ft(n); 
    for (int i{} ; i < n ; i++) {
        ft.operation(hld[i], a[i]);
    }
    for (int _{} ; _ < q ; _++) {
        int t; std::cin >> t;
        if (t == 0) {
            int p, x; std::cin >> p >> x;
            ft.operation(hld[p], x);
            a[hld[p]] += x;
        }
        else if (t == 1) {
            int u, v; std::cin >> u >> v;
            long long ans{};
            auto decomp{hld(u, v)};
            for (const auto& p : hld(u, v)) {
                ans += ft.product(p.first(), p.second());
            }
            std::cout << ans << '\n';
        }
        else {
            assert(false);
        }
    }
}
