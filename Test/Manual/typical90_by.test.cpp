#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Graph/Flow/Dinic.hpp"

#include <iostream>
#include <unordered_map>
#include <vector>

/*
 * 競プロ典型90-077 Planes on a 2D Plane
 * https://atcoder.jp/contests/typical90/submissions/48902918
 */

int dx[8]{ 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[8]{ 0, 1, 1, 1, 0, -1, -1, -1 };

const long long INF{(long long)2e9};
long long f(int x, int y) {
    return (long long)x * INF + y;
}

void solve() {
    using namespace zawa;
    SetFastIO();
    int n, t; std::cin >> n >> t;
    for (int i{} ; i < 8 ; i++) {
        dx[i] *= t;
        dy[i] *= t;
    }
    std::vector<int> ax(n), ay(n);
    for (int i{} ; i < n ; i++) std::cin >> ax[i] >> ay[i];
    std::unordered_map<long long, int> map;
    for (int i{} ; i < n ; i++) {
        int x, y; std::cin >> x >> y;
        map[f(x, y)] = i;
    }
    Dinic<int> mf(2 * n + 2, 2 * n + 8 * n); 
    for (int i{} ; i < n ; i++) {
        mf.addEdge(2 * n, i, 1);
        mf.addEdge(n + i, 2 * n + 1, 1);
    }
    std::vector table(n, std::vector<int>(8, -1));
    for (int i{} ; i < n ; i++) {
        for (int j{} ; j < 8 ; j++) {
            int nx{ax[i] + dx[j]}, ny{ay[i] + dy[j]};
            if (nx < 0 or ny < 0) continue;
            if (nx > (int)1e9 or ny > (int)1e9) continue;
            auto it{map.find(f(nx, ny))};
            if (it == map.end()) continue;
            table[i][j] = mf.addEdge(i, n + it->second, 1);
        }
    }
    int ans{mf.flow(2 * n, 2 * n + 1)};
    if (ans < n) {
        std::cout << "No" << '\n';
    }
    else {
        std::cout << "Yes" << '\n';
        for (int i{} ; i < n ; i++) {
            for (int j{} ; j < 8 ; j++) {
                if (table[i][j] == -1) continue;
                if (mf.residual(table[i][j]) == 0) {
                    std::cout << j + 1 << (i + 1 == n ? '\n' : ' ');
                    break;
                }
            }
        }
    }
}

int main() {
#ifdef ATCODER
    solve();
#else
    std::cout << "Hello World" << '\n';
#endif
}
