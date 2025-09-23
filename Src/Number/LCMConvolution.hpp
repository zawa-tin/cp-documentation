#pragma once

#include "../Template/TypeAlias.hpp"
#include "./PrimeSubsetTransform.hpp"

#include <algorithm>
#include <vector>

namespace zawa {

template <class T>
std::vector<T> LCMConvolution(std::vector<T> a, std::vector<T> b) {
    const usize n = std::max(a.size(), b.size());
    a.resize(n);
    b.resize(n);
    PrimeSubsetZetaTransform(a);
    PrimeSubsetZetaTransform(b);
    for (usize i = 0 ; i < n ; i++)
        a[i] *= b[i];
    PrimeSubsetMobiusTransform(a);
    return a;
}

} // namespace zawa
