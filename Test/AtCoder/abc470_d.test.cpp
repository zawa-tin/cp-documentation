// #define PROBLEM "https://atcoder.jp/contests/abc470/tasks/abc470_d"
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
/*
 * AtCoder Beginner Contest 470 D - Inverse and Swap
 * https://atcoder.jp/contests/abc470/submissions/80553925
 */
#include "../../Src/Algebra/Group/SymmetricGroup.hpp"
#include <iostream>
#include <vector>
using namespace std;
int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N,Q;
    cin >> N >> Q;
    vector<int> P(N);
    for (int& p : P) {
        cin >> p;
        p--;
    }
    zawa::SymmetricGroup sym{P};
    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x,y;
            cin >> x >> y;
            sym.swap(--x,--y);
        }
        else if (t == 2)
            sym.invert();
        else
            assert(0);
    }
    for (int i = 0 ; i < N ; i++)
        cout << sym[i]+1 << (i+1==N?'\n':' ');
#else
    int a,b;
    cin >> a >> b;
    cout << a+b << '\n';
#endif
}
