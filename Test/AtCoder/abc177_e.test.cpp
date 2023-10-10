#define PROBLEM "https://atcoder.jp/contests/abc177/tasks/abc177_e"

#include "../../Src/Number/LinearSieve.hpp"

#include <iostream>
#include <numeric>
#include <unordered_set>

const int N{ 1000100 };

int main() {
    int n; std::cin >> n;
    zawa::LinearSieve siv(N);
    int setGCD{};
    std::unordered_set<int> divisors;
    bool pairwise{true};
    for (int _{} ; _ < n ; _++) {
        int a; std::cin >> a;
        setGCD = std::gcd(setGCD, a);
        for (auto p : siv.factorize(a)) if (p.factor() > 1) {
            pairwise &= divisors.find(p.factor()) == divisors.end();
            divisors.emplace(p.factor());
        }
    }
    if (pairwise) {
        std::cout << "pairwise coprime" << std::endl;
    }
    else if (setGCD == 1) {
        std::cout << "setwise coprime" << std::endl;
    }
    else {
        std::cout << "not coprime" << std::endl;
    }

}
