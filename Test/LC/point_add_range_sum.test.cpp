#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Template/VectorIO.hpp"
#include "../../Src/Algebra/Group/AdditiveGroup.hpp"
#include "../../Src/DataStructure/FenwickTree/FenwickTree.hpp"

#include <iostream>
#include <vector>
#include <cassert>

using namespace zawa;

int main() {
    SetFastIO();
    usize N, Q; std::cin >> N >> Q;
    std::vector<i64> A(N); std::cin >> A;

    FenwickTree<AdditiveGroup<i64>> ft(A);

    for (u32 _{} ; _ < Q ; _++) {
        u32 t; std::cin >> t;
        if (t == 0) {
            u32 p; std::cin >> p;
            i64 x; std::cin >> x;
            ft.add(p, x);
        }
        else if (t == 1) {
            u32 l, r; std::cin >> l >> r;
            std::cout << ft.product(l, r) << std::endl;
        }
        else {
            assert(!"input fail");
        }
    }
}
