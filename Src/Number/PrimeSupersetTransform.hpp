#pragma once

#include "../Template/TypeAlias.hpp"

#include <vector>

namespace zawa {

template <class T>
void PrimeSupersetZetaTransform(std::vector<T>& a) {
    std::vector<bool> p(a.size(), true);
    for (usize i = 2 ; i < a.size() ; i++)
        if (p[i]) {
            for (usize j = (a.size() - 1) / i * i ; j >= i ; j -= i) {
                p[j] = 0;
                a[j / i] += a[j];
            }
        }
}

template <class T>
void PrimeSupersetMobiusTransform(std::vector<T>& a) {
    std::vector<bool> p(a.size(), true);
    for (usize i = 2 ; i < a.size() ; i++)
        if (p[i]) {
            for (usize j = i ; j < a.size() ; j += i) {
                p[j] = 0;
                a[j / i] -= a[j];
            }
        }
}

} // namespace zawa
