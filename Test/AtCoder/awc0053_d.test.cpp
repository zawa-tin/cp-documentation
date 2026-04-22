// #define PROBLEM "https://atcoder.jp/contests/awc0053/tasks/awc0053_d"
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

/*
 * AtCoder Weekday Contest 0053 Beta D - フェンスの塗り替え
 * https://atcoder.jp/contests/awc0053/submissions/75170136
 */

#include "../../Src/DataStructure/Other/RangeAssigner.hpp"

#include <iostream>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
#ifdef ATCODER
    int N,M;
    cin >> N >> M;
    zawa::RangeAssigner<int,int> rg(N,0);
    while (M--) {
        int L,R,C;
        cin >> L >> R >> C;
        rg.assign(--L,R,C);
    }
    for (int i = 0 ; i < N ; i++)
        cout << rg[i] << (i + 1 == N ? '\n' : ' ');
#else
    int a,b;
    cin >> a >> b;
    cout << a + b << '\n';
#endif
}
