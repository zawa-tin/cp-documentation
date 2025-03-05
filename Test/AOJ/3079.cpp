#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/3079"

#include "../../Src/FPS/KthTerm.hpp"
#include "atcoder/modint"

#include <iostream>
using namespace zawa;
using mint = atcoder::modint1000000007;

int main() {
    long long N;
    std::cin >> N; 
    std::vector<mint> A{1, 0, 1};
    std::vector<mint> C{0, 1, 1};
    std::cout << KthTerm(N, A, C, [](const auto& L, const auto& R) {
                if (L.empty() or R.empty()) return std::vector<mint>{};
                std::vector<mint> res(L.size() + R.size() - 1);
                for (size_t i{} ; i < L.size() ; i++) for (size_t j{} ; j < R.size() ; j++) {
                    res[i + j] += L[i] * R[j];
                }
                return res;
            }).val() << '\n';
}
