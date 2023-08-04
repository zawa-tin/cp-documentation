#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/4/ITP2_4_A"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Template/VectorIO.hpp"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace zawa;

int main() {
    u32 n; std::cin >> n;
    std::vector<i32> a(n); std::cin >> a;
    u32 q; std::cin >> q;
    for (u32 _{} ; _ < q ; _++) {
        u32 l, r; std::cin >> l >> r;
        std::reverse(a.begin() + l, a.begin() + r);
    }
    std::cout << a << std::endl;
}
