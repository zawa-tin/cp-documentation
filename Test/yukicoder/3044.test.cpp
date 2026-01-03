// #define PROBLEM "https://yukicoder.me/problems/no/3044"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/FPS/FPSNTTFriendly.hpp"
#include "../../Src/FPS/KthTerm.hpp"

/*
 * yukicoder No. 3044 よくあるカエルさん
 * https://yukicoder.me/submissions/1142771
 */

#include <iostream>
#include <vector>

#include "atcoder/modint"
using namespace zawa;
using mint = atcoder::modint998244353;
using fps = FPSNTTFriendly<mint::mod()>;

void solve() {
    int N, T, k, l;
    std::cin >> N >> T >> k >> l;
    fps C(T + 1);
    C[1] = mint::raw(k - 1) / mint::raw(6);
    C[2] = mint::raw(l - k) / mint::raw(6);
    C[T] = mint::raw(7 - l) / mint::raw(6);
    fps A(T);
    A[0] = 1;
    for (int n = 1 ; n < T ; n++) {
        for (int j = 1 ; j <= T and n - j >= 0 ; j++) {
            A[n] += C[j] * A[n - j];
        }
    }
    std::cout << KthTerm(N - 1, A, C).val() << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
    solve();
#else
    std::cout << "Hello World\n";
#endif
}
