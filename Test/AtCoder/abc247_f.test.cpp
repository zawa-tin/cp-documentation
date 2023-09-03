#define PROBLEM "https://atcoder.jp/contests/abc247/tasks/abc247_f"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Template/VectorIO.hpp"
#include "../../Src/Number/ModInt.hpp"
#include "../../Src/Graph/Components/ConnectedComponents.hpp"

#include <iostream>
#include <vector>
#include <array>

using namespace zawa;
using m32 = StaticModInt<u32, 998244353>;

int main() {
    usize n; std::cin >> n;

    std::vector<m32> cyc(n + 1);

    std::array<m32, 2> dp1{ m32{1}, m32{} }, dp2{ m32{}, m32{1} };
    for (u32 i{} ; i < n ; i++) {
        cyc[i + 1] = dp1[true] + dp2[false] + dp2[true];
        std::array<m32, 2> nxt1, nxt2;
        nxt1[false] = dp1[true];
        nxt2[false] = dp2[true];
        nxt1[true] = dp1[false] + dp1[true];
        nxt2[true] = dp2[false] + dp2[true];
        dp1 = std::move(nxt1);
        dp2 = std::move(nxt2);
    }

    std::vector<u32> p(n), q(n);
    std::cin >> p >> q;
    ConnectedComponents cc(n);
    for (u32 i{} ; i < n ; i++) {
        cc.addEdge(p[i] - 1, q[i] - 1);
    }
    cc.build();

    m32 ans{1};
    for (u32 i{} ; i < cc.size() ; i++) {
        ans *= cyc[cc.n(i)];
    }
    std::cout << ans << std::endl;
}
