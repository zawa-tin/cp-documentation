#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
// #define PROBLEM "https://www.acmicpc.net/problem/23249"

/*
 * Seoul Nationalwide Internet Competition 2021 - L Triangles
 * https://www.acmicpc.net/source/93662824
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
    int n;
    std::cin >> n;
    std::vector<Point> A(n);
    for (auto& a : A) std::cin >> a;
    CountPointsInTriangles solver(A, A);
    int ans = 0;
    for (int i = 0 ; i < n ; i++) for (int j = i + 1 ; j < n ; j++) for (int k = j + 1 ; k < n ; k++) {
        ans += solver(i, j, k) > 0;
    }
    std::cout << ans << '\n';
#else
    std::cout << "Hello World\n";
#endif
}
