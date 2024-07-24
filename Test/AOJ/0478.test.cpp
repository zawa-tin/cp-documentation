#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/0478"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Algebra/Monoid/RollingHashMonoid.hpp"
#include "../../Src/DataStructure/SegmentTree/SegmentTree.hpp"
#include "../../Src/Graph/Tree/HeavyLightDecomposition.hpp"

#include <cassert>
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace zawa;

RollingHashMonoidData::Value RollingHashMonoidData::base{
    RollingHashMonoidData::randomValue(26)
};

int main() {
    SetFastIO();
    int N;
    std::cin >> N;
    std::vector<char> K(N);
    for (auto& k : K) std::cin >> k;
    Tree T(N);
    for (int i{} ; i < N - 1 ; i++) {
        int u, v;
        std::cin >> u >> v;
        AddEdge(T, u - 1, v - 1);
    }
    HeavyLightDecomposition hld{T};
    std::vector<RollingHashMonoidData> init(N), tini(N);
    for (int i{} ; i < N ; i++) {
        init[hld[i]] = tini[N - hld[i] - 1] = RollingHashMonoidData{K[i]};
    }
    SegmentTree<RollingHashMonoid> seg{init}, ges{tini};
    int Q;
    std::cin >> Q;
    std::unordered_set<RollingHashMonoidData::Value> set;
    while (Q--) {
        int t;
        std::cin >> t;
        if (t == 1) {
            int s, t;
            std::cin >> s >> t;
            s--; t--;
            RollingHashMonoidData res{};
            for (auto [u, v] : hld(s, t)) {
                u = hld[u];
                v = hld[v];
                if (u <= v) res = RollingHashMonoid::operation(res, seg.product(u, v + 1));
                else res = RollingHashMonoid::operation(res, ges.product(N - u - 1, N - v));
            }
            set.insert(res.hash);
            std::cout << set.size() << '\n';
        }
        else if (t == 2) {
            int k;
            char c;
            std::cin >> k >> c;
            k--;
            seg.set(hld[k], RollingHashMonoidData{c});
            ges.set(N - hld[k] - 1, RollingHashMonoidData{c});
        }
        else {
            assert(false);
        }
    }
}
