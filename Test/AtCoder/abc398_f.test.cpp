// #define PROBLEM "https://atcoder.jp/contests/abc398/tasks/abc398_f"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * AtCoder Beginner Contest 398 F - ABCBA
 * https://atcoder.jp/contests/abc398/submissions/67450075
 */

#include "../../Src/Sequence/Manacher.hpp"

#include <cassert>
#include <iostream>
#include <string>

int main() {
#ifdef ATCODER
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::string S;
    std::cin >> S;
    const auto D = zawa::Manacher<int>(S);
    int id = -1, ans = 2 * std::ssize(S);
    for (int i = 0 ; i < std::ssize(D) ; i++) {
        const int half = D[i] / 2;
        if ((i / 2) + half == std::ssize(S) - 1) {
            const int len = D[i] + 2 * (std::ssize(S) - D[i]);
            if (ans > len) {
                id = i;
                ans = len;
            }
        }
    }
    assert(id != -1);
    std::string T = S;
    for (int i = (id / 2) - (D[id] + 1) / 2 ; i >= 0 ; i--) T += S[i];
    std::cout << T << '\n';
#else
    std::cout << "Hello World\n";
#endif
}
