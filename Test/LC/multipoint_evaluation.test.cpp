#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation"

#include "../../Src/FPS/FPSNTTFriendly.hpp"
#include "../../Src/FPS/MultipointEvaluation.hpp"
using namespace zawa;

#include <iostream>
#include <vector>
using namespace std;
using mint = atcoder::modint998244353;
using fps = FPSNTTFriendly<mint::mod()>;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N,M;
    cin >> N >> M;
    fps f(N);
    std::vector<mint> x(M);
    for (int i = 0 ; i < N ; i++) {
        int c;
        cin >> c;
        f[i] = c;
    }
    for (int i = 0 ; i < M ; i++) {
        int p;
        cin >> p;
        x[i] = p;
    }
    auto ans = MultipointEvaluation(f,x);
    for (int i = 0 ; i < M ; i++)
        cout << ans[i].val() << (i + 1 == M ? '\n' : ' ');
}
