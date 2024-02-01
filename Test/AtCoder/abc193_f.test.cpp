#define PROBLEM "https://atcoder.jp/contests/abc193/tasks/abc193_f"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Graph/Flow/BurnBury.hpp"

int main() {
    using namespace zawa;
    SetFastIO();

    int n; std::cin >> n;
    std::vector s(n, std::string{});
    for (auto& v : s) std::cin >> v;

    auto f{[&](int x, int y) -> int {
        return x * n + y;
    }};
    const int dx[4]{ 1, 0, -1, 0 };
    const int dy[4]{ 0, 1, 0, -1 };
    auto in{[&](int x, int y) -> bool {
        return 0 <= x and x < n and 0 <= y and y < n;
    }};

    BurnBury<int> optimizer(n * n);
    const int INF{(int)1e5};
    for (int x{} ; x < n ; x++) {
        for (int y{} ; y < n ; y++) {
            if ((x + y) % 2 == 0) {
                optimizer.func1(f(x, y), {
                        (s[x][y] == 'W' ? INF : 0),
                        (s[x][y] == 'B' ? INF : 0)
                        });
            }
            else {
                optimizer.func1(f(x, y), {
                        (s[x][y] == 'B' ? INF : 0),
                        (s[x][y] == 'W' ? INF : 0)
                        });
            }
            for (int d{} ; d < 4 ; d++) {
                int nx{x + dx[d]}, ny{y + dy[d]};
                if (!in(nx, ny)) continue;
                if (f(x, y) > f(nx, ny)) continue;
                optimizer.func2(f(x, y), f(nx, ny), {-1, 0, 0, -1});
            }
        }
    }

    int ans{optimizer.build()};  
    ans *= -1;
    std::cout << ans << '\n';
}
