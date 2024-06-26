#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2609"

#include "../../Src/GeometryZ2/Point.hpp"
#include "../../Src/GeometryZ2/Circle.hpp"
#include "../../Src/Utility/BinarySearch.hpp"
using namespace zawa;
using namespace geometryZ2;

int main() {
    Zahlen W, H, V, T, X, Y, P, Q;
    std::cin >> W >> H >> V >> T >> X >> Y >> P >> Q;
    Circle wave{Point{ X, Y }, V * T};
    Zahlen ans{};
    auto hito{[&](Zahlen x, Zahlen y) -> Point {
        Point res{W * x, H * y};
        res.x() += (x % 2 ? W - P : P);
        res.y() += (y % 2 ? H - Q : Q);
        return res;
    }};
    auto contains{[&](Zahlen x, Zahlen y) -> bool {
        Point diff{wave.center() - hito(x, y)};
        return !diff.isNormSquareOver(wave.radiusSquare());
    }};
    for (Zahlen x{-1000000} ; x <= 1000000 ; x++) {
        if (!contains(x, 0)) continue;
        ans += BinarySearch(Zahlen{1000000}, Zahlen{0}, [&](Zahlen y) -> bool {
                return !contains(x, y);
                });
        ans -= BinarySearch(Zahlen{0}, Zahlen{-1000000}, [&](Zahlen y) -> bool {
                return contains(x, y);
                });
    }
    std::cout << ans << '\n';
}
