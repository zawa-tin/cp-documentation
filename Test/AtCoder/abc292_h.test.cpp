#define PROBLEM "https://atcoder.jp/contests/abc292/tasks/abc292_ex"
#define ERROR 1e-9

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Algebra/Monoid/AdditionMonoid.hpp"
#include "../../Src/Algebra/Monoid/MaxMonoid.hpp"
#include "../../Src/Algebra/Monoid/PrefixProductMonoid.hpp"
#include "../../Src/DataStructure/SegmentTree/SegmentTree.hpp"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <optional>
#include <vector>

using namespace zawa; 
using D = std::optional<long long>;
using vM = MaxMonoid<long long>;
struct oM {
    using Element = D;
    static D identity() noexcept {
        return 0LL;
    }
    static D operation(const D& l, const D& r) noexcept {
        if (l and r) return l.value() + r.value();
        else return (l ? l : (r ? r : 0LL));
    }
};
using M = PrefixProductMonoid<oM, vM>;

int main() {
    SetFastIO();
    SetPrecision(10);

    int n, q;
    long long b;
    std::cin >> n >> b >> q;
    std::vector<M::Element> a(n);
    for (int i{} ; i < n ; i++) {
        long long v; std::cin >> v;
        a[i] = M::Element{D{v - b}, D{v - b}};
    }
    SegmentTree<M> seg(a);
    for (int _{} ; _ < q ; _++) {
        int c; std::cin >> c;
        c--;
        long long x; std::cin >> x;
        x -= b;
        seg.set(c, M::Element{D{x}, D{x}});
        auto r{seg.maxRight(0, [](const M::Element& v) -> bool { return (!(bool)v.prefix() or v.prefix().value() < 0LL); })};
        r = std::min<int>(r + 1, n);
        assert(seg.product(0, r).product().has_value());
        long long sum{seg.product(0, r).product().value()};
        long double ans{(long double)(sum + b * (long long)r) / (long double)r};
        std::cout << ans << '\n';
    }
}
