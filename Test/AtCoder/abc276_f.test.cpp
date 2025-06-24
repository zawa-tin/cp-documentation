#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
// #define PROBLEM "https://atcoder.jp/contests/abc276/tasks/abc276_f"

/*
 * AtCoder Beginner Contest 276 F - Double Chance
 * https://atcoder.jp/contests/abc276/submissions/67045295
 */

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/DataStructure/FenwickTree/FenwickTree.hpp"
#include "../../Src/Algebra/Group/AdditiveGroup.hpp"

#include <iostream>

using namespace zawa;
#include "atcoder/modint"
using m32 = atcoder::modint998244353;

int main() {
#ifdef ATCODER
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    usize n; std::cin >> n;

    const usize sz{ 200200 };
    FenwickTree<AdditiveGroup<m32>> ft1(sz), ft2(sz);

    m32 now{};
    m32 ans{};
    for (u32 k{1} ; k <= n ; k++) {
        int in;
        std::cin >> in;
        m32 a = m32::raw(in);
        now += (m32{2} * ft1.prefixProduct(a.val() + 1) + m32{1}) * a;
        now += m32{2} * ft2.product(a.val() + 1, sz);
        ans = now / (m32{k} * m32{k});

        std::cout << ans.val() << '\n';

        ft1.operation(a.val(), m32{1});
        ft2.operation(a.val(), a);
    }
#else
    std::cout << "Hello World\n";
#endif
}
