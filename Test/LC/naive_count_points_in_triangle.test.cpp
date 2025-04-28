#define PROBLEM "https://judge.yosupo.jp/problem/count_points_in_triangle"

#include "../../Src/GeometryZ2/Contain/NaiveCountPointsInTriangles.hpp"

#include <iostream>
using namespace zawa;
using namespace geometryZ2;

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int N;
    std::cin >> N;
    PointCloud A(N);
    for (auto& a : A) std::cin >> a;
    int M;
    std::cin >> M;
    PointCloud B(M);
    for (auto& a : B) std::cin >> a;
    NaiveCountPointsInTriangles sv(A, B);
    int Q;
    std::cin >> Q;
    while (Q--) {
        int a, b, c;
        std::cin >> a >> b >> c;
        std::cout << sv(a, b, c) << '\n';
    }
}
