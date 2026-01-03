#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_taylor_shift"

#include "../../Src/FPS/FPSNTTFriendly.hpp"
#include "../../Src/FPS/PolynomialTaylorShift.hpp"
using namespace zawa;

#include "atcoder/modint"
using mint = atcoder::modint998244353;
using fps = FPSNTTFriendly<mint::mod()>;

#include <iostream>
#include <vector>
using namespace std;

int main() {
    std::cin.tie(nullptr);    
    std::cout.tie(nullptr);    
    std::ios::sync_with_stdio(false);
    int N, c;
    std::cin >> N >> c;
    fps A(N);
    for (int i = 0 ; i < N ; i++) {
        int a;
        std::cin >> a;
        A[i] = mint::raw(a);
    }
    auto B = PolynomialTaylorShift(A, c);
    for (int i = 0 ; i < N ; i++) 
        std::cout << B[i].val() << (i + 1 == N ? '\n' : ' ');
}
