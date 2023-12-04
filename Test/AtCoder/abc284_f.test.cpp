#define PROBLEM "https://atcoder.jp/contests/abc284/tasks/abc284_f"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Sequence/RollingHash.hpp"
using namespace zawa;

#include <algorithm>
#include <iostream>
#include <string>

int main() {
    int n; std::cin >> n;
    std::string t; std::cin >> t;
    RollingHashFactory roll(1000000, 26);
    auto rt{roll.create(t)};
    std::reverse(t.begin(), t.end());
    auto tr{roll.create(t)};
    std::reverse(t.begin(), t.end());
    for (int i{} ; i <= n ; i++) {
        auto f{rt.prefix(i)}, b{rt.range(i + n, 2 * n)};
        int l{i}, r{i + n};
        auto mid{tr.range(2 * n - r, 2 * n - l)};
        if (roll.concate(f, b) == mid) {
            std::string ans{t.substr(i, n)};
            std::reverse(ans.begin(), ans.end());
            std::cout << ans << '\n' << i << '\n';
            return 0;
        }
    }
    std::cout << -1 << '\n';
}
