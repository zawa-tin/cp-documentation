#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2943"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Graph/Flow/Dinic.hpp"

#include <cassert>
#include <iostream>
#include <vector>

int main() {
    using namespace zawa;
    SetFastIO();
    int h, w; std::cin >> h >> w;
    long long W; std::cin >> W;
    std::vector B(h, std::vector<long long>(w));
    for (auto& b : B) for (auto& x : b) std::cin >> x;
    auto exist{[&](int x, int y) -> bool {
        return x + 1 < h and y + 1 < w and (x + y) % 2 == 0;
    }};
    auto f{[&](int x, int y) -> int {
        return x * w + y;
    }};
    Dinic<long long> mf(h * w + 2);
    int source{h * w}, sink{source + 1};
    const long long INF{(long long)1e12};
    int count{};
    for (int i{} ; i < h ; i++) {
        for (int j{} ; j < w ; j++) {
            if (!exist(i, j)) continue;
            count++;
            if (i % 2 == 0) {
                mf.addEdge(source, f(i, j), 
                        INF - (-W + B[i][j] + B[i + 1][j] + B[i][j + 1] + B[i + 1][j + 1]));
                mf.addEdge(f(i, j), sink, INF);
                if (i - 1 >= 0 and j - 1 >= 0) {
                    assert(exist(i - 1, j - 1));
                    mf.addEdge(f(i - 1, j - 1), f(i, j), B[i][j]);
                }
                if (i - 1 >= 0 and j + 1 < w - 1) {
                    assert(exist(i - 1, j + 1));
                    mf.addEdge(f(i - 1, j + 1), f(i, j), B[i][j + 1]);
                }
            }
            else {
                mf.addEdge(f(i, j), sink, 
                        INF - (-W + B[i][j] + B[i + 1][j] + B[i][j + 1] + B[i + 1][j + 1]));
                mf.addEdge(source, f(i, j), INF);
                if (i - 1 >= 0 and j - 1 >= 0) {
                    assert(exist(i - 1, j - 1));
                    mf.addEdge(f(i, j), f(i - 1, j - 1), B[i][j]);
                }
                if (i - 1 >= 0 and j + 1 < w - 1) {
                    assert(exist(i - 1, j + 1));
                    mf.addEdge(f(i, j), f(i - 1, j + 1), B[i][j + 1]);
                }
            }
        }
    }
    long long ans{mf.flow(source, sink)};
    ans -= count * INF;
    ans = -ans;
    std::cout << ans << '\n';
}
