#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/3111"

#include "../../Src/Algebra/Monoid/SubarraySumMaxMonoid.hpp"
#include "../../Src/DataStructure/SegmentTree/SegmentTree.hpp"

#include <iostream>
#include <vector>

using namespace std;
using namespace zawa;
using M = SubarraySumMaxMonoid<long long>;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N, Q;
    cin >> N >> Q;
    vector<M::Element> A(N);
    for (int i = 0 ; i < N ; i++) {
        int a;
        cin >> a;
        A[i] = M::convert(a);
    }
    SegmentTree<M> seg{A};
    auto prod = [&]() -> long long {
        auto pd = seg.product(0, N);
        return pd ? max(pd->ans(), 0LL) : 0LL;
    };
    cout << prod() << '\n';
    while (Q--) {
        int k, x;
        cin >> k >> x;
        k--;
        seg.assign(k, M::convert(x));
        cout << prod() << '\n';
    }
}
