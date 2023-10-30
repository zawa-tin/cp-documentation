#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../../Src/DataStructure/SparseTable/SparseTable.hpp"
#include "../../Src/Algebra/Monoid/MinMonoid.hpp"
#include "../../Src/Template/IOSetting.hpp"

#include <iostream>
#include <vector>

int main() {
    using namespace zawa;
    SetFastIO();
    int n, q; std::cin >> n >> q;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    SparseTable<MinMonoid<int>> spt(a);
    for (int _{} ; _ < q ; _++) {
        int l, r; std::cin >> l >> r;
        int ans{spt.product(l, r)};
        std::cout << ans << '\n';
    }
}
