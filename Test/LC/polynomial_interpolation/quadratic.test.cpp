#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_interpolation"

#include "../../../Src/FPS/PolynomialInterpolation.hpp"
#include "atcoder/modint"
using mint = atcoder::modint998244353;

#include <iostream>
#include <vector>

using namespace zawa;
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<mint> xs(N), ys(N);
    for (int i = 0 ; i < N ; i++) {
        int x;
        cin >> x;
        xs[i] = mint::raw(x);
    }
    for (int i = 0 ; i < N ; i++) {
        int y;
        cin >> y;
        ys[i] = mint::raw(y);
    }
    auto ans = PolynomialInterpolation(xs, ys);
    for (int i = 0 ; i < N ; i++)
        cout << ans[i].val() << (i + 1 == N ? '\n' : ' ');
}
