#define PROBLEM "https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification"

#include "../../Src/Graph/Tree/SubtreesHash.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

using namespace zawa;

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int N;
    std::cin >> N;
    std::vector<std::vector<int>> g(N);
    for (int i = 1 ; i < N ; i++) {
        int p;
        std::cin >> p;
        g[p].push_back(i);
    }
    auto ans = SubtreesHasher{}(g);
    auto K = *std::max_element(ans.begin(), ans.end()) + 1;
    std::cout << K << '\n';
    for (int i = 0 ; i < N ; i++) std::cout << ans[i] << (i + 1 == N ? '\n' : ' ');
}
