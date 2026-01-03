// #define PROBLEM "https://atcoder.jp/contests/abc215/tasks/abc215_g"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * AtCoder Beginner Contest 215 G - Colorful Candies 2
 * https://atcoder.jp/contests/abc215/submissions/72163857
 */

#include "../../Src/FPS/FPSNTTFriendly.hpp"
#include "../../Src/FPS/PolynomialTaylorShift.hpp"
using namespace zawa;

#include "atcoder/modint"
using mint = atcoder::modint998244353;
using fps = FPSNTTFriendly<mint::mod()>;

#include <iostream>
#include <vector>
#include <algorithm>
int N, C[50050];
int main() {
#ifdef ATCODER
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::cin >> N;
    for (int i = 0 ; i < N ; i++) 
        std::cin >> C[i];
    std::ranges::sort(C, C + N);
    int cnt = 0;
    fps a(N + 1);
    for (int i = 0, j = 0 ; i < N ; i = j) {
        while (j < N and C[i] == C[j]) 
            j++;
        a[N - (j - i)]++;
        cnt++;
    }
    auto b = zawa::PolynomialTaylorShift(a, 1);
    std::vector<mint> fact(N + 1, 1), invfact(N + 1);
    for (int i = 1 ; i <= N ; i++) 
        fact[i] = fact[i - 1] * mint::raw(i);
    invfact[N] = fact[N].inv();
    for (int i = N ; i >= 1 ; i--) 
        invfact[i - 1] = invfact[i] * mint::raw(i);
    for (int k = 1 ; k <= N ; k++) {
        mint ans = mint{cnt} - b[k] * invfact[N] * fact[k] * fact[N - k];
        std::cout << ans.val() << '\n';
    }
#else
    std::cout << "Hello World\n";
#endif
}
