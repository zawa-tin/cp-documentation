#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_xor_convolution"

#include "../../Src/Sequence/BitwiseXORConvolution.hpp"
#include "atcoder/modint"
using mint = atcoder::modint998244353;

#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int N;
    std::cin >> N;
    std::vector<mint> A(1 << N), B(1 << N);
    for (int i = 0 ; i < std::ssize(A) ; i++) {
        int v;
        std::cin >> v;
        A[i] = mint::raw(v);
    }
    for (int i = 0 ; i < std::ssize(B) ; i++) {
        int v;
        std::cin >> v;
        B[i] = mint::raw(v);
    }
    auto ans = zawa::BitwiseXORConvolution(A, B);
    for (int i = 0 ; i < std::ssize(ans) ; i++) std::cout << ans[i].val() << (i + 1 == std::ssize(ans) ? '\n' : ' ');
}
