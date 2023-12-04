#define PROBLEM "https://atcoder.jp/contests/abc141/tasks/abc141_e"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Sequence/RollingHash.hpp"
using namespace zawa;

#include <iostream>
#include <unordered_set>
#include <string>

int main() {
    SetFastIO();
    int n; std::cin >> n;
    std::string s; std::cin >> s;
    RollingHashFactory roll(n, 26);
    auto H{roll.create(s)};
    using Value = RollingHashFactory::Value;
   
    auto judge{[&](int len) -> bool {
        std::unordered_set<Value> set;
        std::vector<Value> data(n - len + 1);
        for (int i{} ; i + len - 1 < n ; i++) {
            if (i >= len) {
                set.insert(data[i - len]);
            }
            data[i] = H.range(i, i + len).hash();
            if (set.find(data[i]) != set.end()) {
                return true;
            }
        }
        return false;
    }};

    int ans{};
    for (int i{1} ; i <= n / 2 ; i++) {
        if (judge(i)) ans = i;
    }

    std::cout << ans << '\n';
}
