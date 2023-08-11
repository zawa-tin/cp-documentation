#define PROBLEM "https://atcoder.jp/contests/abc236/tasks/abc236_e"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Template/FloatingNumberAlias.hpp"
#include "../../Src/Template/Input.hpp"
#include "../../Src/Template/Output.hpp"
#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Utility/BinarySearch.hpp"

#include <vector>
#include <array>
#include <utility>
#include <algorithm>

using namespace zawa;

template <class T>
T eval(const std::vector<T>& A) {
    std::array<T, 2> dp{ T{}, T{} };
    for (auto a : A) {
        std::array<T, 2> nxt{ T{}, T{} };
        nxt[0] = std::max(dp[0] + a, dp[1] + a);
        nxt[1] = dp[0];
        dp = std::move(nxt);
    }
    return std::max(dp[0], dp[1]);
}

int main() {
    SetPrecision(5);
    usize N; input(N);
    std::vector<i32> A(N); input(A);

    auto ave{[&](ld v) -> bool {
        std::vector<ld> B(N);
        for (u32 i{} ; i < N ; i++) B[i] = (ld)A[i] - v;
        return eval(B) >= 0.0l;
    }};

    auto med{[&](i32 v) -> bool {
        std::vector<i32> B(N);
        for (u32 i{} ; i < N ; i++) B[i] = (A[i] >= v ? 1 : -1);
        return eval(B) > 0;
    }};

    out(BinarySearch(0.0l, 1e9 + 1.0l, ave, 50));
    out(BinarySearch(0, (i32)1e9 + 1, med));
}
