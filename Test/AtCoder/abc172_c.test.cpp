#define PROBLEM "https://atcoder.jp/contests/abc172/tasks/abc172_c"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/DataStructure/PrefixSum1D/StaticRangeSumSolver.hpp"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace zawa;

i32 main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    usize N, M; std::cin >> N >> M;
    i64 K; std::cin >> K;

    std::vector<i64> A(N), B(M);
    for (auto& a : A) std::cin >> a;
    for (auto& b : B) std::cin >> b;

    Ruisekiwa<i64> SA(A), SB(B);

    u32 ans = 0;
    for (u32 a = 0 ; a <= N ; a++) {
        if (SA[a] > K) break;
        auto f = [&](i64 v) -> bool {
            return SA[a] + v <= K;
        };  
        u32 val = a + SB.maxRight(0, f);
        ans = std::max(ans, val);
    }

    std::cout << ans << std::endl;
}
