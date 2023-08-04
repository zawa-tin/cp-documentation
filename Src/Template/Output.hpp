#pragma once

#include "./ArrayIO.hpp"
#include "./VectorIO.hpp"
#include "./PairIO.hpp"

#include <iostream>

namespace zawa {

void Cout() {
    std::cout << std::endl;
}

template <class T>
void Cout(const T& value) {
    std::cout << value;
}

template <class Head, class... Tail>
void Cout(const Head& head, const Tail&... tail) {
    std::cout << head;
    if (sizeof...(tail)) {
        std::cout << ' ';
        Cout(tail...);
    }
}

void Eout() {
    std::cerr << std::endl;
}

template <class T>
void Eout(const T& value) {
    std::cerr << value;
}

template <class Head, class... Tail>
void Eout(const Head& head, const Tail&... tail) {
    std::cerr << head;
    if (sizeof...(tail)) {
        std::cerr << ' ';
        Eout(tail...);
    }
}

} // namespace zawa
