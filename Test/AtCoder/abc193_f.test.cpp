#define PROBLEM "https://atcoder.jp/contests/abc193/tasks/abc193_f"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Graph/Flow/Dinic.hpp"

int main() {
    using namespace zawa;
    SetFastIO();
    int n; std::cin >> n;
    std::vector<std::string> S(n);
    for (auto& s : S) std::cin >> s;
    Dinic<int> mf(n * n + 2);
    int source{n * n}, sink{n * n + 1};
    constexpr int dx[4]{ 1, 0, -1, 0 };
    constexpr int dy[4]{ 0, 1, 0, -1 };
    auto in{[&](int x, int y) -> bool {
        return 0 <= x and x < n and 0 <= y and y < n;
    }};
    auto f{[&](int x, int y) -> int {
        return x * n + y;
    }};
    constexpr int INF{10000};
    int good{};
    for (int x{} ; x < n ; x++) {
        for (int y{} ; y < n ; y++) {
            for (int d{} ; d < 4 ; d++) {
                int nx{x + dx[d]}, ny{y + dy[d]};
                if (!in(nx, ny)) continue;
                mf.addEdge(f(x, y), f(nx, ny), 1);
                good++;
            }
            if ((x + y) & 1) {
                mf.addEdge(source, f(x, y), S[x][y] == 'B' ? INF : 0);
                mf.addEdge(f(x, y), sink, S[x][y] == 'W' ? INF : 0);
            }
            else {
                mf.addEdge(source, f(x, y), S[x][y] == 'W' ? INF : 0);
                mf.addEdge(f(x, y), sink, S[x][y] == 'B' ? INF : 0);
            }
        }
    }
    good /= 2;
    int ans{good - mf.flow(source, sink)};
    std::cout << ans << '\n';
}
