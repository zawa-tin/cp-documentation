#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/Sequence/RunLengthEncoding.hpp"

#include <vector>
#include <iostream>

/*
 * AGC026-A Colorful Slimes 2
 * https://atcoder.jp/contests/agc026/submissions/45973756
 */

void solve() {
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    zawa::RunLengthEncoding rle(a);
    int ans{};
    for (const auto& x : rle) ans += x.number() / 2;
    std::cout << ans << std::endl;
}

int main() {
#ifdef ATCODER
    solve();
#else
    std::cout << "Hello World" << std::endl;
#endif
}
