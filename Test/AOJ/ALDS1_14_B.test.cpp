#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Sequence/RollingHash.hpp"
using namespace zawa;

#include <iostream>
#include <string>

int main() {
    SetFastIO();
    RollingHashFactory roll(1000000);
    std::string t, p; std::cin >> t >> p;
    auto T{roll.create(t)};
    auto P{roll.hash(p)};
    for (usize i{} ; i + p.size() - 1 < t.size() ; i++) {
        if (T.range(i, i + p.size()) == P) {
            std::cout << i << '\n';
        }
    }
}
