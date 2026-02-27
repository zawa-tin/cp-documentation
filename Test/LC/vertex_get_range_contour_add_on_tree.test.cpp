#define PROBLEM "https://judge.yosupo.jp/problem/vertex_get_range_contour_add_on_tree"

#include "../../Src/Graph/Tree/ContourAggregation.hpp"
#include "../../Src/DataStructure/FenwickTree/DualFenwickTree.hpp"
#include "../../Src/Algebra/Group/AdditiveGroup.hpp"
using namespace zawa;

#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (auto& x : A)
        cin >> x;
    vector<vector<int>> G(N);
    for (int i = 0 ; i < N - 1 ; i++) {
       int u, v;
       cin >> u >> v;
       G[u].push_back(v);
       G[v].push_back(u);
    }
    ContourAggregation sol(move(G));
    cerr << "size=" << ssize(sol) << endl;
    DualFenwickTree<AdditiveGroup<long long>> fen(ssize(sol));
    for (int i = 0 ; i < N ; i++) 
        for (auto [L, R] : sol.contour(i,0))
            fen.operation(L,R,A[i]);
    while (Q--) {
        int T;
        cin >> T;
        if (T == 0) {
            int p, l, r, x;
            cin >> p >> l >> r >> x;
            for (auto [L, R] : sol.contour(p,l,r))
                fen.operation(L,R,x);
        }
        else if (T == 1) {
            int p;
            cin >> p;
            long long ans = 0;
            for (auto i : sol.point(p))
                ans += fen[i];
            cout << ans << '\n';
        }
        else
            assert(0);
    }
}
