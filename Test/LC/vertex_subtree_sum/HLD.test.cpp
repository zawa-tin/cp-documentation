#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"
#include "../../../Src/Graph/Tree/HeavyLightDecomposition.hpp"
#include "../../../Src/Algebra/Group/AdditiveGroup.hpp"
#include "../../../Src/DataStructure/FenwickTree/FenwickTree.hpp"
using namespace zawa;
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N,Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (auto& x : A)
        cin >> x;
    vector<vector<int>> G(N);
    for (int i = 1 ; i < N ; i++) {
        int p;
        cin >> p;
        G[p].push_back(i);
    }
    HeavyLightDecomposition hld{move(G)};
    FenwickTree<AdditiveGroup<long long>> fen(N);
    for (int i = 0 ; i < N ; i++)
        fen.operation(hld[i],A[i]);
    while (Q--) {
        int t,v;
        cin >> t >> v;
        if (t == 0) {
            int x;
            cin >> x;
            fen.operation(hld[v],x);
        }
        else if (t == 1) {
            long long ans = 0;
            hld.subtreeQuery(v,[&](int l,int r) { ans += fen.product(l,r); });
            cout << ans << '\n';
        }
        else
            assert(0);
    }
}
