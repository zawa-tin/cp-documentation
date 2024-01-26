#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Graph/Flow/BurnBury.hpp"

#include <iostream>

/*
 * 競プロ典型90問-040 Get More Money
 * https://atcoder.jp/contests/typical90/submissions/49664834
 */

void solve() {
    using namespace zawa;
    SetFastIO();
    int n; std::cin >> n;
    BurnBury<long long> solver(n);
    long long w; std::cin >> w;
    for (int i{} ; i < n ; i++) {
        long long a; std::cin >> a;
        solver.func1(i, { 0LL, -(a - w) });
    }
    const long long INF{(long long)1e12};
    for (int i{} ; i < n ; i++) {
        int k; std::cin >> k;
        for (int _{} ; _ < k ; _++) {
            int c; std::cin >> c;
            c--;
            solver.func2(i, c, { 0LL, INF, 0LL, 0LL });
        }
    }
    long long ans{solver.build()};
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
