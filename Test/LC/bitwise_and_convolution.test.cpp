#define PROBLEM "bitwise_and_convolution"

#include "../../Src/Sequence/BitwiseAndConvolution.hpp"
#include "atcoder/modint"
using mint = atcoder::modint998244353;

#include <iostream>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<mint> a(1 << N), b(1 << N);
    for (int i = 0 ; i < (1 << N) ; i++) {
        int v;
        cin >> v;
        a[i] = v;
    }
    for (int i = 0 ; i < (1 << N) ; i++) {
        int v;
        cin >> v;
        b[i] = v;
    }
    auto ans = zawa::BitwiseAndConvolution(a, b);
    for (int i = 0 ; i < ssize(ans) ; i++)
        cout << ans[i].val() << (i + 1 == ssize(ans) ? '\n' : ' ');
}
