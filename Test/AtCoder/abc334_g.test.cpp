#define PROBLEM "https://atcoder.jp/contests/abc334/tasks/abc334_g"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Graph/Components/ConnectedComponents.hpp"
#include "../../Src/Graph/Components/Lowlink.hpp"
#include "../../Src/Number/ModInt.hpp"

#include <iostream>

using namespace zawa;
using mint = StaticModInt<u32, 998244353>;

int main() {
    SetFastIO();
    int h, w; std::cin >> h >> w;
    std::vector s(h, std::string{});
    for (auto& c : s) std::cin >> c;
    auto f{[w](int x, int y) -> int {
        return x * w + y;
    }};
    auto in{[&](int x, int y) -> bool {
        return 0 <= x and x < h and 0 <= y and y < w and s[x][y] == '#';
    }};
    const int dx[4]{ 1, 0, -1, 0 };
    const int dy[4]{ 0, 1, 0, -1 };
    ConnectedComponents cc(h * w);
    Lowlink g(h * w);
    int red{}, green{};
    for (int x{} ; x < h ; x++) {
        for (int y{} ; y < w ; y++) {
            if (!in(x, y)) {
                red++;
                continue;
            }
            else {
                green++;
            }
            for (int d{} ; d < 4 ; d++) {
                int nx{x + dx[d]}, ny{y + dy[d]};
                if (!in(nx, ny)) continue;
                if (f(x, y) > f(nx, ny)) continue;
                cc.addEdge(f(x, y), f(nx, ny));
                g.addEdge(f(x, y), f(nx, ny));
            }
        }
    } 
    cc.build();
    g.build();
    mint res{};
    for (int x{} ; x < h ; x++) {
        for (int y{} ; y < w ; y++) {
            if (!in(x, y)) continue;
            int num{(int)cc.size() - red + (int)g.cut(f(x, y)) - 1};
            int den{green};
            res += mint{num} / mint{den};
        }
    }
    std::cout << res << '\n';
}
