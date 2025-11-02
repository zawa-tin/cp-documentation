// #define PROBLEM "https://atcoder.jp/contests/abc430/tasks/abc430_g"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
    AtCoder Beginner Contest 430 G - Range Set Modifying Query
    https://atcoder.jp/contests/abc430/submissions/70642359
 */

#include "../../Src/DataStructure/Other/RangeAssigner.hpp"
#include "../../Src/DataStructure/SegmentTree/LazySegmentTree.hpp"
#include "../../Src/Algebra/Group/AdditiveGroup.hpp"
using namespace zawa;
#include <cassert>
#include <iostream>
#include <utility>
using namespace std;
struct MAX {
    using Element = pair<int, int>;
    static Element identity() {
        return {-1, 0};
    }
    static Element operation(Element L, Element R) {
        if (L.first < R.first)
            swap(L, R);
        if (L.first == R.first)
            L.second += R.second;
        return L;
    }
};
struct ACT {
    using ValueMonoid = MAX;
    using OperatorMonoid = AdditiveGroup<int>;
    static ValueMonoid::Element mapping(ValueMonoid::Element v, OperatorMonoid::Element o) {
        v.first += o;
        return v;
    }
};
int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N, Q;
    cin >> N >> Q;
    vector rg(60, RangeAssigner<int, bool>(N, false));
    LazySegmentTree<ACT> seg(vector<MAX::Element>(N, {0, 1}));
    while (Q--) {
        int T, L, R;
        cin >> T >> L >> R;
        L--;
        if (T == 1) {
            int x;
            cin >> x;
            for (auto [l, r, v] : rg[x - 1].assign(L, R, true)) {
                if (v == false)
                    seg.operation(l, r, 1);
            }
        }
        else if (T == 2) {
            int x;
            cin >> x;
            for (auto [l, r, v] : rg[x - 1].assign(L, R, false)) {
                if (v == true)
                    seg.operation(l, r, -1);
            }
        }
        else if (T == 3) {
            auto [x, y] = seg.product(L, R);
            cout << x << ' ' << y << '\n';
        }
        else
            assert(0);
    }
#else
    cout << "Hello World\n";
#endif
}
