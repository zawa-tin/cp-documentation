#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_interpolation"
#include "../../../Src/FPS/FPSNTTFriendly.hpp"
#include "../../../Src/FPS/PolynomialInterpolationFast.hpp"
#include "atcoder/modint"
using mint=atcoder::modint998244353;
using fps=zawa::FPSNTTFriendly<mint::mod()>;
#include <iostream>
#include <vector>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<mint> xs(N),ys(N);
    for (mint& a : xs) {
        int v;
        cin >> v;
        a=mint::raw(v);
    }
    for (mint& a : ys) {
        int v;
        cin >> v;
        a=mint::raw(v);
    }
    cout << zawa::PolynomialInterpolationFast(move(xs),move(ys)) << '\n';
}
