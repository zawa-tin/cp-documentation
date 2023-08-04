#pragma once

#include "./TypeAlias.hpp"

#include <iostream>
#include <utility>

namespace zawa {

template <class T1, class T2>
std::istream &operator>>(std::istream& is, std::pair<T1, T2>& P) {
    is >> P.first >> P.second;
    return is;
}

template <class T1, class T2>
std::ostream &operator<<(std::ostream& os, const std::pair<T1, T2>& P) {
    os << '(' << P.first << ',' << P.second << ')';
    return os;
}

} // namespace zawa
