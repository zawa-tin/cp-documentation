#pragma once

#include <algorithm>
#include <concepts>
#include <utility>
#include <optional>

namespace zawa {

template <std::totally_ordered T, T INF>
struct ClampAdd {

    static_assert(INF >= T{0}, "ClampAdd<T, INF>'s INF must be non negative");

    T low = -INF, high = INF, plus = 0;

    ClampAdd() = default; 

    ClampAdd(T l, T h, T p) : low{l}, high{h}, plus{p} {}

    static ClampAdd<T, INF> chmin(T x) {
        return {-INF, x, T{0}};
    }

    static ClampAdd<T, INF> chmax(T x) {
        return {x, INF, T{0}};
    }

    static ClampAdd<T, INF> add(T x) {
        return {-INF, INF, x};
    }

    T operator()(T x) const {
        return std::clamp(x, low, high) + plus;
    }
};

// ref: https://rsm9.hatenablog.com/entry/2021/02/01/220408
template <std::totally_ordered T, T INF>
struct ClampAddMonoid {

    using Element = ClampAdd<T, INF>;

    static Element identity() {
        return Element{};
    }

    static Element operation(const Element& L, const Element& R) {
        T low   = std::max(std::min(L.low + L.plus, R.high),  R.low) - L.plus;
        T high  = std::min(std::max(L.high + L.plus, R.low), R.high) - L.plus;
        T plus  = L.plus + R.plus;
        return Element{low, high, plus};
    }

};

} // namespace zawa
