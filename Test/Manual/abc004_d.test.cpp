#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/Graph/Flow/SuccessiveShortestPath.hpp"

#include <cassert>
#include <cmath>
#include <iostream>

/*
 * ABC004 - D マーブル
 * https://atcoder.jp/contests/abc004/submissions/49008975
 */

int solve() {
    using namespace zawa;
    int R, G, B; std::cin >> R >> G >> B;
    const int n{3000};
    SuccessiveShortestPath<int, int> mcf(n + 5);
    int r{n}, g{n + 1}, b{n + 2}, source{n + 3}, sink{n + 4};
    mcf.addEdge(source, r, R, 0);
    mcf.addEdge(source, g, G, 0);
    mcf.addEdge(source, b, B, 0);
    for (int i{} ; i < n ; i++) {
        mcf.addEdge(r, i, 1, std::abs(1400 - i));
        mcf.addEdge(g, i, 1, std::abs(1500 - i));
        mcf.addEdge(b, i, 1, std::abs(1600 - i));
        mcf.addEdge(i, sink, 1, 0);
    }
    assert(mcf.flow(source, sink, R + G + B));
    return mcf.minCost();
}

int main() {
#ifdef ATCODER
    std::cout << solve() << '\n';
#else
    std::cout << "Hello World" << '\n';
#endif
}
