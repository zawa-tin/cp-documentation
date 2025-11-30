#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
//#define PROBLEM "https://atcoder.jp/contests/abc229/tasks/abc229_d"

/*
 * AtCoder Beginner Contest 229 D - Longest X
 * https://atcoder.jp/contests/abc229/submissions/71354868
 */

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/DataStructure/PrefixSum/StaticRangeSumSolver.hpp"

using namespace zawa;

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
#ifdef ATCODER
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string S;
    std::cin >> S;
    u32 K;
    std::cin >> K;

    std::vector<i32> A(S.size());
    for (u32 i = 0 ; i < S.size() ; i++) {
        A[i] = S[i] == '.';
    }
    A.push_back(K + 1);

    Ruisekiwa<i32> pref(A);

    u32 ans = 0;
    for (u32 i = 0 ; i <= S.size() ; i++) {
        u32 v = pref.upperBound(i, pref.size() - 1, K) - 1;
        ans = std::max(ans, v - i);
    }

    std::cout << ans << std::endl;
#else
    std::cout << "Hello World\n";
#endif
}
