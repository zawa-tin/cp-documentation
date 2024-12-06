#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Graph/Tree/HeavyLightDecomposition.hpp"

#include <iostream>

using namespace zawa;

int main() {
    SetFastIO();
    int N, Q;
    std::cin >> N >> Q;
    std::vector<std::vector<int>> T(N);
    for (int i{} ; i < N - 1 ; i++) {
        int a, b;
        std::cin >> a >> b;
        T[a].push_back(b);
        T[b].push_back(a);
    }
    HeavyLightDecomposition hld(T);
    while (Q--) {
        int s, t, i;
        std::cin >> s >> t >> i;
        auto ans{hld.jump(s, t, i)};
        std::cout << (hld.Invalid() == ans ? -1 : (int)ans) << '\n';
    }
}
