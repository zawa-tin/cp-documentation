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

    A.push_back((i64)1e15);
    B.push_back((i64)1e15);
    N++; M++;

    Ruisekiwa<i64> SA(A), SB(B);

    u32 ans1{}, ans2{};

    {
        for (auto a : SA) {
            if (a > K) break;
            u32 v = a + SB.upperBound(0, M, K - SA[a]) - 1;
            ans1 = std::max(ans1, v);
        }
    }

    {
        for (u32 a = 0 ; a <= N ; a++) {
            if (SA[a] > K) break;
            auto f = [&](i64 v) -> bool {
                return SA[a] + v <= K;
            };
            u32 v = a + SB.maxRight(0, f) - 1;
            ans2 = std::max(ans2, v);
        }
    }

    assert(ans1 == ans2);

    std::cout << ans1 << std::endl;
}
