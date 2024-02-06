#define PROBLEM "https://atcoder.jp/contests/abc292/tasks/abc292_ex"
#define ERROR 1e-9

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Algebra/Monoid/AdditionMonoid.hpp"
#include "../../Src/Algebra/Monoid/MaxMonoid.hpp"
#include "../../Src/Algebra/Monoid/PrefixProductMonoid.hpp"
#include "../../Src/DataStructure/SegmentTree/SegmentTree.hpp"

using namespace zawa; 
using M = PrefixProductMonoid<AdditionMonoid<long long>, MaxMonoid<long long>>;
using MD = typename M::Element;

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

int main() {
    SetFastIO();
    SetPrecision(10);

    int n, q;
    long long b;
    std::cin >> n >> b >> q;
    std::vector<MD> a(n);
    for (int i{} ; i < n ; i++) {
        long long v; std::cin >> v;
        a[i] = MD{v - b, v - b};
    }
    SegmentTree<M> seg(a);
    for (int _{} ; _ < q ; _++) {
        int c; std::cin >> c;
        c--;
        long long x; std::cin >> x;
        x -= b;
        seg.set(c, MD{x, x});
        auto r{seg.maxRight(0, [](const auto& v) -> bool { return v.prefix() < 0LL; })};
        r = std::min<int>(r + 1, n);
        long long sum{seg.product(0, r).product()};
        long double ans{(long double)(sum + b * (long long)r) / (long double)r};
        std::cout << ans << '\n';
    }
}
