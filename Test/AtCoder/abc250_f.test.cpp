#define PROBLEM "https://atcoder.jp/contests/abc250/tasks/abc250_f"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/GeometryZ2/Polygon.hpp"

#include <iostream>

int main() {
    using namespace zawa;
    using namespace geometryZ2;
    SetFastIO();
    int n; std::cin >> n;
    Polygon p(n);
    std::cin >> p;
    Zahlen a{p.areaTwice()};
    Zahlen b{};
    Zahlen ans{4 * a};
    int r{};
    for (int l{} ; l < n ; l++) {
        while (b < a) {
            b += 4 * p.subtriangle(l, r, r+1==n?0:r+1).areaTwice();
            r = (r+1==n?0:r+1);
            ans = std::min(ans, std::abs(a - b));
        }
        if (l == r) r++;
        else {
            b -= 4 * p.subtriangle(l, l+1==n?0:l+1, r).areaTwice();
            ans = std::min(ans, std::abs(a - b));
        }
    }
    std::cout << ans << '\n';
}
