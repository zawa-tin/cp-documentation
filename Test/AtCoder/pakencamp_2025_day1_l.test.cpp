// #define PROBLEM "https://atcoder.jp/contests/pakencamp-2025-day1/tasks/pakencamp_2025_day1_l"
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

/*
 * パ研合宿2025 第1日「SpeedRun」 L- Typical Addition Problem
 * https://atcoder.jp/contests/pakencamp-2025-day1/submissions/75681053
 */

#include "../../Src/DataStructure/SegmentTree/DualSegmentTree.hpp"
#include "../../Src/Algebra/Group/AdditiveGroup.hpp"
#include "../../Src/Algebra/Monoid/MonoidAction.hpp"
using namespace zawa;

#include <cassert>
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
    vector<long long> A(N),B(N);
    for (auto& x : A)
        cin >> x;
    for (auto& x : B)
         cin >> x;
    DualSegmentTree<AddSelfAction<AdditiveGroup<long long>>,long long,true> seg(N);
    while (Q--) {
        int T;
        cin >> T;
        if (T == 1) {
            int p,x;
            cin >> p >> x;
            p--;
            A[p] += seg[p]*B[p];
            seg.assignOperator(p,0);
            B[p] = x;
        }
        else if (T == 2) {
            int l,r;
            cin >> l >> r;
            seg.operation(--l,r,1);
        }
        else if (T == 3) {
            int p;
            cin >> p;
            p--;
            A[p] += seg[p]*B[p];
            seg.assignOperator(p,0);
            cout << A[p] << '\n';
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
