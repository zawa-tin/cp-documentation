#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/3568"
#include "../../Src/Sequence/BitwiseXORConvolution.hpp"
#include "atcoder/modint"
using mint=atcoder::modint998244353;
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
int main() {
    int N,K;
    cin >> N >> K;
    int M=1;
    while (M <= N)
        M<<=1;
    vector<mint> A(M);
    fill(A.begin(),A.begin()+N+1,mint::raw(1));
    auto powed=zawa::BitwiseXORConvolutionPower(std::move(A),K);
    mint ans=0;
    for (int i = 0 ; i < M ; i++)
        ans+=mint::raw(i)*powed[i];
    cout << ans.val() << '\n';
}
