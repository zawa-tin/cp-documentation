#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../../../Src/Graph/Tree/LowestCommonAncestor.hpp"

#include <vector>
#include <random>
#include <iostream>
bool check() {
    std::mt19937 mt{std::random_device{}()};
    int N{static_cast<int>(mt() % 1000 + 1)};
    std::vector<std::vector<int>> T(N);
    for (int i{1} ; i < N ; i++) {
        int p{static_cast<int>(mt() % i)};
        T[i].push_back(p);
        T[p].push_back(i);
    }
    zawa::LowestCommonAncestor lca{T, 0};
    for (int i{} ; i < N ; i++) {
        if (lca(i, i) != i) return false;
        if (lca.lca(i, i) != i) return false;
        if (lca.distance(i, i) != 0) return false;
    }
    return true;
}
int main() {
    int T{1000};
    while (T--) {
        assert(check());
    }
    std::cout << "Hello World\n";
}
