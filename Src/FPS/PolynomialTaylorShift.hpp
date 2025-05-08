#pragma once

#include <algorithm>
#include <cassert>
#include <vector>
#include <concepts>

#include "../Template/TypeAlias.hpp"

namespace zawa {

template <class T, std::integral C, class F>
std::vector<T> PolynomialTaylorShift(std::vector<T> a, C c, F convolution) {
    assert(a.size());
    std::vector<T> invfact(a.size());
    T f{1};
    for (usize i = 1 ; i < a.size() ; i++) {
        f *= i;
        a[i] *= f;
    }
    invfact.back() = T{1} / f;
    for (usize i = a.size() - 1 ; i >= 1 ; i--) invfact[i - 1] = invfact[i] * T{i};
    std::vector<T> right(a.size());
    T powc = 1;
    for (usize i = 0 ; i < a.size() ; i++) {
        right[i] = invfact[i] * powc;
        powc *= T{c};
    }
    std::ranges::reverse(a);
    const usize n = a.size();
    std::vector<T> b = convolution(std::move(a), std::move(right));
    b.resize(n);
    std::ranges::reverse(b);
    for (usize i = 0 ; i < b.size() ; i++) b[i] *= invfact[i];
    return b;
}

} // namespace zawa
