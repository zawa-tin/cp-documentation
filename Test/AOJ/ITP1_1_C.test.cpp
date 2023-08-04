#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_C"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Template/PairIO.hpp"

#include <iostream>
#include <utility>

using namespace zawa;

int main() {
    std::pair<u32, u32> R; std::cin >> R;
    std::pair<u32, u32> ans{ R.first * R.second, 2 * (R.first + R.second) };
    std::cerr << ans << std::endl;
    std::cout << ans.first << ' ' << ans.second << std::endl;
}
