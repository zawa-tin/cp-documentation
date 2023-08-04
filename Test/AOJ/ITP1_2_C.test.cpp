#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/2/ITP1_2_C"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Template/ArrayIO.hpp"

#include <iostream>
#include <array>
#include <utility>

using namespace zawa;

int main() {
    std::array<u32, 3> a; std::cin >> a;
    if (a[1] > a[2]) std::swap(a[1], a[2]);
    if (a[0] > a[1]) std::swap(a[0], a[1]);
    if (a[1] > a[2]) std::swap(a[1], a[2]);
    std::cout << a << std::endl;
}
