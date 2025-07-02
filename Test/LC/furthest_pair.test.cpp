#define PROBLEM "https://judge.yosupo.jp/problem/furthest_pair"

#include "../../Src/GeometryZ2/Distance/FurthestPairOfPoints.hpp"
using namespace zawa::geometryZ2;

#include <iostream>
int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int T;
    std::cin >> T;
    while (T--) {
        int N;
        std::cin >> N;
        PointCloud P(N);
        for (auto& p : P) std::cin >> p;
        auto [i, j] = FurthestPairOfPoints<int>(P);
        std::cout << i << ' ' << j << '\n';
    }
}
