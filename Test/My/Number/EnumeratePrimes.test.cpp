#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../../Src/Number/EratosthenesSieve.hpp"
#include "../../../Src/Number/EnumeratePrimes.hpp"

#include <random>

std::vector<int> EratosEnumerate(int N) {
    std::vector<int> ans;
    for (auto v : zawa::EratosthenesSieve(N).enumeratePrimes(N)) {
        ans.push_back(static_cast<int>(v));
    }
    return ans;
}

bool test(int N) {
    return EratosEnumerate(N) == zawa::EnumeratePrimes<int>(N);
}

#include <cassert>
#include <iostream>
#include <random>

int main() {
    // small
    for (int N = 1 ; N <= 500 ; N++) assert(test(N));
    std::mt19937 mt{std::random_device{}()};
    for (int t = 0 ; t < 15 ; t++) {
        int N = mt() % (int)1e7 + 1;
        assert(test(N));
    }
    std::cout << "Hello World\n";
}
