#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/3/DPL_3_C"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Sequence/CartesianTree.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

using namespace zawa;

int main() {
    SetFastIO();
    int N;
    std::cin >> N;
    std::vector<int> H(N);
    for (auto& h : H) std::cin >> h;
    using Tree = CartesianTree<int>;
    Tree T{H, [](int l, int r) { return l < r; }};
    long long ans{};
    std::vector<int> size(N);
    T.treeDP([&](const Tree::Node& node) {
            auto v{node.idx};
            size[v] = 1;
            if (node.left != Tree::Invalid) size[v] += size[node.left];
            if (node.right != Tree::Invalid) size[v] += size[node.right];
            ans = std::max(ans, (long long)size[v] * node.value);
        });
    std::cout << ans << '\n';
}
