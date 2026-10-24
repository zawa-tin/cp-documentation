#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series_sparse"
#include "../../Src/SparseFPS/Inverse.hpp"
using namespace zawa;
#include "atcoder/modint"
using mint=atcoder::modint998244353;
#include <iostream>
using namespace std;
using fps=SparseFPS::Series<int,mint>;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N,K;
    cin >> N >> K;
    fps f(K);
    for (int i = 0 ; i < K ; i++) {
        int a,b;
        cin >> a >> b;
        f[i]={a,mint::raw(b)};
    }
    auto ans=SparseFPS::Inv(move(f),N);
    for (int i = 0 ; i < N ; i++)
        cout << ans[i].val() << (i+1==N?'\n':' ');
}
