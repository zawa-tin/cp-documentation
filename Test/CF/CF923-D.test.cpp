#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Algebra/Monoid/ChminMonoid.hpp"
#include "../../Src/Algebra/Monoid/ChmaxMonoid.hpp"
#include "../../Src/DataStructure/SparseTable/SparseTable.hpp"

#include <iostream>
using namespace zawa;

using M1 = ChmaxMonoid<int, int>;
using M2 = ChminMonoid<int, int>;

void solve() {
    int t; std::cin >> t;
    while (t--) {
        int n; std::cin >> n;
        std::vector<M1::Element> a(n);
        std::vector<M2::Element> b(n);
        for (int i{} ; i < n ; i++) {
            int v; std::cin >> v;
            a[i] = { v, i + 1 };
            b[i] = { v, i + 1 };
        }
        SparseTable<M1> spt1(a);
        SparseTable<M2> spt2(b);
        int q; std::cin >> q;
        for (int _{} ; _ < q ; _++) {
            int l, r; std::cin >> l >> r;
            l--;
            auto prod1{spt1.product(l, r)};
            auto prod2{spt2.product(l, r)};
            if (prod1.priority() == prod2.priority()) {
                std::cout << -1 << ' ' << -1 << '\n';
            }
            else {
                std::cout << prod1.value() << ' ' << prod2.value() << '\n';
            }
        }
    }
}

int main() {
#ifdef ONLINE_JUDGE
    SetFastIO();
    solve();
#else
    std::cout << "Hello World" << '\n';
#endif
}
