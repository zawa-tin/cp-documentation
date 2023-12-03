#define PROBLEM "https://atcoder.jp/contests/abc276/tasks/abc276_f"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Number/ModInt.hpp"
#include "../../Src/DataStructure/FenwickTree/FenwickTree.hpp"
#include "../../Src/Algebra/Group/AdditiveGroup.hpp"

#include <iostream>

using namespace zawa;
using m32 = StaticModInt<u32, 998244353>;

int main() {
    SetFastIO();
    usize n; std::cin >> n;

    const usize sz{ 200200 };
    FenwickTree<AdditiveGroup<m32>> ft1(sz), ft2(sz);

    m32 now{};
    m32 ans{};
    for (u32 k{1} ; k <= n ; k++) {
        m32 a; std::cin >> a;
        now += (m32{2} * ft1.prefixProduct(a.v() + 1) + m32{1}) * a;
        now += m32{2} * ft2.product(a.v() + 1, sz);
        ans = now / (m32{k} * m32{k});

        std::cout << ans << '\n';

        ft1.operation(a.v(), m32{1});
        ft2.operation(a.v(), a);
    }
}
