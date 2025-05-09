#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"

#include "../../Src/Number/EnumeratePrimes.hpp"
using namespace zawa;

#include <iostream>

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int N, A, B;
    std::cin >> N >> A >> B;
    auto P = zawa::EnumeratePrimes<int>(N);
    std::vector<int> ans;
    ans.reserve(N / A + 1);
    for (int i = B ; i < std::ssize(P) ; i += A) ans.push_back(P[i]);
    std::cout << P.size() << ' ' << ans.size() << '\n';
    for (int i = 0 ; i < std::ssize(ans) ; i++) std::cout << ans[i] << (i + 1 == std::ssize(ans) ? '\n' : ' ');
}
