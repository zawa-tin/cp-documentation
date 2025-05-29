// #define PROBLEM "https://atcoder.jp/contests/arc185/tasks/arc185_e"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * AtCoder Regular Contest 185 - E Adjacent GCD
 * https://atcoder.jp/contests/arc185/submissions/66241326
 */

#include "../../Src/Number/LinearSieve.hpp"
using namespace zawa;
#include "atcoder/modint"
using mint = atcoder::modint998244353;

#include <iostream>
#include <vector>
#include <numeric>

const int MAX = 100000;
int N, A[500050];
int main() {
#ifdef ATCODER
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::cin >> N;
    for (int i = 0 ; i < N ; i++) std::cin >> A[i];
    LinearSieve siv{MAX + 1};
    std::vector<mint> x(MAX + 1), a(MAX + 1);
    // 重みの列Y
    std::iota(x.begin(), x.end(), mint::raw(0));
    // mobius transformでXを得る
    for (int i = 1 ; i <= MAX ; i++) if (siv.isPrime(i)) {
        for (int j = MAX / i ; j >= 1 ; j--) x[i * j] -= x[j];
    }
    std::vector<mint> p2(N, mint::raw(1));
    for (int i = 1 ; i < N ; i++) p2[i] *= p2[i - 1] * mint::raw(2);
    mint ans = 0;
    for (int i = 0 ; i < N ; i++, ans *= mint::raw(2)) {
        for (int d : siv.divisor<int>(A[i])) {
            ans += x[d] * a[d];
            a[d] += p2[i];
        }
        std::cout << ans.val() << '\n';
    }
#else
    std::cout << "Hello World\n";
#endif
}
