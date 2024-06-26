#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2706"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Number/PrimeFactorize.hpp"

#include <iostream>
#include <numeric>

using namespace zawa;

int main() {
    SetFastIO(); 
    int P, Q;
    std::cin >> P >> Q;
    Q /= std::gcd(P, Q);
    int ans{1};
    for (const auto& data : PrimeFactorize((unsigned)Q)) {
        // auto [f, exp]{(std::pair<unsigned, u32>)data)};
        ans *= (int)data.factor();
    }
    std::cout << ans << '\n';
}
