#pragma once

#include "../../Template/TypeAlias.hpp"
#include "../../Algebra/Group/GroupConcept.hpp"

#include <cassert>
#include <vector>

namespace zawa {

template <Concept::Group G>
class DualFenwickTree {
public:

    using V = typename G::Element;

    DualFenwickTree() = default;

    DualFenwickTree(usize n) : n_{n}, dat_(n+1, G::identity()) {
        assert(n);
    }

    DualFenwickTree(const std::vector<V>& d) : n_{d.size()}, dat_(d.size() + 1, G::identity()) {
        assert(d.size());
        add(0, d[0]);
        for (usize i = 1 ; i < d.size() ; i++) add(i, G::operation(G::inverse(d[i - 1]), d[i]));
    }

    inline usize size() const noexcept {
        return n_;
    }

    void operation(usize l, usize r, const V& v) {
        assert(l <= r and r <= (i32)size());
        if (l < r) {
            add(l, v);
            if (r < size()) add(r, G::inverse(v));
        }
    }

    void operation(usize i, const V& v) {
        assert(i < size());
        operation(i, i + 1, v);
    }

    V operator[](i32 i) const {
        assert(0 <= i and i < (i32)size());
        V res = G::identity();
        for (i++ ; i ; i -= lsb(i)) res = G::operation(dat_[i], res);
        return res;
    }

    void set(usize i, V v) {
        assert(0 <= i and i < size());
        v = G::operation(G::inverse((*this)[i]), v);
        operation(i, v);
    }

private:

    usize n_;

    std::vector<V> dat_;

    constexpr i32 lsb(i32 x) const noexcept {
        return x & -x;
    }

    void add(i32 i, const V& v) {
        for (i++ ; i <= (i32)size() ; i += lsb(i)) dat_[i] = G::operation(dat_[i], v);
    }
};

} // namespace zawa
