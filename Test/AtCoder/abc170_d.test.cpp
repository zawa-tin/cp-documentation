#define PROBLEM "https://atcoder.jp/contests/abc170/tasks/abc170_d"

#include "../../Src/Number/LinearSieve.hpp"

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main() {
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
        for (auto d : siv.divisor(x)) if (d < (unsigned)x) {
            ok &= cnt.find(d) == cnt.end();
        }
        ans += ok;
    }
    std::cout << ans << std::endl;
}
