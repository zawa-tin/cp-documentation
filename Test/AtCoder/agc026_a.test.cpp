#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/agc026/tasks/agc026_a"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Sequence/RunLengthEncoding.hpp"

#include <iostream>
#include <vector>

using namespace zawa;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    u32 N; std::cin >> N;
    std::vector<u32> A(N);
    for (auto& a : A) std::cin >> a;
    
    RunLengthEncoding rle(A);

    u32 ans{};
    for (const auto& r : rle) ans += (r.number() >> 1);

    std::cout << ans << std::endl;
}
