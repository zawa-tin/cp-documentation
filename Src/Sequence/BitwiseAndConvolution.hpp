#pragma once

#include "SupersetTransform.hpp"

#include <algorithm>
#include <bit>
#include <cassert>
#include <utility>
#include <vector>

namespace zawa {

template <class T>
std::vector<T> BitwiseAndConvolution(std::vector<T> a, std::vector<T> b) {
    assert(a.size() and b.size());
    const usize n = std::bit_width(std::max(a.size(), b.size()) - 1);
    a.resize(1 << n);
    b.resize(1 << n);
    SupersetZetaTransform(n, a);
    SupersetZetaTransform(n, b);
    for (usize i = 0 ; i < (usize{1} << n) ; i++)
        a[i] *= b[i];
    SupersetMobiusTransform(n, a);
    return a;
}

} // namespace zawa
