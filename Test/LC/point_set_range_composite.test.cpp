#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/DataStructure/SegmentTree/SegmentTree.hpp"

#include <iostream>

using namespace zawa;

constexpr u64 mod{ 998244353 };

struct Linear {
    u64 a{1}, b{};
    constexpr Linear() {}
    constexpr Linear(u64 a, u64 b) : a{a % mod}, b{b % mod} {}
    u64 apply(u64 x) const {
        return ((a * x) % mod + b) % mod;
    }
    friend std::ostream& operator<<(std::ostream& os, const Linear& v) {
        os << '(' << v.a << ' ' << v.b << ')';
        return os;
    }    
};

struct Monoid {
    using Element = Linear;
    static constexpr Linear identity() {
        return Linear{};
    }
    static constexpr Linear operation(const Linear& l, const Linear& r) {
        return Linear{l.a * r.a, l.b * r.a + r.b};
    }
};

#include <cassert>

int main() {
    SetFastIO();
    int n, q; std::cin >> n >> q;
    std::vector<Linear> init(n);
    for (int i{} ; i < n ; i++) {
        u64 a, b; std::cin >> a >> b;
        init[i] = Linear{ a, b };
    }
    SegmentTree<Monoid> seg(init);
    // seg.debug();
    for (int _{} ; _ < q ; _++) {
        int t; std::cin >> t;
        if (t == 0) {
            int p; std::cin >> p;
            u64 a, b; std::cin >> a >> b;
            seg.set(p, Linear{ a, b });
        }
        else if (t == 1) {
            u32 l, r; std::cin >> l >> r;
            u64 x; std::cin >> x;
            std::cout << seg.product(l, r).apply(x) << std::endl;
        }
        else {
            assert(false);
        }
    }
}
