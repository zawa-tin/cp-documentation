#define PROBLEM "https://atcoder.jp/contests/abc132/tasks/abc132_f"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Number/EnumerateQuotients.hpp"

#include <iostream>
#include <vector>
#include <utility>

using namespace zawa;

constexpr u64 mod{1000000007};

int main() {
    u32 N, K; std::cin >> N >> K;
    EnumerateQuotients eq(N);
    
    std::vector<u64> dp(eq.size());
    dp[0] = 1;
    for (u32 _{} ; _ < K + 1 ; _++) {
        std::vector<u64> nxt(eq.size()), sum(eq.size() + 1);
        for (u32 i{} ; i < eq.size() ; i++) sum[i + 1] = (sum[i] + dp[i] * eq[i].len()) % mod;
        for (u32 i{} ; i < eq.size() ; i++) nxt[i] = sum[eq.size() - i];
        dp = std::move(nxt);
    }

    std::cout << dp[0] << std::endl;
}
