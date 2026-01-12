// #define PROBLEM "https://atcoder.jp/contests/abc385/tasks/abc385_g"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * AtCoder Beginner Contest 385 G - Counting Buildings
 * https://atcoder.jp/contests/abc385/submissions/72424554
 */

#include "../../Src/FPS/PolynomialProducts.hpp"
#include "../../Src/FPS/FPSNTTFriendly.hpp"
using namespace zawa;
#include "atcoder/modint"
using mint = atcoder::modint998244353;
using fps = FPSNTTFriendly<mint::mod()>;

#include <iostream>
#include <vector>
using namespace std;

int main() {
#ifdef ATCODER
    int N, K;
    cin >> N >> K;
    vector<fps> dp(N);
    dp[0] = {0, 1, 0};
    for (int i = 1 ; i < N ; i++) {
        dp[i].resize(3);
        dp[i][0] = dp[i][2] = 1;
        dp[i][1] = i - 1;
    }
    auto pd = PolynomialProducts(dp);
    cout << pd[N + K].val() << '\n';
#else
    cout << "Hello World\n";
#endif
}
