// #define PROBLEM "https://atcoder.jp/contests/abc439/tasks/abc439_g"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * AtCoder Beginner Contest 439 G - Sugoroku 6
 * https://atcoder.jp/contests/abc439/submissions/72425293
 */

#include "../../Src/FPS/PowerProjection.hpp"
#include "../../Src/FPS/RationalSum.hpp"
#include "../../Src/FPS/FPSNTTFriendly.hpp"
using namespace zawa;
#include "atcoder/modint"
using mint = atcoder::modint998244353;
using fps = FPSNTTFriendly<mint::mod()>;

#include <iostream>
using namespace std;

int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N, M, L;
    cin >> N >> M >> L;
    const mint inv = mint::raw(M).inv();
    fps dice(N + 1);
    for (int i = 0 ; i < M ; i++) {
        int a;
        cin >> a;
        dice[a] = inv;
    }
    fps q{PowerProjection(N + 1, fps(N, 1), dice)};
    fps p(N + 1);
    for (int i = 0 ; i <= N ; i++)
        p[i] = 1 - q[i];
    for (int i = N ; i >= 1 ; i--)
        p[i] -= p[i - 1];
    vector<fps> num, den;
    for (int j = 1 ; j <= N ; j++) {
        if (q[j - 1] == mint{})
            break;
        num.push_back({p[j] * q[j - 1].pow(L - 1)});
        den.push_back({1, -q[j] * q[j - 1].inv()});
    }
    auto [a, b] = RationalSum(num, den);
    auto ans = a * b.inv(L);
    for (int i = 0 ; i < L ; i++)
        cout << ans[i].val() << '\n';
#else
    std::cout << "Hello World\n";
#endif
}
