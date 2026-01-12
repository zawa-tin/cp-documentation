// #define PROBLEM "https://atcoder.jp/contests/abc345/tasks/abc345_g"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * AtCoder Beginner Contest 345 G - Sugoroku 5
 * https://atcoder.jp/contests/abc345/submissions/72422855
 */

#include "../../Src/FPS/FPSNTTFriendly.hpp"
#include "../../Src/FPS/PowerProjection.hpp"
using namespace zawa;
#include "atcoder/modint"
using mint = atcoder::modint998244353;
using fps = FPSNTTFriendly<mint::mod()>;

#include <iostream>
using namespace std;

int main() {
#ifdef ATCODER
    int N, K;
    cin >> N >> K;
    fps dice(K + 1, mint::raw(K).inv()), ngs(N, 1);
    dice[0] = 0;
    auto pws = PowerProjection(N + 1, ngs, dice);
    for (int i = 0 ; i <= N ; i++)
        pws[i] = 1 - pws[i];
    for (int i = N ; i >= 1 ; i--)
        pws[i] -= pws[i - 1];
    for (int i = 1 ; i <= N ; i++)
        cout << pws[i].val() << '\n';
#else
    std::cout << "Hello World\n";
#endif
}
