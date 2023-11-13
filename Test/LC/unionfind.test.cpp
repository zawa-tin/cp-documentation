#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp"

#include <iostream>

int main() {
    using namespace zawa;
    SetFastIO();
    u32 n, q; std::cin >> n >> q;
    DisjointSetUnion dsu(n);
    for (u32 _{} ; _ < q ; _++) {
        u32 t, u, v; std::cin >> t >> u >> v;
        if (t == 0) {
            dsu.merge(u, v);
        }
        else {
            std::cout << dsu.same(u, v) << '\n';
        }
    }
}
