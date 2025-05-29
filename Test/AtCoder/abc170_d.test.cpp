// #define PROBLEM "https://atcoder.jp/contests/abc170/tasks/abc170_d"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * AtCoder Beginner Contest 170 - D Not Divisible
 * https://atcoder.jp/contests/abc170/submissions/66240723
 */

#include "../../Src/Number/LinearSieve.hpp"

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main() {
#ifdef ATCODER
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    std::sort(a.begin(), a.end());
    std::map<int, int> cnt;
    for (auto x : a) cnt[x]++;
    int ans{};
    zawa::LinearSieve siv(a.back());
    for (auto x : a) if (cnt[x] == 1) {
        bool ok{true};
        for (auto d : siv.divisor<int>(x)) if (d < x) {
            ok &= cnt.find(d) == cnt.end();
        }
        ans += ok;
    }
    std::cout << ans << std::endl;
#else
    std::cout << "Hello World\n";
#endif
}
