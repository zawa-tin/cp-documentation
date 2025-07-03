#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_4_C"
#define ERROR 0.00001

#include "../../Src/GeometryR2/ConvexPolygonCut.hpp"
using namespace zawa::geometryR2;

#include <iostream>
#include <iomanip>

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int N;
    std::cin >> N;
    Polygon P(N);
    for (int i = 0 ; i < N ; i++) std::cin >> P[i];
    int Q;
    std::cin >> Q;
    std::cout << std::fixed << std::setprecision(7);
    const Real area = P.area();
    while (Q--) {
        Line l;
        std::cin >> l.p0() >> l.p1();
        const auto [left, right] = ConvexPolygonCut(P, l);
        assert(Equal(left.area() + right.area(), area));
        std::cout << left.area() << '\n';
    }
}
