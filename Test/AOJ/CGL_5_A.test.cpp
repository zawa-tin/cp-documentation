#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/5/CGL_5_A"

#include "../../Src/GeometryZ2/Distance/ClosestPairOfPoints.hpp"
#include "../../Src/GeometryZ2/Distance/PointAndPoint.hpp"
#include "../../Src/Utility/FloatingMarkerShift.hpp"
using namespace zawa;
using namespace zawa::geometryZ2;

#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int N;
    std::cin >> N;
    std::vector<Point> P(N);
    for (auto& p : P) {
        std::string x, y;
        std::cin >> x >> y;
        p = {FloatingMarkerShift(x, 6), FloatingMarkerShift(y, 6)};
    }
    auto [i, j] = ClosestPairOfPoints(P);
    std::cout << std::fixed << std::setprecision(8) << sqrtl(DistanceSquare(P[i], P[j])) / 1000000 << '\n';
}
