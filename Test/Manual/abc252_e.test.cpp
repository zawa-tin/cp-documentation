#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Graph/ShortestPath/Dijkstra.hpp"

/*
 * ABC252-E Road Reduction
 * https://atcoder.jp/contests/abc252/submissions/48494342
 */

void solve() {
    using namespace zawa;
    SetFastIO();
    int n, m; std::cin >> n >> m;
    Dijkstra<u64> solver(n);
    for (int i{} ; i < m ; i++) {
        int a, b, c; std::cin >> a >> b >> c;
        solver.addUndirectedEdge(a - 1, b - 1, (u64)c, (u32)i);
    }
    auto tree{solver.build(0)};
    for (int i{1} ; i < n ; i++) {
        std::cout << tree.id(i) + 1 << (i + 1 == n ? '\n' : ' ');
    }
}

int main() {
#ifdef ATCODER
    solve();
#else
    std::cout << "Hello World" << '\n';
#endif
}
