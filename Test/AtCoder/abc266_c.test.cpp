// #define PROBLEM "https://atcoder.jp/contests/abc266/tasks/abc266_c"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/GeometryZ2/Polygon.hpp"

#include <iostream>

int main() {
#ifdef ATCODER
    using namespace zawa::geometryZ2;
    Polygon p(4);
    std::cin >> p;
    std::cout << (p.isConvex() ? "Yes\n" : "No\n");
#else
    std::cout << "Hello World\n";
#endif
}
