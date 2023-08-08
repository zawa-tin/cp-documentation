#pragma once

#include "./ArrayIO.hpp"
#include "./VectorIO.hpp"
#include "./PairIO.hpp"

#include <iostream>

namespace zawa {

template <class T>
void input(T& value) {
    std::cin >> value;
}

template <class Head, class... Tail>
void input(Head& head, Tail&... tail) {
    input(head);
    input(tail...);
}

} // namespace zawa
