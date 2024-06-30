#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Number/BinomalCoefficients.hpp"

#include <algorithm>
#include <iostream>

using namespace zawa;

int main() {
    int T, m;
    std::cin >> T >> m;
    BinomalCoefficients comb(m);
    comb.reserve(std::min(m, 10000000));
    while (T--) {
        int n, k;
        std::cin >> n >> k;
        std::cout << comb.C(n, k).val() << '\n';
    }
}
