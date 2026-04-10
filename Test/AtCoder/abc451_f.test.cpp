// #define PROBLEM "https://atcoder.jp/contests/abc451/tasks/abc451_f"
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../Src/DataStructure/DisjointSetUnion/MonoidDSU.hpp"

/*
 * AtCoder Beginner Contest 451 F - Make Bipartite 3
 * https://atcoder.jp/contests/abc451/submissions/74800768
 */

#include <iostream>
#include <vector>
using namespace std;
struct M {
    using Element = pair<int,int>;
    static Element identity() {
        return {0,0};
    }
    static Element operation(Element L,Element R) {
        return {L.first+R.first,L.second+R.second};
    }
};
int eval(M::Element v) {
    return min(v.first,v.second);
}
void solve() {
    int N,Q;
    cin >> N >> Q;
    vector<typename M::Element> A(2*N);
    for (int i = 0 ; i < N ; i++)
        A[i] = {1,0};
    for (int i = N ; i < 2 * N ; i++)
        A[i] = {0,1};
    zawa::MonoidDSU<M> dsu(A);
    bool bip = true;
    int ans = 0;
    while (Q--) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        if (!dsu.same(u,v+N)) {
            ans -= eval(dsu[u]);
            ans -= eval(dsu[v+N]);
            dsu.merge(u,v+N);
            dsu.merge(v,u+N);
            ans += eval(dsu[u]);
            bip &= !dsu.same(u,u+N);
            bip &= !dsu.same(v,v+N);
        }
        cout << (bip ? ans : -1) << '\n';
    }
}
int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    solve();
#else
    int a,b;
    cin >> a >> b;
    cout << a + b << '\n';
#endif
}
