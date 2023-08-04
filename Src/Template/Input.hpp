#pragma once

#include "./ArrayIO.hpp"
#include "./VectorIO.hpp"
#include "./PairIO.hpp"

#include <iostream>

namespace zawa {

template <class T>
void In(T& value) {
    std::cin >> value;
}

template <class Head, class... Tail>
void In(Head& head, Tail&... tail) {
    In(head);
    In(tail...);
}

} // namespace zawa
