#pragma once

#include "./MonoidConcept.hpp"
#include "../Action/ActionConcept.hpp"
#include "../../Template/TypeAlias.hpp"

#include <algorithm>
#include <cassert>
#include <concepts>
#include <cmath>
#include <functional>
#include <optional>
#include <unordered_set>

namespace zawa {

namespace discretelog_internal {

using namespace concepts;

template <class X, class S>
concept Condition = Monoid<X> and Action<X, S>;

template <class F, class S>
concept Hasher = std::is_invocable_r_v<usize, F, S>;

template <class S>
concept STDHashable = requires (S s) {
    { std::hash<S>{}(s) } -> std::convertible_to<usize>;
};

} // namespace discretelog_internal

template <class X, class S, class H>
requires discretelog_internal::Condition<X, S> and discretelog_internal::Hasher<H, S>
std::optional<usize> MonoidDiscreteLogarithm(typename X::Element x, S s, S t, usize N) {
    assert(N);
    if (s == t)
        return 0;
    using XE = typename X::Element;
    using Hashset = std::unordered_set<S, H>;
    const usize m = std::max<usize>(1, sqrtl(N));
    Hashset T;
    T.reserve(m);
    const XE xm = [&]() {
        XE xi = X::identity();
        for (usize i = 0 ; i < m ; i++)
            T.insert(X::action(xi = X::operation(xi, x), t));
        return xi;
    }();
    XE prv = X::identity();
    for (usize k = 1, fail = 0 ; (k - 1) * m <= N and fail < 2 ; k++) {
        XE cur = X::operation(prv, xm);
        const S val = X::action(cur, s);
        if (T.contains(val)) {
            for (auto [i, xi] = std::pair<usize, XE>(0, prv) ; i < m ; i++, xi = X::operation(xi, x)) {
                if (X::action(xi, s) == t) {
                    const usize res = (k - 1) * m + i;
                    return res < N ? std::optional<usize>{res} : std::nullopt;
                }
            } 
            fail++;
        }
        prv = std::move(cur);
    }
    return std::nullopt;
}

template <class X, class S>
requires discretelog_internal::Condition<X, S> and discretelog_internal::STDHashable<S>
std::optional<usize> MonoidDiscreteLogarithm(typename X::Element x, S s, S t, usize N) {
    return MonoidDiscreteLogarithm<X, S, std::hash<S>>(x, s, t, N); 
}

} // namespace zawa
