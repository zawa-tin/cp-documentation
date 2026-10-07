// #define PROBLEM "https://atcoder.jp/contests/abc429/tasks/abc429_f"
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
/*
 * AtCoder Beginner Contest 429 F - Shortest Path Query
 * https://atcoder.jp/contests/abc429/submissions/79844847
 */
#include "../../Src/Algebra/Ring/MinPlusSemiring.hpp"
#include "../../Src/Algebra/Monoid/StaticSquareMatrix.hpp"
#include "../../Src/DataStructure/SegmentTree/SegmentTree.hpp"
#include <cassert>
#include <iostream>
#include <string>
using namespace std;
using namespace zawa;
const int INF=(int)1e9;
using M = SquareMatrix<MinPlusSemiring<int,INF>,3>;
M convert(string S) {
    assert(ssize(S)==3);
    M res = M::zero();
    res[0][0]=S[0]=='.'?0:INF;
    res[1][1]=S[1]=='.'?0:INF;
    res[2][2]=S[2]=='.'?0:INF;
    res[0][1]=res[1][0]=(S[0]=='.' and S[1]=='.')?1:INF;
    res[1][2]=res[2][1]=(S[1]=='.' and S[2]=='.')?1:INF;
    res[0][2]=res[2][0]=(S[0]=='.' and S[1]=='.' and S[2]=='.') ?2:INF;
    return res;
}
int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector S(N,string(3,'_'));
    for (int i = 0 ; i < 3 ; i++)
        for (int j = 0 ; j < N ; j++)
            cin >> S[j][i];
    vector<M> A(N);
    for (int i = 0 ; i < N ; i++)
        A[i]=convert(S[i]);
    SegmentTree<M> seg(A);
    int Q;
    cin >> Q;
    while (Q--) {
        int r,c;
        cin >> r >> c;
        r--; c--;
        S[c][r]^='.'^'#';
        A[c]=convert(S[c]);
        seg.assign(c,A[c]);
        auto pd=seg.product(0,N);
        cout << (pd[0][2]==INF?-1:pd[0][2]+N-1) << '\n';
    }
#else
    int a,b;
    cin >> a >> b;
    cout << a+b << '\n';
#endif
}
