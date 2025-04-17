#pragma once

#include "../../Template/TypeAlias.hpp"
#include "../../Algebra/Group/GroupConcept.hpp"

#include <bit>
#include <cassert>
#include <concepts>
#include <iterator>
#include <optional>
#include <vector>

namespace zawa {

namespace concepts {

template <class F, class V>
concept Predicate = requires {
    { std::declval<F>()(std::declval<V>()) } -> std::same_as<bool>; 
};

} // namespace Concept

template <concepts::Group G>
class DualFenwickTree {
public:

    using V = typename G::Element;

    constexpr static u32 Log2(usize n) noexcept {
        return static_cast<u32>(
                    std::bit_width(n) - (std::has_single_bit(n) ? 1 : 0)
                );
    }

    DualFenwickTree() = default;

    DualFenwickTree(usize n) : n_{n}, lg_{Log2(n)}, dat_(n+1, G::identity()) {
        assert(n);
    }

    DualFenwickTree(const std::vector<V>& d) : n_{d.size()}, lg_{Log2(n_)}, dat_(d.size() + 1, G::identity()) {
        assert(d.size());
        add(0, d[0]);
        for (usize i = 1 ; i < d.size() ; i++) add(i, G::operation(G::inverse(d[i - 1]), d[i]));
    }

    template <std::input_iterator It>
    DualFenwickTree(It first, It last) 
    : n_{static_cast<usize>(std::distance(first, last))}, lg_{Log2(n_)}, dat_(n_ + 1, G::identity()) {
        assert(first != last);
        V pv = static_cast<V>(*first);
        add(0, pv);
        for (usize i = 1 ; i < n_ ; i++) {
            first++;
            V v = static_cast<V>(*first);
            add(i, G::operation(G::inverse(pv), v));
            pv = v;
        } 
    }

    inline usize size() const noexcept {
        return n_;
    }

    void operation(usize l, usize r, const V& v) {
        assert(l <= r and r <= size());
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

    template <class F>
    std::optional<usize> maxRight(usize l, F f) const requires concepts::Predicate<F, V> {
        assert(l < size());
        V sum = l ? (*this)[l - 1] : G::identity();
        usize r = 0;
        for (u32 w = lg_ ; w <= lg_ ; w--) {
            usize next = r | (1u << w);
            if (next >= dat_.size()) continue;
            V nsum = G::operation(sum, dat_[next]);
            if (f(nsum)) {
                sum = std::move(nsum);
                r = std::move(next);
            }
        }
        assert(l <= r);
        return r == size() and f(sum) ? std::nullopt : std::optional{r};
    }

    // 実装が合いません。頭が悪いので
    // template <class F>
    // requires Concept::Predicate<F, V>
    // std::optional<usize> minLeft(usize r, F f) const {
    //     assert(r <= n_);
    //     V sum = G::identity();
    //     usize l = 0;
    //     for (u32 w = lg_ ; w <= lg_ ; w--) {
    //         u32 next = l | (1u << w);
    //         if (next >= r) continue;
    //         V nsum = G::operation(dat_[next], sum);
    //         if (!f(nsum)) {
    //             sum = std::move(nsum);
    //             l = std::move(next);
    //         }
    //     }
    //     assert(l <= r);
    //     if (l + 1 == r and !f(sum)) return r;
    //     return l == 0u and f(sum) ? std::nullopt : std::optional{l};
    // }

private:

    usize n_;

    u32 lg_;

    std::vector<V> dat_;

    constexpr i32 lsb(i32 x) const noexcept {
        return x & -x;
    }

    void add(i32 i, const V& v) {
        for (i++ ; i <= (i32)size() ; i += lsb(i)) dat_[i] = G::operation(dat_[i], v);
    }
};

} // namespace zawa
