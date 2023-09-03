#define PROBLEM "https://atcoder.jp/contests/abc307/tasks/abc307_e"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Number/ModInt.hpp"

#include <iostream>
#include <array>

using namespace zawa;
using m32 = StaticModInt<u32, 998244353>;

int main() {
    u32 n, m; std::cin >> n >> m;
    std::array<m32, 2> dp{ m32{m}, m32{} }; 
    for (u32 _{} ; _ < n - 1 ; _++) {
        std::array<m32, 2> nxt;
        nxt[0] = dp[1];
        nxt[1] = dp[0] * m32{m - 1} + dp[1] * m32{m - 2};
        dp = std::move(nxt);
    }
    std::cout << dp[1] << std::endl;
}
