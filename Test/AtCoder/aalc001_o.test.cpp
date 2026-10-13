// #define PROBLEM "https://atcoder.jp/contests/aalc001/tasks/aalc001_o"
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
/*
 * AAL Contest 001: Let's use segtree! O - 最小値
 * https://atcoder.jp/contests/aalc001/submissions/80016999
 */
#include "../../Src/DataStructure/SegmentTree/LazySegmentTree.hpp"
#include "../../Src/Algebra/Monoid/ConstantSquareMatrix.hpp"
#include "../../Src/Algebra/Monoid/ReverseOrder.hpp"
#include "../../Src/Algebra/Ring/UsualRing.hpp"
#include <array>
#include <vector>
#include <iostream>
using namespace std;
using namespace zawa;
struct VM {
   using Element = array<long long,3>;
   static Element identity() {
       return {0,0,0};
   }
   static Element operation(Element L, Element R) {
       for (int i = 0 ; i < 3 ; i++)
           L[i]+=R[i];
       return L;
   }
};
using OM=ConstantSquareMatrix<UsualRing<long long>,3>;
struct ACT {
   using ValueMonoid = VM;
   using OperatorMonoid = ReverseOrder<OM>;
   static ValueMonoid::Element mapping(const ValueMonoid::Element& v, const OperatorMonoid::Element& o) {
        return OM::leftAction(o,v);
   }
};
int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N,Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (auto& x : A)
        cin >> x;
    vector<vector<pair<int,int>>> query(N);
    for (int i = 0 ; i < Q ; i++) {
        int l,r;
        cin >> l >> r;
        l--; r--;
        query[r].push_back({l,i});
    }
    LazySegmentTree<ACT> seg(vector(N,VM::Element{0,0,1}));
    vector<long long> ans(Q);
    vector<int> stk;
    for (int i = 0 ; i < N ; i++) {
        while (stk.size() and A[stk.back()] >= A[i])
            stk.pop_back();
        {
            int l=stk.empty()?0:(stk.back()+1);
            OM::Element op=OM::Element{
                {0,0,A[i]},
                {0,1,0},
                {0,0,1}
            };
            seg.operation(l,i+1,op);
        }
        {
            OM::Element op=OM::Element{
                {1,0,0},
                {1,1,0},
                {0,0,1}
            };
            seg.operation(0,i+1,op);
        }
        for (auto [l,idx] : query[i]) 
            ans[idx]=seg.product(l,i+1)[1];
        stk.push_back(i);
    }
    for (auto i : ans)
        cout << i << '\n';
#else
    int a,b;
    cin >> a >> b;
    cout << a+b << '\n';
#endif
}
