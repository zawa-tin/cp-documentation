#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Number/EratosthenesSieve.hpp"

#include <iostream>

using namespace zawa;

int main() {

    // std::cin.tie(nullptr);
    // std::ios::sync_with_stdio(false);

    u32 N, A, B;
    std::cin >> N >> A >> B;

    std::vector<u32> P = 
        EratosthenesSieve(N).enumeratePrimes(N);

    std::vector<i32> ans{};
    for (u32 i = 0 ; A * i + B < P.size() ; i++) {
        ans.push_back(P[A * i + B]);
    }

    std::cout << P.size() << ' ' << ans.size() << std::endl;
    for (u32 i = 0 ; i < ans.size() ; i++) {
        std::cout << ans[i] << (i + 1 == ans.size() ? '\n' : ' ');
    }
}
