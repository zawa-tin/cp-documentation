#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_B"
#define ERROR 0.000001

#include "../../Src/GeometryZ2/Distance/FurthestPairOfPoints.hpp"
#include "../../Src/Utility/FloatingMarkerShift.hpp"
using namespace zawa;
using namespace geometryZ2;

#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int N;
    std::cin >> N;
    PointCloud P(N);
    for (auto& p : P) {
        std::string x, y;
        std::cin >> x >> y;
        p = {FloatingMarkerShift(x, 6), FloatingMarkerShift(y, 6)};
    }
    auto [i, j] = FurthestPairOfPoints<int>(P);
    std::cout << std::fixed << std::setprecision(8) << sqrtl(DistanceSquare(P[i], P[j])) / 1000000.0l << '\n';
}
