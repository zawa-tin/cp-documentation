#define PROBLEM "https://atcoder.jp/contests/abc238/tasks/abc238_c"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Number/ModInt.hpp"

using namespace zawa;
using m32 = StaticModInt<u32, 998244353>;

#include <iostream>
#include <string>
#include <algorithm>

m32 f(u64 v) {
    return m32{v} * m32{v + 1} / m32{2};
}

int main() {
    u64 n; std::cin >> n;
    usize deg{ std::to_string(n).size() };
    m32 ans{};
    u64 now{9};
    for (u32 i{} ; i < deg ; i++) {
        ans += f(std::min(n - (now / 9) + 1, now));
        now *= 10;
    }
    std::cout << ans << std::endl;
}
