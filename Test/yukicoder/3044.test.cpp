// #define PROBLEM "https://yukicoder.me/problems/no/3044"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/FPS/KthTerm.hpp"

/*
 * yukicoder No. 3044 よくあるカエルさん
 * https://yukicoder.me/submissions/1048080
 */

#include <iostream>
#include <vector>

#include "atcoder/modint"
using namespace zawa;
using mint = atcoder::modint998244353;

void solve() {
    int N, T, k, l;
    std::cin >> N >> T >> k >> l;
    std::vector<mint> C(T);
    C[0] = mint::raw(k - 1) / mint::raw(6);
    C[1] = mint::raw(l - k) / mint::raw(6);
    C[T - 1] = mint::raw(7 - l) / mint::raw(6);
    std::vector<mint> A(T);
    A[0] = 1;
    for (int n = 1 ; n < T ; n++) {
        for (int j = 1 ; j < T and n - j >= 0 ; j++) {
            A[n] += C[j - 1] * A[n - j];
        }
    }
    std::cout << KthTerm(N - 1, A, C, [](const auto& L, const auto& R) {
                if (L.empty() or R.empty()) return std::vector<mint>{};
                std::vector<mint> res(L.size() + R.size() - 1);
                for (size_t i{} ; i < L.size() ; i++) for (size_t j{} ; j < R.size() ; j++) {
                    res[i + j] += L[i] * R[j];
                }
                return res;
            }).val() << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
    solve();
#else
    std::cout << "Hello World\n";
#endif
}
