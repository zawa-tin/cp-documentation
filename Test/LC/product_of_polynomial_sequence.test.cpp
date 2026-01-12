#define PROBLEM "https://judge.yosupo.jp/problem/product_of_polynomial_sequence"

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
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<fps> F(N);
    for (auto& f : F) {
        int d;
        cin >> d;
        f.resize(d + 1);
        for (auto& v : f) {
            int a;
            cin >> a;
            v = a;
        }
    }
    cout << PolynomialProducts(F) << '\n';
}
