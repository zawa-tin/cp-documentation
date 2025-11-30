#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
// #define PROBLEM "https://atcoder.jp/contests/agc023/tasks/agc023_a"

/*
 * AtCoder Grand Contest 023
 * https://atcoder.jp/contests/agc023/submissions/71354946
 */

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/DataStructure/PrefixSum/StaticRangeSumSolver.hpp"

#include <iostream>
#include <vector>
#include <map>

using namespace zawa;

i32 main() {
#ifdef ATCODER
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
#else
    std::cout << "Hello World\n";
#endif
}
