// #define PROBLEM "https://atcoder.jp/contests/abc484/tasks/abc484_f"
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
/*
 * AtCoder Beginner Contest 484 F - Make them monochrome
 * https://atcoder.jp/contests/abc484/submissions/80933917
 */
#include "../../Src/Algebra/Monoid/SameMonoid.hpp"
#include "../../Src/DataStructure/SegmentTree/SegmentTree.hpp"
using namespace zawa;
#include <iostream>
#include <vector>
using namespace std;
using M=SameMonoid<int>;
M::Element gen(int x) {
    return x == -1 ? M::identity() : M::Element{x};
}
int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N,Q;
    cin >> N >> Q;
    vector<M::Element> A(N);
    for (auto& x : A) {
        int a;
        cin >> a;
        x=gen(a);
    }
    SegmentTree<M> seg(move(A));
    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i,x;
            cin >> i >> x;
            seg.assign(--i,gen(x));
        }
        else if (t == 2) {
            int l,r;
            cin >> l >> r;
            cout << (seg.product(--l,r).same()?"Yes\n":"No\n");
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
