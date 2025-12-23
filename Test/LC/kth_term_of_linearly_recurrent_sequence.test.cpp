#define PROBLEM "https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence"

#include "../../Src/FPS/FPSNTTFriendly.hpp"
#include "../../Src/FPS/KthTerm.hpp"
using namespace zawa;
#include "atcoder/modint"

using mint = atcoder::modint998244353;
using fps = FPSNTTFriendly<mint::mod()>;

#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int d;
    long long k;
    cin >> d >> k;
    fps A(d), C(d + 1);
    for (int i = 0 ; i < d ; i++) {
        int v;
        cin >> v;
        A[i] = v;
    }
    for (int i = 1 ; i <= d ; i++) {
        int v;
        cin >> v;
        C[i] = v;
    }
    cout << KthTerm(k, A, C).val() << '\n';
}
