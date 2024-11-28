#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E"

#include "../../Src/Number/ExtendGCD.hpp"

#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
    auto [x, y]{zawa::ExtendGCD(a, b)};
    std::cout << x << ' ' << y << '\n';
}
