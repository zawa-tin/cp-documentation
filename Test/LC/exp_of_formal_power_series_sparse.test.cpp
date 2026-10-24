#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series_sparse"
#include "../../Src/SparseFPS/Exp.hpp"
#include "atcoder/modint"
using mint=atcoder::modint998244353;
#include <iostream>
using namespace std;
using namespace zawa;
using fps=SparseFPS::Series<int,mint>;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N,K;
    cin >> N >> K;
    fps f(K);
    for (auto& t : f) {
        int i,a;
        cin >> i >> a;
        t={i,mint::raw(a)};
    }
    auto ans=Exp(move(f),N);
    for (int i = 0 ; i < N ; i++)
        cout << ans[i].val() << (i+1==N?'\n':' ');
}
