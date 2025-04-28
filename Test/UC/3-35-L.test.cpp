#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * The 3rd Universal Cup. Stage 35: Krakow - L Empty Triangles
 */

#include "../../Src/GeometryZ2/Contain/CountPointsInTriangles.hpp"

#include <iostream>
#include <vector>
using namespace zawa;
using namespace geometryZ2;

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
#ifdef ONLINE_JUDGE
    int Z;
    std::cin >> Z;
    while (Z--) {
        int n, q;
        std::cin >> n >> q;
        std::vector<Point> A(n);
        for (auto& a : A) std::cin >> a;
        CountPointsInTriangles solver(A, A);
        while (q--) {
            int i, j, k;
            std::cin >> i >> j >> k;
            std::cout << (solver(i - 1, j - 1, k - 1) == 0 ? "YES\n" : "NO\n");
        }
    }
#else
    std::cout << "Hello World\n";
#endif
}
