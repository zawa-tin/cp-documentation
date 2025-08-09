#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"

#include "../../Src/FPS/FPSInverse.hpp"

#include <iostream>
#include <vector>

#include "atcoder/modint"
using mint = atcoder::modint998244353;
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<mint> A(N);
    for (int i = 0 ; i < N ; i++) {
        int a;
        cin >> a;
        A[i] = mint::raw(a);
    }
    auto ans = zawa::FPSInverse(A, N);
    for (int i = 0 ; i < N ; i++) cout << ans[i].val() << (i + 1 == N ? '\n' : ' ');
}
