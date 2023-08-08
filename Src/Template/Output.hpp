#pragma once

#include "./ArrayIO.hpp"
#include "./VectorIO.hpp"
#include "./PairIO.hpp"

#include <iostream>

namespace zawa {

void out() {
    std::cout << std::endl;
}

template <class T>
void out(const T& value) {
    std::cout << value << std::endl;
}

template <class Head, class... Tail>
void out(const Head& head, const Tail&... tail) {
    std::cout << head;
    if (sizeof...(tail)) {
        std::cout << ' ';
    }
    out(tail...);
}

void eout() {
    std::cerr << std::endl;
}

template <class T>
void eout(const T& value) {
    std::cerr << value << std::endl;
}

template <class Head, class... Tail>
void eout(const Head& head, const Tail&... tail) {
    std::cerr << head;
    if (sizeof...(tail)) {
        std::cerr << ' ';
    }
    eout(tail...);
}

} // namespace zawa
