// #define PROBLEM "https://atcoder.jp/contests/abc417/tasks/abc417_f"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * AtCoder Beginner Contest 417 F - Random Gathering
 * https://atcoder.jp/contests/abc417/submissions/68182292
 */

#include "../../Src/DataStructure/SegmentTree/AssignmentSegmentTree.hpp"
#include "atcoder/modint"
using mint = atcoder::modint998244353;

#include <iostream>
#include <vector>

struct S {
    using Element = mint;
    static Element identity() {
        return 0;
    }
    static Element operation(Element L, Element R) {
        return L + R;
    }
    static Element power(Element v, int exp) {
        return v * mint{exp};
    }
};

using namespace std;
using namespace zawa;
int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    vector<mint> A(N);
    for (int i = 0 ; i < N ; i++) {
        int v;
        cin >> v;
        A[i] = mint::raw(v);
    }
    AssignmentSegmentTree<S> seg{A};
    while (M--) {
        int L, R;
        cin >> L >> R;
        L--;
        seg.assign(L, R, seg.product(L, R) / mint{R - L}); 
    }
    for (int i = 0 ; i < N ; i++) cout << seg.product(i, i + 1).val() << (i + 1 == N ? '\n' : ' ');
#else
    cout << "Hello World\n";
#endif
}
