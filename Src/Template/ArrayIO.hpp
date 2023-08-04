#pragma once

#include "./TypeAlias.hpp"

#include <iostream>
#include <array>

namespace zawa {

template <class T, usize N>
std::istream &operator>>(std::istream& is, std::array<T, N>& A) {
    for (T& a : A) {
        is >> a;
    }
    return is;
}

template <class T, usize N>
std::ostream &operator<<(std::ostream& os, const std::array<T, N>& A) {
    for (u32 i{} ; i < A.size() ; i++) {
        os << A[i] << (i + 1 == A.size() ? "" : " ");
    }
    return os;
}

} // namespace zawa
