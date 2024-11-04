#pragma once

#include "../Template/TypeAlias.hpp"
#include "../Algebra/Monoid/AdditionMonoid.hpp"
#include "../Algebra/Monoid/MinCountMonoid.hpp"
#include "../DataStructure/SegmentTree/LazySegmentTree.hpp"

#include <algorithm>
#include <cassert>
#include <type_traits>
#include <utility>

namespace zawa {

template <class T>
class Rectangle {
public:

    Rectangle() = default;
     
    Rectangle(T l, T d, T r, T u)
        : l_{l}, d_{d}, r_{r}, u_{u} {
        assert(l <= r);
        assert(d <= u);
    }

    Rectangle(const std::pair<T, T>& ld, const std::pair<T, T>& ru)
        : l_{ld.first}, d_{ld.second}, r_{ru.first}, u_{ru.second} {}

    Rectangle(const std::pair<T, T>& ld, T w, T h)
        : l_{ld.first}, d_{ld.second}, r_{l_ + w}, u_{d_ + h} {}

    inline T left() const noexcept {
        return l_;
    }

    inline T right() const noexcept {
        return r_;
    }

    inline T down() const noexcept {
        return d_;
    }

    inline T up() const noexcept {
        return u_;
    }

private:
    // 左下、右上
    T l_{}, d_{}, r_{}, u_{};
};

namespace internal {

struct AreaOfUnionOfRectanglesStructure {
    using ValueMonoid = MinCountMonoid<i32, u64>;
    using OperatorMonoid = AdditionMonoid<i32>;
    static ValueMonoid::Element mapping(const ValueMonoid::Element& V, const OperatorMonoid::Element& R) {
        return ValueMonoid::Element{ V.first + R, V.second };
    }
    static ValueMonoid::Element generate(u64 v) {
        return ValueMonoid::Element{ 0, v };
    }
};

} // namespace internal

template <class T, class InputIterator>
u64 AreaOfUnionOfRectangles(InputIterator first, InputIterator last) {
    static_assert(std::is_same_v<std::remove_reference_t<decltype(*first)>, Rectangle<T>>, "*iterator 's type must be T");
    usize n{static_cast<usize>(std::distance(first, last))};
    if (n == 0u) return u64{};
    std::vector<T> xs, ys;
    xs.reserve(2u * n);
    ys.reserve(2u * n);
    for (auto it{first} ; it != last ; it++) {
       xs.push_back(it->left()); 
       xs.push_back(it->right());
       ys.push_back(it->down()); 
       ys.push_back(it->up());
    }
    std::sort(ys.begin(), ys.end());
    ys.erase(std::unique(ys.begin(), ys.end()), ys.end());
    std::sort(xs.begin(), xs.end());
    xs.erase(std::unique(xs.begin(), xs.end()), xs.end());
    std::vector<std::vector<std::pair<std::pair<u32, u32>, bool>>> event(xs.size());
    for (auto it{first} ; it != last ; it++) {
        u32 l{static_cast<u32>(std::distance(ys.begin(), std::lower_bound(ys.begin(), ys.end(), it->down())))};
        u32 r{static_cast<u32>(std::distance(ys.begin(), std::lower_bound(ys.begin(), ys.end(), it->up())))};
        event[static_cast<u32>(std::distance(xs.begin(), std::lower_bound(xs.begin(), xs.end(), it->left())))]
            .emplace_back(std::pair<u32, u32>{ l, r }, true);
        event[static_cast<u32>(std::distance(xs.begin(), std::lower_bound(xs.begin(), xs.end(), it->right())))]
            .emplace_back(std::pair<u32, u32>{ l, r }, false);
    } 
    using S = internal::AreaOfUnionOfRectanglesStructure;
    std::vector<S::ValueMonoid::Element> init(ys.size() - 1);
    for (usize i{} ; i + 1 < ys.size() ; i++) {
        init[i] = S::generate(static_cast<u64>(ys[i + 1] - ys[i]));
    } 
    u64 all{static_cast<u64>(ys.back() - ys.front())};
    LazySegmentTree<S> seg{init};
    u64 res{};
    for (u32 x{} ; x < xs.size() ; x++) {
        if (x >= 1u) {
            auto [min, count]{seg.product(0, init.size())};
            res += (all - (min == 0 ? count : u64{})) * (xs[x] - xs[x - 1]);
        }
        for (const auto& [lr, v] : event[x]) {
            seg.operation(lr.first, lr.second, (v ? +1 : -1));
        }
    }
    return res;
}

} // namespace zawa
