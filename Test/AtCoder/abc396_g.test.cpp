// #define PROBLEM "https://atcoder.jp/contests/abc396/tasks/abc396_g"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * AtCoder Beginner Contest 396 - G Flip Row or Col
 * https://atcoder.jp/contests/abc396/submissions/66400307
 */

#include "../../Src/Sequence/BitwiseXORConvolution.hpp"

#include <algorithm>
#include <bit>
#include <iostream>
#include <string>
#include <vector>
#include <ranges>

int main() {
#ifdef ATCODER
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int H, W;
    std::cin >> H >> W;
    std::vector<int> A(1 << W), B(1 << W);
    for (int i = 0 ; i < H ; i++) {
        std::string S;
        std::cin >> S;
        int v = 0;
        for (int j = 0 ; j < W ; j++) if (S[j] == '1') v |= 1 << j;
        A[v]++;
    }
    for (int i = 0 ; i < (1 << W) ; i++) {
        const int cnt = std::popcount((unsigned)i);
        B[i] = std::min(cnt, W - cnt);
    }
    auto C = zawa::BitwiseXORConvolution<long long>(A, B);
    std::cout << *std::ranges::min_element(C) << '\n';
#else
    std::cout << "Hello World\n";
#endif
}
