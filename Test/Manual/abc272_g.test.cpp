#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * AtCoder Beginner Contest 272-G Yer Another mod M
 * https://atcoder.jp/contests/abc272/submissions/50049939
 */

#include "../../Src/Number/Divisor.hpp"
#include "../../Src/Sequence/MajorityVote.hpp"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int solve() {
    using namespace zawa;
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    std::sort(a.begin(), a.end());
    std::vector<int> mod;
    for (int i{} ; i < n ; i++) {
        for (int x : Divisor(std::abs(a[i] - a[(i + 1) % n]))) {
            if (x < 3) continue;
            mod.push_back(x);
        }
    }
    std::sort(mod.begin(), mod.end());
    auto m{std::distance(mod.begin(), std::unique(mod.begin(), mod.end()))};
    for (std::ptrdiff_t i{} ; i < m ; i++) {
        std::vector<int> b(n);
        for (int j{} ; j < n ; j++) b[j] = a[j] % mod[i];
        if (MajorityVote<int>(b.begin(), b.end())) {
            return mod[i];
        }
    }
    return -1;
}

int main() {
#ifdef ATCODER
    std::cout << solve() << '\n';
#else
    std::cout << "Hello World" << '\n';
#endif
}
