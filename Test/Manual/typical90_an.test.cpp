#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Graph/Flow/Dinic.hpp"

#include <iostream>

/*
 * 競プロ典型90問-040 Get More Money
 * https://atcoder.jp/contests/typical90/submissions/48902896
 */

void solve() {
    using namespace zawa;
    SetFastIO();
    const long long INF1{(long long)1e11};
    const long long INF2{(long long)1e16};
    int n, w; std::cin >> n >> w;
    Dinic<long long> mf(n + 2);
    int s{n}, t{n + 1};
    for (int i{} ; i < n ; i++) {
        int a; std::cin >> a;
        // 入る(燃やす)
        mf.addEdge(s, i, INF1 - (a - w));
        // 入らない(埋める)
        mf.addEdge(i, t, INF1);
    }
    for (int i{} ; i < n ; i++) {
        int k; std::cin >> k;
        for (int _{} ; _ < k ; _++) {
            // 家cに入って(燃やす)家iに入らない(埋める)と無限の損
            int c; std::cin >> c;
            c--;
            mf.addEdge(i, c, INF2);
        }
    }
    long long ans{mf.flow(s, t)};
    ans -= INF1 * n;
    ans *= -1;
    std::cout << ans << '\n';
}

int main() {
#ifdef ATCODER
    solve();
#else
    std::cout << "Hello World" << '\n';
#endif
}
