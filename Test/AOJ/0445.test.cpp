#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/0445"
#define ERROR 0.0001

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/GeometryZ2/Polygon.hpp"

using namespace zawa;
using namespace geometryZ2;

int main() {
    SetFastIO();
    SetPrecision(6);
    int n; std::cin >> n;
    Polygon p(n);
    std::cin >> p;
    Zahlen total{p.areaTwice()};
    Zahlen area{};
    Zahlen ans{total};
    int r{};
    for (int l{} ; l < n ; l++) {
        while (area * 2 < total) {
            area += p.subtriangle(l, r, r+1==n?0:r+1).areaTwice();
            r = (r+1==n?0:r+1);
        }
        ans = std::min(ans, std::abs(area * 2 - total));
        if (l == r) r++;
        else area -= p.subtriangle(l, l+1==n?0:l+1, r).areaTwice();
    }
    std::cout << ans / 2.0 << '\n';
}
