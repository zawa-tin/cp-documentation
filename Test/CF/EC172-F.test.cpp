// #define PROBLEM "https://codeforces.com/contest/2042/problem/F"
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../Src/Algebra/Ring/MaxPlusSemiring.hpp"
#include "../../Src/Algebra/Monoid/StaticSquareMatrix.hpp"
#include "../../Src/DataStructure/SegmentTree/SegmentTree.hpp"
/*
 * Educational Codeforces Round 172 (Rated for Div. 2) F. Two Subarrays
 * https://codeforces.com/contest/2042/submission/393514797
 */
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
using namespace zawa;
const long long INF=(long long)-1e18;
using M=SquareMatrix<MaxPlusSemiring<long long,INF>,5>;
M convert(int a,int b) {
    return M{
        {0,a+b,(long long)a+b+b,INF,INF},
        {INF,a,a+b,INF,INF},
        {INF,INF,0,a+b,(long long)a+b+b},
        {INF,INF,INF,a,a+b},
        {INF,INF,INF,INF,0}
    };
}
int main() {
#ifdef ONLINE_JUDGE
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<int> A(N),B(N);
    for (auto& x : A)
        cin >> x;
    for (auto& x : B)
        cin >> x;
    SegmentTree<M> seg([&]() {
                vector<M> res(N);
                for (int i = 0 ; i < N ; i++)
                    res[i]=convert(A[i],B[i]);
                return res;
            }());
    int Q;
    cin >> Q;
    while (Q--) {
        int t;
        cin >> t;
        if (t == 1 or t == 2) {
            int p,x;
            cin >> p >> x;
            p--;
            if (t == 1)
                A[p]=x;
            else
                B[p]=x;
            seg.assign(p,convert(A[p],B[p]));
        }
        else if (t == 3) {
            int l,r;
            cin >> l >> r;
            cout << seg.product(--l,r)[0][4] << '\n';
        }
        else
            assert(0);
    }
#else
    int a,b;
    cin >> a >> b;
    cout << a+b << '\n';
#endif
}
