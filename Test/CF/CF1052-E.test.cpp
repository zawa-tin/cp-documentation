// #define PROBLEM "https://codeforces.com/contest/2146/problem/E"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
/*
 * Codeforces Round 1052 (Div. 2) E - Yet Another MEX Problem
 * https://codeforces.com/contest/2146/submission/341030148
 */
#include "../../Src/DataStructure/SegmentTree/LazySegmentTree.hpp"
#include <iostream>
#include <algorithm>
using namespace std;
struct ADD {
    using Element = int;
    static Element identity() {
        return 0;
    }
    static Element operation(Element l, Element r) {
        return l + r;
    }
};
struct MAX {
    using Element = int;
    static Element identity() {
        return 0;
    }
    static Element operation(Element l, Element r) {
        return max(l, r);
    }
};
struct ACT {
    using ValueMonoid = MAX;
    using OperatorMonoid = ADD;
    static ValueMonoid::Element mapping(ValueMonoid::Element v, OperatorMonoid::Element o) {
        return v + o;
    }
};
void solve() {
    int N;
    cin >> N;
    zawa::LazySegmentTree<ACT> seg(N + 1);
    for (int i = 0 ; i < N ; i++) {
        int a;
        cin >> a;
        seg.assign(a, 0);
        seg.operation(0, a, 1);
        cout << seg.product(0, N + 1) << (i + 1 == N ? '\n' : ' ');
    }
}
int main() {
#ifdef ONLINE_JUDGE
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--)
        solve();
#else
    cout << "Hello World\n";
#endif
}
