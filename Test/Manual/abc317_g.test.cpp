#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Graph/Flow/Dinic.hpp"

#include <cassert>
#include <iostream>
#include <vector>

/*
 * AtCoder Beginner Contest 317 - G Rearranging
 * https://atcoder.jp/contests/abc317/submissions/48525602
 */

void solve() {
    using namespace zawa;
    SetFastIO();
    int n, m; std::cin >> n >> m;
    // i行目に残り要素jが何個残っているか？
    std::vector remain(n, std::vector<int>(n)); for (int i{} ; i < n ; i++) for (int j{} ; j < m ; j++) {
        int a; std::cin >> a;
        remain[i][a - 1]++;
    }
    std::vector ans(n, std::vector<int>(m));
    for (int col{} ; col < m ; col++) {
        Dinic<int> mf(2 * n + 2);
        for (int i{} ; i < n ; i++) {
            mf.addEdge(2 * n, i, 1);
            mf.addEdge(n + i, 2 * n + 1, 1);
        }
        std::vector id(n, std::vector<int>(n));
        for (int i{} ; i < n ; i++) for (int j{} ; j < n ; j++) {
            id[i][j] = mf.addEdge(i, n + j, (bool)remain[i][j]);
        }
        assert(mf.flow(2 * n, 2 * n + 1) == n);
        for (int i{} ; i < n ; i++) for (int j{} ; j < n ; j++) {
            if (mf.flowed(id[i][j]) == 1) {
                ans[i][col] = j + 1;
                remain[i][j]--;
            }
        }
    }
    std::cout << "Yes" << '\n';
    for (int i{} ; i < n ; i++) {
        for (int j{} ; j < m ; j++) {
            std::cout << ans[i][j] << (j + 1 == m ? '\n' : ' ');
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
