#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree"

#include "../../Src/Graph/Tree/ContourAggregation.hpp"
#include "../../Src/DataStructure/FenwickTree/FenwickTree.hpp"
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
    FenwickTree<AdditiveGroup<long long>> fen(ssize(sol));
    for (int i = 0 ; i < N ; i++) 
        for (int j : sol.point(i))
            fen.operation(j,A[i]);
    while (Q--) {
        int T;
        cin >> T;
        if (T == 0) {
            int p, x;
            cin >> p >> x;
            for (int i : sol.point(p))
                fen.operation(i,x);
        }
        else if (T == 1) {
            int p, l, r;
            cin >> p >> l >> r;
            // cout << "query " << p << ' ' << l << ' ' << r << endl;
            long long ans = 0;
            for (auto [L, R] : sol.contour(p,l,r))
                ans += fen.product(L,R);
            cout << ans << '\n';
        }
        else
            assert(0);
    }
}
