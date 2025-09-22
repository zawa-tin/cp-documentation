#pragma once

#include "../Template/TypeAlias.hpp"

#include <vector>

namespace zawa {

template <class T>
void SupersetZetaTransform(usize n, std::vector<T>& a) {
    for (usize i = 0 ; i < n ; i++)
        for (usize b = ssize(a) ; b-- ; )
            if (b & (usize{1} << i))
                a[b ^ (usize{1} << i)] += a[b];
}

template <class T>
void SupersetMobiusTransform(usize n, std::vector<T>& a) {
    for (usize i = 0 ; i < n ; i++)
        for (usize b = ssize(a) ; b-- ; )
            if (b & (usize{1} << i))
                a[b ^ (usize{1} << i)] -= a[b];
}

} // namespace zawa
