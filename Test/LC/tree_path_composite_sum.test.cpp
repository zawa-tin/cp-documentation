#define PROBLEM "https://judge.yosupo.jp/problem/tree_path_composite_sum"
#include "../../Src/Graph/Tree/Rerooting.hpp"
#include "../../Src/Algebra/Monoid/AffineMonoid.hpp"
#include "atcoder/modint"
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
using namespace zawa;
using mint=atcoder::modint998244353;
struct DP {
    using Tree = pair<mint,int>;
    using Cluster = pair<mint,int>;
    using Edge = Affine<mint>;
    using Vertex = mint;
    static Tree Convert(Vertex a) {
        return {a,1};
    }
    static Cluster AddEdge(Tree t,Edge f) {
        return {f.a()*t.first+f.b()*t.second,t.second};
    }
    static Cluster Merge(Cluster l,Cluster r) {
        return {l.first+r.first,l.second+r.second};
    }
    static Tree AddVertex(Cluster c,Vertex a) {
        return {c.first+a,c.second+1};
    }
};
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<mint> A(N);
    for (int i = 0 ; i < N ; i++) {
        int a;
        cin >> a;
        A[i]=mint::raw(a);
    }
    vector<pair<int,int>> E(N-1);
    vector<Affine<mint>> af(N-1);
    for (int i = 0 ; auto& [u,v] : E) {
        int b,c;
        cin >> u >> v >> b >> c;
        af[i]=Affine<mint>{mint::raw(b),mint::raw(c)};
        i++;
    }
    Rerooting<DP,int> dp(N,E,A,af);
    for (int i = 0 ; i < N ; i++)
        cout << dp[i].first.val() << (i+1==N?'\n':' ');
}
