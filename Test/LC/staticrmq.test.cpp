#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../../Src/DataStructure/SparseTable/SparseTable.hpp"
#include "../../Src/Algebra/Monoid/MinMonoid.hpp"
#include "../../Src/Template/IOSetting.hpp"

#include <iostream>
#include <vector>

int main() {
    using namespace zawa;
    SetFastIO();
    using M = MinMonoid<int>;
    using MD = M::Element;
    int n, q; std::cin >> n >> q;
    std::vector<MD> a(n);
    for (auto& x : a) {
        int v; std::cin >> v;
        x = v;
    }
    SparseTable<M> spt(a);
    for (int _{} ; _ < q ; _++) {
        int l, r; std::cin >> l >> r;
        MD ans{spt.product(l, r)};
        std::cout << ans.value() << '\n';
    }
}
