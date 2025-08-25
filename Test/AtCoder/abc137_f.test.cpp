// #define PROBLEM "https://atcoder.jp/contests/abc137/tasks/abc137_f"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * AtCoder Beginner Contest 137 F - Polynomial Construction
 * https://atcoder.jp/contests/abc137/submissions/68802452
 */

#include "../../Src/FPS/PolynomialInterpolation.hpp"
#include "atcoder/modint"
using mint = atcoder::modint;

#include <iostream>
#include <vector>

using namespace zawa;
using namespace std;

int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    mint::set_mod(N);
    vector<mint> xs(N), ys(N);
    for (int i = 0 ; i < N ; i++) 
        xs[i] = mint::raw(i);
    for (int i = 0 ; i < N ; i++) {
        int y;
        cin >> y;
        ys[i] = mint::raw(y);
    }
    auto ans = PolynomialInterpolation(xs, ys);
    for (int i = 0 ; i < N ; i++)
        cout << ans[i].val() << (i + 1 == N ? '\n' : ' ');
#else
    cout << "Hello World\n";
#endif
}
