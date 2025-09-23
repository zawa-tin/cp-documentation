#define PROBLEM "https://judge.yosupo.jp/problem/lcm_convolution"

#include "../../Src/Number/LCMConvolution.hpp"
#include "atcoder/modint"
using mint = atcoder::modint998244353;

#include <iostream>
#include <vector>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<mint> a(N + 1), b(N + 1);
    for (int i = 1 ; i <= N ; i++) {
        int v;
        cin >> v;
        a[i] = v;
    }
    for (int i = 1 ; i <= N ; i++) {
        int v;
        cin >> v;
        b[i] = v;
    }
    auto ans = zawa::LCMConvolution(a, b);
    for (int i = 1 ; i < ssize(ans) ; i++)
        cout << ans[i].val() << (i + 1 == ssize(ans) ? '\n' : ' ');
}
