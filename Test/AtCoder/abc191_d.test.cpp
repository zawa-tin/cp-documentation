#define PROBLEM "https://atcoder.jp/contests/abc191/tasks/abc191_d"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Template/FloatingNumberAlias.hpp"
#include "../../Src/Number/IntegerDivision.hpp"
#include "../../Src/Utility/FloatingMarkerShift.hpp"
#include "../../Src/Utility/BinarySearch.hpp"
#include "../../Src/GeometryZ2/Circle.hpp"
#include "../../Src/GeometryZ2/Contain/CircleContainsPoint.hpp"

#include <iostream>
#include <cmath>

using namespace zawa;
using namespace geometryZ2;

i64 parse() {
    std::string s; std::cin >> s;
    return FloatingMarkerShift(s, 4);
}

constexpr i64 mul{10000}, range{200100};

int main() {
    i64 X{parse()}, Y{parse()}, R{parse()}; 
    Circle c{Point{X, Y}, R};
    u64 ans{};
    
    auto contain{[&](Zahlen x, Zahlen y) -> bool {
        return CircleContainsPoint(c, Point{x, y}) != OUTSIDE;
    }};

    for (i64 x{-range * mul} ; x <= range * mul ; x += mul) {
        if (!contain(x, Y)) continue;
        i64 u{BinarySearch(Y, Y + R + 1, [&](i64 p) -> bool { return contain(x, p); })};
        u = DivFloor(u, mul);
        i64 d{BinarySearch(Y, Y - R - 1, [&](i64 p) -> bool { return contain(x, p); })};
        d = DivCeil(d, mul);
        ans += (u - d + 1);
    }
    std::cout << ans << std::endl;
}
