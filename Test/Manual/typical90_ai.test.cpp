#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * 競プロ典型 90問 035- Preserve Connectivity
 * https://atcoder.jp/contests/typical90/submissions/55137635
 */

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Graph/Tree/AuxiliaryTree.hpp"

#include <iostream>
#include <vector>

using namespace zawa;

int main() {
#ifdef ATCODER
    SetFastIO(); 

    int N;
    std::cin >> N;
    Tree g(N);
    for (int i{1} ; i < N ; i++) {
        int A, B;
        std::cin >> A >> B;
        AddEdge(g, A - 1, B - 1);
    }
    AuxiliaryTree AT(g);
    int Q;
    std::cin >> Q;
    while (Q--) {
        int K;
        std::cin >> K;
        std::vector<AuxiliaryTree::V> V(K);
        for (auto& v : V) {
            std::cin >> v;
            v--;
        }
        u32 r{AT.construct(V)};
        auto dfs{[&](auto dfs, int v, int p) -> u32 {
            u32 res{};
            if (p != -1) {
                res += AT.parentEdgeLength(v);
            }
            for (auto x : AT[v]) {
                if ((int)x != p) {
                    res += dfs(dfs, x, v);
                }
            }
            return res;
        }};
        std::cout << dfs(dfs, r, -1) << '\n';
    }
#else
    std::cout << "Hello World" << '\n';
#endif
}
