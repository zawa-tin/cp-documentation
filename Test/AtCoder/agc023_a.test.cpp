#define PROBLEM "https://atcoder.jp/contests/agc023/tasks/agc023_a"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/DataStructure/PrefixSum1D/StaticRangeSumSolver.hpp"

#include <iostream>
#include <vector>
#include <map>

using namespace zawa;

i32 main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    u32 N; std::cin >> N;
    std::vector<i64> A(N);
    for (auto& a : A) std::cin >> a;

    Ruisekiwa<i64> S(A);
    std::map<i64, i32> mp{};
    u64 ans = 0;
    for (const auto v : S) {
        ans += mp[v];
        mp[v]++;
    } 

    std::cout << ans << std::endl;
}
