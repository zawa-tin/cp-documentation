// #define PROBLEM "https://atcoder.jp/contests/aalc001/tasks/aalc001_l"
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
/*
 * AAL Contest 001: Let's use segtree!
 * https://atcoder.jp/contests/aalc001/submissions/80554180
 */
#include "../../Src/Algebra/Group/SymmetricGroup.hpp"
#include "../../Src/DataStructure/SegmentTree/LazySegmentTree.hpp"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace zawa;
using namespace std;
struct Item {
    long long sum=0,pref=(long long)-1e18;
};
struct VM {
   using Element = array<Item,3>;
   static Element identity() {
       return {Item{},Item{},Item{}};
   }
   static Element operation(Element L, Element R) {
       for (int i = 0 ; i < 3 ; i++) {
           L[i].pref=max(L[i].pref,L[i].sum+R[i].pref);
           L[i].sum+=R[i].sum;
       }
       return L;
   }
};
struct ACT {
   using ValueMonoid = VM;
   using OperatorMonoid = SymmetricGroup<3>;
   static ValueMonoid::Element mapping(ValueMonoid::Element v, OperatorMonoid::Element o) {
       return OperatorMonoid::action(o,v);
   }
};
int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N,Q;
    cin >> N >> Q;
    vector<VM::Element> A(N);
    for (int i = 0 ; i < 3 ; i++) 
        for (int j = 0 ; j < N ; j++) {
            int x;
            cin >> x;
            A[j][i]={x,x};
        }
    LazySegmentTree<ACT> seg(move(A));
    vector<typename ACT::OperatorMonoid> ops(3);
    ops[0]=SymmetricGroup<3>({1,0,2});
    ops[1]=SymmetricGroup<3>({0,2,1});
    ops[2]=SymmetricGroup<3>({2,1,0});
    while (Q--) {
        int t;
        cin >> t;
        if (1 <= t and t <= 3) {
            int l,r;
            cin >> l >> r;
            l--;
            seg.operation(l,r,ops[t-1]);
        }
        else if (t == 4) {
            int i;
            cin >> i;
            i--;
            cout << seg.maxRight(i,[](const auto& v) { return v[0].pref <= 0; })+1 << '\n';
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
