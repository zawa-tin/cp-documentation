#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../../Src/FPS/FPSNTTFriendly.hpp"
#include "../../../Src/FPS/PowerProjection.hpp"
#include "atcoder/modint"
using namespace zawa;
using mint = atcoder::modint998244353;
using fps = FPSNTTFriendly<mint::mod()>;

#include <iostream>
#include <random>
using namespace std;
mt19937 mt{random_device{}()};
vector<mint> naive(int M, const fps& W, const fps& F) {
    vector<mint> res(M);
    fps cur{1};
    for (int i = 0 ; i < M ; i++) {
        cur.resize(W.size());
        for (int j = 0 ; j < ssize(W) ; j++)
            res[i] += W[j] * cur[j];
        cur *= F;
    }
    return res;
}
void test(int MAXN, int MAXM, int MAXVAL, bool verify = true) {
    int N = mt() % MAXN + 1;
    int M = mt() % MAXM + 1;
    fps W(N), F(mt() % MAXN + 1);
    for (int i = 0 ; i < N ; i++)
        W[i] = mt() % MAXVAL;
    for (int i = 0 ; i < ssize(F) ; i++)
        F[i] = mt() % MAXVAL;
    auto ans = PowerProjection(M, W, F);
    if (verify) {
        auto nv = naive(M, W, F);
        if (ans != nv) {
            cerr << "fail" << endl;
            cerr << "W -> " << W << endl;
            cerr << "F -> " << F << endl;
            cerr << "ans: ";
            for (auto i : nv)
                cerr << i.val() << ' ';
            cerr << endl;
            cerr << "you: ";
            for (auto i : ans)
                cerr << i.val() << ' ';
            cerr << endl;
            exit(0);
        }
    }
}
int main() {
#ifdef DEBUG
    fps W{4, 4, 1, 0};
    fps F{0, 7, 1, 5};
    int M = 10;
    for (auto i : PowerProjection(M, W, F))
        cout << i.val() << ' ';
    cout << endl;
    for (auto i : naive(M, W, F))
        cout << i.val() << ' ';
    cout << endl;
#else
    // for (int i = (1 << 15) ; i-- ; )
    //     test(4, 10, 10);
    // cerr << "tiny end" << endl;
    // for (int i = (1 << 10) ; i-- ; )
    //     test(50, 50, mint::mod());
    // cerr << "small end" << endl;
    // for (int i = 0 ; i < (1 << 3) ; i++)
    //     test(3000, 3000, mint::mod());
    // cerr << "med end" << endl;
    for (int i = 0 ; i < (1 << 0) ; i++) {
        cerr << "test start" << endl;
        test(200000, 200000, mint::mod(), false);
    }
    cerr << "large end" << endl;
    // int A, B;
    // cin >> A >> B;
    // cout << A + B << '\n';
#endif
}
