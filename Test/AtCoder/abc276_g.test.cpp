// #define PROBLEM "https://atcoder.jp/contests/abc276/tasks/abc276_g"
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
/*
 * AtCoder Beginner Contest 276 G - Count Sequence
 * https://atcoder.jp/contests/abc276/submissions/80353697
 */
#include "../../Src/SparseFPS/PowerProduct.hpp"
#include "atcoder/modint"
using mint=atcoder::modint998244353;
#include <iostream>
using namespace zawa;
using namespace std;
using fps=SparseFPS::Series<int,mint>;
int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N,M;
    cin >> N >> M;
    fps num,den;
    num.emplace_back(1,1);
    num.emplace_back(2,1);
    den.emplace_back(0,1);
    den.emplace_back(3,-1);
    auto f=SparseFPS::PowProduct(num,den,N-1,-(N-1),M+1);
    for (int i = 0 ; i < 2 ; i++)
        for (int j = 1 ; j <= M ; j++)
            f[j]+=f[j-1];
    cout << f[M].val() << '\n';
#else
    int a,b;
    cin >> a >> b;
    cout << a+b << '\n';
#endif
}
