#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_H"
#define ERROR 0.00001

#include "../../Src/GeometryR2/CommonArea/CircleAndPolygon.hpp"
using namespace zawa::geometryR2;

#include <iostream>
#include <iomanip>

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int N;
    Real R;
    std::cin >> N >> R;
    Circle C{Point{0, 0}, R};
    Polygon P(N);
    for (int i = 0 ; i < N ; i++) std::cin >> P[i];
    std::cout << std::fixed << std::setprecision(8) << CommonArea(C, P) << '\n';
}
