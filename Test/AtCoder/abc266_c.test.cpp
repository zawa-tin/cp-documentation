#define PROBLEM "https://atcoder.jp/contests/abc266/tasks/abc266_c"

#include "../../Src/GeometryZ2/Polygon.hpp"

#include <iostream>

int main() {
    using namespace zawa::geometryZ2;
    Polygon p(4);
    std::cin >> p;
    std::cout << (p.isConvex() ? "Yes\n" : "No\n");
}
