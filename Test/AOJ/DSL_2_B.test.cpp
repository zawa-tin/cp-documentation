#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Algebra/Group/AdditiveGroup.hpp"
#include "../../Src/DataStructure/FenwickTree/FenwickTree.hpp"

#include <iostream>
#include <vector>
#include <cassert>

using namespace zawa;

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    usize n, q; std::cin >> n >> q;
    FenwickTree<AdditiveGroup<i32>> ft(n); 
    for (u32 _{} ; _ < q ; _++) {
        u32 t; std::cin >> t;
        if (t == 0) {
            u32 i, x; std::cin >> i >> x;
            ft.operation(i - 1, x);
        }
        else if (t == 1) {
            u32 s, t; std::cin >> s >> t;
            std::cout << ft.product(s - 1, t) << '\n';
        }
        else {
            assert(!"input fail");
        }
    }
}
