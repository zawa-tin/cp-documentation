#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/DataStructure/PrefixSum1D/StaticRangeSumSolver.hpp" 

#include <cstdio>
#include <vector>

using namespace zawa;

i32 main() {
    u32 N, Q;
    std::scanf("%u%u", &N, &Q); 
    std::vector<i64> A(N);
    for (auto& a : A) std::scanf("%ld", &a);

    Ruisekiwa<i64> S(A);
    for (u32 _ = 0 ; _ < Q ; _++) {
        u32 l, r;
        std::scanf("%u%u", &l, &r);
        std::printf("%ld\n", S.product(l, r));
    }
}
