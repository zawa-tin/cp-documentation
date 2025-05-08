#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_taylor_shift"

#include "../../Src/FPS/PolynomialTaylorShift.hpp"

#include "atcoder/modint"
#include "atcoder/convolution"
using mint = atcoder::modint998244353;

#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr);    
    std::cout.tie(nullptr);    
    std::ios::sync_with_stdio(false);
    int N, c;
    std::cin >> N >> c;
    std::vector<mint> A(N);
    for (int i = 0 ; i < N ; i++) {
        int a;
        std::cin >> a;
        A[i] = mint::raw(a);
    }
    auto B = zawa::PolynomialTaylorShift(A, c, atcoder::convolution<mint>);
    for (int i = 0 ; i < N ; i++) std::cout << B[i].val() << (i + 1 == N ? '\n' : ' ');
}
