#pragma once

#include "./TypeAlias.hpp"

#include <iostream>
#include <vector>

namespace zawa {

template <class T>
std::istream &operator>>(std::istream& is, std::vector<T>& A) {
    for (T& a : A) {
        is >> a;
    }
    return is;
}

template <class T>
std::ostream &operator<<(std::ostream& os, const std::vector<T>& A) {
    for (u32 i{} ; i < A.size() ; i++) {
        os << A[i] << (i + 1 == A.size() ? "" : " ");
    }
    return os;
}

} // namespace zawa
