// #define PROBLEM "https://atcoder.jp/contests/arc082/tasks/arc082_d"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * AtCoder Regular Contest 082 F - Sandlgass
 * https://atcoder.jp/contests/arc082/submissions/75030785
 */

#include "../../Src/Sequence/CompressedSequence.hpp"
#include "../../Src/DataStructure/SegmentTree/LazySegmentTree.hpp"
using namespace zawa;
#include <algorithm>
#include <iostream>
#include <vector>
#include <variant>
#include <tuple>
#include <iterator>
#include <ranges>
using namespace std;
struct VM {
   using Element = pair<long long,long long>;
   static Element identity() {
       return {-(long long)2e9,(long long)2e9};
   }
   static Element operation(Element L, Element R) {
       L.first = max(L.first,R.first);
       L.second = min(L.second,R.second);
       return L;
   }
};
using Assign = long long;
using Add = tuple<long long,bool,long long>;
using Item = variant<Assign,Add>;
Add normalize(Add v) {
    if (!get<1>(v)) {
        get<0>(v) += get<2>(v);
        get<2>(v) = 0;
    }
    return v;
}
struct OM {
    using Element = Item;
    static Element identity() {
        return tuple{0LL,false,0LL};
    }
    static Element operation(Element L, Element R) {
        if (holds_alternative<Assign>(R))
            return R;
        if (holds_alternative<Assign>(L)) {
            long long v = get<Assign>(L);
            auto [p,m,s] = get<Add>(R);
            v += p;
            if (m)
                v *= -1;
            v += s;
            return v;
        }
        auto [l1,m1,r1] = normalize(get<Add>(L));
        auto [l2,m2,r2] = normalize(get<Add>(R));
        if (!m1) {
            l1 += l2;
            m1 = m2;
            r1 = r2;
            return Add{l1,m1,r1};
        }
        if (!m2) {
            r1 += l2;
            return Add{l1,m1,r1};
        }
        return Add{l1-r1-l2+r2,false,0LL};
    }
};
struct ACT {
    using ValueMonoid = VM;
    using OperatorMonoid = OM;
    static ValueMonoid::Element mapping(ValueMonoid::Element v, OperatorMonoid::Element o) {
        if (holds_alternative<Add>(o)) {
            auto [l,m,r] = get<Add>(o);
            v.first += l;
            v.second += l;
            if (m) {
                v.first *= -1;
                v.second *= -1;
            }
            v.first += r;
            v.second += r;
            if (v.first < v.second)
                swap(v.first,v.second);
            return v;
        }
        else
            return {get<Assign>(o),get<Assign>(o)};
    }
};
int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int X,K;
    cin >> X >> K;
    vector<int> R(K);
    for (auto& x : R)
        cin >> x;
    int Q;
    cin >> Q;
    vector<int> T(Q);
    vector<long long> A(Q);
    for (int i = 0 ; i < Q ; i++)
        cin >> T[i] >> A[i];
    CompressedSequence<long long> comp{A};
    const int n = ssize(comp);
    LazySegmentTree<ACT> seg([&]() {
                vector<pair<long long,long long>> res(n);
                for (int i = 0 ; i < n ; i++)
                    res[i] = {comp.inverse(i),comp.inverse(i)};
                return res;
            }());
    vector<tuple<int,int,int>> event;
    event.reserve(K+Q);
    for (int i = 0 ; i < K ; i++)
        event.push_back({R[i],0,i});
    for (int i = 0 ; i < Q ; i++)
        event.push_back({T[i],1,i});
    ranges::sort(event);
    bool sign = 0;
    vector<long long> ans(Q);
    int last_upd = 0;
    for (auto [time,type,idx] : event) {
        if (type == 0) {
            if (!sign) { // 広義単調増加
                auto it = seg.maxRight(0,[&](const VM::Element& v) { return v.first <= time - last_upd; });
                seg.operation(0,it,Assign{0LL});
                seg.operation(it,n,Add{-(time-last_upd),false,0LL});
            }
            else { // 減少
                auto it = seg.minLeft(n,[&](const VM::Element& v) { return v.first <= time - last_upd; });
                seg.operation(it,n,Assign{0LL});
                seg.operation(0,it,Add{-(time-last_upd),false,0LL});
            }
            seg.operation(0,n,Add{0LL,true,X});
            last_upd = time;
            sign = !sign;
            // for (int i = 0 ; i < n ; i++)
            //     cout << seg[i] << (i + 1 == n ? '\n' : ' ');
        }
        else if (type == 1) {
            long long up = seg[comp.at(A[idx])].first;
            // assert(0 <= up and up <= X);
            up = max(0LL,up-(time-last_upd));
            if (sign)
                ans[idx] = X - up;
            else
                ans[idx] = up;
        }
        else
            assert(0);
    }
    for (long long a : ans)
        cout << a << '\n';
#else
    cout << "Hello World\n";
#endif
}
