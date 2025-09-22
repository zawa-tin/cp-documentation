#pragma once

#include "../Template/TypeAlias.hpp"

#include <vector>

namespace zawa {

template <class T>
void SubsetZetaTransform(usize n, std::vector<T>& a) {
    for (usize i = 0 ; i < n ; i++)
        for (usize b = 0 ; b < a.size() ; b++)
            if (b & (usize{1} << i))
                a[b] += a[b ^ (usize{1} << i)];
}

template <class T>
void SubsetMobiusTransform(usize n, std::vector<T>& a) {
    for (usize i = 0 ; i < n ; i++)
        for (usize b = 0 ; b < a.size() ; b++)
            if (b & (usize{1} << i))
                a[b] -= a[b ^ (usize{1} << i)];
}

} // namespace zawa
