// #define PROBLEM "https://atcoder.jp/contests/abc266/tasks/abc266_h"
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
/*
 * AtCoder Beginner Contest 266 Ex - Snuke Panic
 * https://atcoder.jp/contests/abc266/submissions/75815775
 */
#include "../../Src/DataStructure/Wavelet/RectangleAggregation.hpp"
#include "../../Src/DataStructure/SegmentTree/SegmentTree.hpp"
using namespace zawa;
#include <algorithm>
#include <iostream>
#include <numeric>
#include <utility>
#include <ranges>
#include <vector>
using namespace std;
struct MAX {
    using Element = long long;
    static Element identity() {
        return -1;
    }
    static Element operation(Element L,Element R) {
        return max(L,R);
    }
};
int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<int> T(N),X(N),Y(N),A(N);
    for (int i = 0 ; i < N ; i++)
        cin >> T[i] >> X[i] >> Y[i] >> A[i];
    T.push_back(0);
    X.push_back(0);
    Y.push_back(0);
    vector<pair<long long,long long>> P(N+1);
    for (int i = 0 ; i < N+1 ; i++)
        P[i] = {(long long)X[i]+Y[i]-T[i],(long long)-X[i]+Y[i]-T[i]};
    RectangleAggregation RA{P};
    vector<int> ord(N);
    iota(ord.begin(), ord.end(), 0);
    ranges::sort(ord, [&](int i, int j) -> bool {
        if (Y[i] != Y[j])
            return Y[i] < Y[j];
        else
            return T[i] < T[j];
    });
    vector<SegmentTree<MAX>> seg(RA.height());
    for (int i = 0 ; i < (int)RA.height() ; i++)
        seg[i] = SegmentTree<MAX>(RA.width());
    for (auto [x,y] : RA.point(N))
        seg[x].assign(y,0);
    long long ans = 0;
    for (int i : ord) {
        long long v = MAX::identity();
        for (auto [h,l,r] : RA.rectangle(P[i].first,P[i].second,(long long)1e18,(long long)1e18))
            v = max(v,seg[h].product(l,r));
        if (v == MAX::identity())
            continue;
        v += A[i];
        ans = max(ans,v);
        for (auto [x,y] : RA.point(i))
            seg[x].operation(y,v);
    }
    cout << ans << '\n';
#else
    int a,b;
    cin >> a >> b;
    cout << a+b << '\n';
#endif
}
