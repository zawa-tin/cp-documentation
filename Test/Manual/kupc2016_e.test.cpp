#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Graph/Flow/Dinic.hpp"

#include <iostream>
#include <string>
#include <vector>

/*
 * Kyoto University Programming Contest 2016-E 柵
 * https://atcoder.jp/contests/kupc2016/submissions/48902787
 */

long long solve() {
    using namespace zawa;
    int h, w; std::cin >> h >> w;
    std::vector<std::string> s(h);
    for (auto& x : s) std::cin >> x;
    constexpr int di[4]{ 1, 0, -1, 0 };
    constexpr int dj[4]{ 0, 1, 0, -1 };
    auto f{[&](int x, int y) -> int {
        return x * w + y;
    }};
    auto in{[&](int x, int y) -> bool {
        return 0 <= x and x < h and 0 <= y and y < w;
    }};
    auto side{[&](int x, int y) -> bool {
        return x == 0 or y == 0 or x == h - 1 or y == w - 1;
    }};
    const long long INF{(long long)1e9};
    Dinic<long long> mf(2 * h * w + 2);
    for (int i{} ; i < h ; i++) {
        for (int j{} ; j < w ; j++) {
            mf.addEdge(f(i, j), h * w + f(i, j), (s[i][j] == 'X' ? INF : 1));
            if (s[i][j] == 'X') {
                mf.addEdge(2 * h * w, f(i, j), INF);
            }
            if (side(i, j)) {
                mf.addEdge(h * w + f(i, j), 2 * h * w + 1, INF);
            }
            for (int d{} ; d < 4 ; d++) {
                int ni{i + di[d]}, nj{j + dj[d]};
                if (!in(ni, nj)) continue;
                mf.addEdge(h * w + f(i, j), f(ni, nj), INF);
            }
        }
    }
    long long ans{mf.flow(2 * h * w, 2 * h * w + 1)};
    return (ans >= INF ? -1LL : ans);
}

int main() {
#ifdef ATCODER
    std::cout << solve() << '\n'; 
#else
    std::cout << "Hello World" << '\n';
#endif
}
