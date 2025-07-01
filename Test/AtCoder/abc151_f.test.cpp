// #define PROBLEM "https://atcoder.jp/contests/abc151/tasks/abc151_f"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * AtCoder Beginner Contest 151 F - Enclose All
 * https://atcoder.jp/contests/abc151/submissions/67218823
 */

#include "../../Src/GeometryR2/Contain/SmallestEnclosingDisc.hpp"
using namespace zawa;
using namespace geometryR2;

#include <iostream>
#include <iomanip>

int main() {
#ifdef ATCODER
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int N;
    std::cin >> N;
    PointCloud P(N);
    for (auto& p : P) std::cin >> p;
    auto ans = SmallestEnclosingDisc(P, 42);
    std::cout << std::fixed << std::setprecision(8) << ans.radius() << '\n';
#else
    std::cout << "Hello World\n";
#endif
}
