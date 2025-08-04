#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2450"

#include "../../Src/DataStructure/SegmentTree/AssignmentSegmentTree.hpp"
#include "../../Src/Graph/Tree/HeavyLightDecomposition.hpp"
#include "../../Src/Algebra/Monoid/SubarraySumMaxMonoid.hpp"
#include "../../Src/Algebra/Monoid/ReverseOrder.hpp"

#include <cassert>
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
    vector<int> A(N);
    for (int i = 0 ; i < N ; i++) cin >> A[i];
    vector<vector<int>> g(N);
    for (int i = 0 ; i < N - 1 ; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    HeavyLightDecomposition hld{g};
    vector<M::Element> init(N);
    for (int i = 0 ; i < N ; i++) init[hld[i]] = M::convert(A[i]);
    AssignmentSegmentTree<M> seg{init};
    AssignmentSegmentTree<ReverseOrder<M>> ges{init};
    while (Q--) {
        int T;
        cin >> T;
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        if (T == 1) {
            for (auto [s, t] : hld(a, b)) {
                s = hld[s];
                t = hld[t];
                if (s > t) swap(s, t);
                seg.assign(s, t + 1, M::convert(c));
                ges.assign(s, t + 1, M::convert(c));
            }
        }
        else if (T == 2) {
            M::Element pd = M::identity();
            for (auto [s, t] : hld(a, b)) {
                s = hld[s];
                t = hld[t];
                if (s <= t) pd = M::operation(pd, seg.product(s, t + 1));
                else pd = M::operation(pd, ges.product(t, s + 1));
            }
            assert(pd);
            cout << pd->ans() << '\n';
        }
        else assert(false);
    }
}
