#define PROBLEM "https://atcoder.jp/contests/abc276/tasks/abc276_f"

/*
 * AtCoder Beginner Contest 276 F - Double Chance
 * https://atcoder.jp/contests/abc276/submissions/64948085
 */

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/DataStructure/FenwickTree/FenwickTree.hpp"
#include "../../Src/Algebra/Group/AdditiveGroup.hpp"

#include <iostream>

using namespace zawa;
#include "atcoder/modint"
using m32 = atcoder::modint998244353;

int main() {
    SetFastIO();
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
}
