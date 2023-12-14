#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Graph/ShortestPath/BFS.hpp"

#include <cassert>
#include <iostream>

void solve() {
    using namespace zawa;
    SetFastIO();
    int n, m; std::cin >> n >> m;
    std::vector g(n, std::vector<u32>{});
    for (int i{} ; i < m ; i++) {
        u32 a, b; std::cin >> a >> b;
        a--; b--;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    auto tree{BFS(g).build(0)};
    for (int i{1} ; i < n ; i++) assert(tree.connect(i));
    std::cout << "Yes\n";
    for (int i{1} ; i < n ; i++) {
        std::cout << tree.parent(i) + 1 << '\n';
    }
}

int main() {
#ifdef ATCODER
    solve();
#else
    std::cout << "Hello World" << '\n';
#endif
}
