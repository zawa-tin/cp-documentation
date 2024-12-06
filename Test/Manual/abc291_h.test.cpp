#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * AtCoder Beginner Contest 291 - Ex Balanced Tree
 * https://atcoder.jp/contests/abc291/submissions/60474986
 */

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Graph/Tree/Centroid.hpp"

#include <iostream>
#include <utility>

using namespace zawa;

int main() {
    SetFastIO();

#ifdef ATCODER
    int N;
    std::cin >> N;
    std::vector<std::vector<int>> g(N);
    for (int _{} ; _ < N - 1 ; _++) {
        int A, B;
        std::cin >> A >> B;
        A--; B--;
        g[A].push_back(B);
        g[B].push_back(A);
    }
    Centroid C(std::move(g));
    std::vector<int> ans(N, -1);
    auto dfs{[&](auto dfs, int v) -> int {
        v = (int)C.rooting(v);
        C.remove(v);
        for (auto x : C.adjlist(v)) {
            ans[dfs(dfs, x)] = v + 1;
        }
        return v;
    }};
    dfs(dfs, 0);
    for (int v{} ; v < N ; v++) {
        std::cout << ans[v] << (v + 1 == N ? '\n' : ' ');
    }
#else
    std::cout << "Hello World" << '\n';
#endif
}
