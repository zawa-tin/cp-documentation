#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Graph/Flow/Dinic.hpp"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

/*
 * AtCoder Library Practice Contest-D Maxflow
 * https://atcoder.jp/contests/practice2/submissions/48601081
 */

void solve() {
    using namespace zawa; 
    int n, m; std::cin >> n >> m;
    std::vector<std::string> s(n);
    for (auto& v : s) std::cin >> v;
    constexpr int dx[4]{ 1, 0, -1, 0 };
    constexpr int dy[4]{ 0, 1, 0, -1 }; 
    auto f{[&](int x, int y) -> int {
        return x * m + y;
    }};
    auto sign{[&](int x, int y) -> int {
        return (x % 2) ^ (y % 2);
    }};
    auto in{[&](int x, int y) -> bool {
        return 0 <= x and x < n and 0 <= y and y < m;
    }};
    Dinic<int> maxflow(n * m + 2);
    std::vector edges(n * m + 2, std::vector<u32>{});
    for (int i{} ; i < n ; i++) for (int j{} ; j < m ; j++) {
        if (s[i][j] == '#') continue;
        if (sign(i, j) == 0) {
            maxflow.addEdge(n * m, f(i, j), 1);
            for (int d{} ; d < 4 ; d++) {
                int ni{i + dx[d]}, nj{j + dy[d]};
                if (!in(ni, nj)) continue;
                if (s[ni][nj] == '#') continue;
                edges[f(i, j)].push_back(maxflow.addEdge(f(i, j), f(ni, nj), 1));
            }
        }
        else {
            maxflow.addEdge(f(i, j), n * m + 1, 1);
        }
    }
    int ans{maxflow.flow(n * m, n * m + 1)};
    std::cout << ans << '\n';
    std::vector<std::string> t(n, std::string(m, '.'));
    auto g{[&](int v) -> std::pair<int, int> {
        return std::pair{ v / m, v % m };
    }};
    for (int v{} ; v < n + m - 1 ; v++) {
        for (int i{std::max(0, v - m + 1)} ; i < std::min(n, v + 1) ; i++) {
            int j{v - i};
            if (s[i][j] == '#') {
                t[i][j] = '#';
                continue;
            }
            if (sign(i, j) % 2 == 1) continue;
            for (auto e : edges[f(i, j)]) {
                if (maxflow.residual(e) == 1) continue;
                auto [x, y]{ g(maxflow.to(e)) };
                assert(in(x, y));
                assert(s[x][y] == '.');
                assert(t[x][y] == '.');
                int dx{ x - i }, dy{ y - j };
                if (dx == -1 and dy == 0) {
                    t[x][y] = 'v';
                    t[i][j] = '^';
                }
                else if (dx == 1 and dy == 0) {
                    t[x][y] = '^';
                    t[i][j] = 'v';
                }
                else if (dx == 0 and dy == -1) {
                    t[x][y] = '>';
                    t[i][j] = '<';
                }
                else if (dx == 0 and dy == 1) {
                    t[x][y] = '<';
                    t[i][j] = '>';
                }
                else {
                    assert(false);
                }
            } 
        }
    }
    for (const auto& v : t) std::cout << v << '\n';
}

int main() {
#ifdef ATCODER
    solve();
#else
    std::cout << "Hello World" << '\n';
#endif
}
