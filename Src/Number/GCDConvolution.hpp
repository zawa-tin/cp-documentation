#pragma once

#include "../Template/TypeAlias.hpp"
#include "./PrimeSupersetTransform.hpp"

#include <algorithm>
#include <vector>

namespace zawa {

template <class T>
std::vector<T> GCDConvolution(std::vector<T> a, std::vector<T> b) {
    const usize n = std::max(a.size(), b.size());
    a.resize(n);
    b.resize(n);
    PrimeSupersetZetaTransform(a);
    PrimeSupersetZetaTransform(b);
    for (usize i = 0 ; i < n ; i++)
        a[i] *= b[i];
    PrimeSupersetMobiusTransform(a);
    return a;
}

} // namespace zawa
