#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Algebra/Ring/UsualRing.hpp"
#include "../../Src/LinearAlgebra/Matrix.hpp"
#include "atcoder/modint.hpp"

#include <iostream>

using namespace zawa;
using mint = atcoder::modint1000000007;
using M = Matrix<UsualRing<mint>>;

/*
 * ECR157-F Fancy Arrays
 * https://codeforces.com/contest/1895/submission/255171867
 */

mint solve() {
    int n, x, k; std::cin >> n >> x >> k;
    mint ans{};
    if (x > 0) {
        M A(x);
        for (int i{} ; i < x ; i++) {
            for (int j{} ; j < x ; j++) {
                if (std::abs(i - j) <= k) {
                    A[i][j] = mint::raw(1);
                }
            }
        }
        A = A.pow(n - 1);
        for (int i{} ; i < x ; i++) {
            for (int j{} ; j < x ; j++) {
                ans += A[i][j];
            }
        }
    }
    ans = mint{x + k} * mint{2 * k + 1}.pow(n - 1) - ans;
    return ans;
}

int main() {
#ifdef ONLINE_JUDGE
    SetFastIO();
    int t; std::cin >> t;
    while (t--) {
        std::cout << solve().val() << '\n';
    }
#else
    std::cout << "Hello World" << '\n';
#endif
}
