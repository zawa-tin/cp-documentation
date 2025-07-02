#define PROBLEM "https://judge.yosupo.jp/problem/closest_pair"

#include "../../Src/GeometryZ2/Distance/ClosestPairOfPoints.hpp"
using namespace zawa;
using namespace geometryZ2;

#include <iostream>
#include <utility>

std::pair<int, int> solve() {
    int N;
    std::cin >> N;
    PointCloud P(N);
    for (auto& p : P) std::cin >> p; 
    return ClosestPairOfPoints<int>(P);
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int T;
    std::cin >> T;
    while (T--) {
        auto [i, j] = solve();
        std::cout << i << ' ' << j << '\n';
    }
}
