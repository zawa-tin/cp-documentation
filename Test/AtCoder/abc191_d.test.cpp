#define PROBLEM "https://atcoder.jp/contests/abc191/tasks/abc191_d"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Template/FloatingNumberAlias.hpp"
#include "../../Src/Number/IntegerDivision.hpp"
#include "../../Src/Utility/FloatingMarkerShift.hpp"
#include "../../Src/Utility/BinarySearch.hpp"

#include <iostream>
#include <cmath>

using namespace zawa;

i64 parse() {
    std::string s; std::cin >> s;
    return FloatingMarkerShift(s, 4);
}

constexpr i64 mul{10000}, range{200100};

int main() {
    i64 X{parse()}, Y{parse()}, R{parse()}; 
    u64 ans{};
    for (i64 x{-range * mul} ; x <= range * mul ; x += mul) {
        if (abs(x - X) > R) continue;
        i64 y2{ R * R - (x - X) * (x - X) };
        assert(y2 >= 0);
        i64 u{BinarySearch(Y, Y + R + 1, [&](i64 p) -> bool { return (p - Y) * (p - Y) <= y2;})};
        u = DivFloor(u, mul);
        i64 d{BinarySearch(Y, Y - R - 1, [&](i64 p) -> bool { return (p - Y) * (p - Y) <= y2;})};
        d = DivCeil(d, mul);
        ans += (u - d + 1);
    }
    std::cout << ans << std::endl;
}
