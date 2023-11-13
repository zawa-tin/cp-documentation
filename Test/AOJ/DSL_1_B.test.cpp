#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Algebra/Group/AdditiveGroup.hpp"
#include "../../Src/DataStructure/DisjointSetUnion/PotentializedDisjointSetUnion.hpp"

#include <cassert>
#include <iostream>

int main() {
    using namespace zawa;
    SetFastIO();
    u32 n, q; std::cin >> n >> q;
    PotentializedDisjointSetUnion<AdditiveGroup<i32>> dsu(n);
    for (u32 _{} ; _ < q ; _++) {
        u32 t; std::cin >> t;
        if (t == 0) {
            u32 x, y; std::cin >> x >> y;
            i32 z; std::cin >> z;
            assert(dsu.merge(x, y, z));
        }
        else if (t == 1) {
            u32 x, y; std::cin >> x >> y;
            if (dsu.isDefined(x, y)) {
                std::cout << dsu.distance(x, y) << '\n';
            }
            else {
                std::cout << '?' << '\n';
            }
        }
        else {
            assert(false);
        }
    }
}
