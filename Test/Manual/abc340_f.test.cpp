#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * AtCoder Beginner Contest 340 - F S = 1
 * https://atcoder.jp/contests/abc340/submissions/60264792
 */

#include "../../Src/Number/ExtendGCD.hpp"

#include <cmath>
#include <iostream>

void solve() {
    long long X, Y;
    std::cin >> X >> Y;
    auto [A, B]{zawa::ExtendGCD(Y, -X)};
    long long gcd{std::abs(A*Y + B*(-X))};
    if (gcd == 1) {
        A *= 2;
        B *= 2;
    }
    if (gcd <= 2) {
        std::cout << A << ' ' << B << '\n';
    }
    else {
        std::cout << -1 << '\n';
    }
}

int main() {
#ifdef ATCODER
    solve();
#else
    std::cout << "Hello World\n";
#endif
}
