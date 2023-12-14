#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Graph/ShortestPath/BFS.hpp"

#include <iostream>
#include <string>
#include <utility>
#include <vector>

/*
 * ABC271-D Flip and Adjust
 * https://atcoder.jp/contests/abc271/submissions/48487470
 */

void solve() {
    using namespace zawa; 
    SetFastIO();
    int n, s; std::cin >> n >> s;
    
    auto f{[&](int card, int sum) -> int {
        return card * (s + 1) + sum;
    }};

    BFS bfs((n + 1) * (s + 1));
    for (int i{} ; i < n ; i++) {
        int a, b; std::cin >> a >> b;
        for (int j{} ; j + a <= s ; j++) {
            bfs.addDirectedEdge(f(i, j), f(i + 1, j + a), 0);
        }
        for (int j{} ; j + b <= s ; j++) {
            bfs.addDirectedEdge(f(i, j), f(i + 1, j + b), 1);
        }
    }

    auto tree{bfs.build(f(0, 0))};
    if (tree.connect(f(n, s))) {
        std::cout << "Yes\n";
        for (const auto& e : tree.pathE(f(n, s))) {
            std::cout << (e.id ? 'T' : 'H');
        }
        std::cout << '\n';
    }
    else {
        std::cout << "No" << '\n';
    }
}

int main() {
#ifdef ATCODER
    solve();
#else
    std::cout << "Hello World" << '\n';
#endif
}
