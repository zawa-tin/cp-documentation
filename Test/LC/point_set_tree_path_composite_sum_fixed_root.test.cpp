#define PROBLEM "https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root"

#include "../../Src/Graph/Tree/DynamicTreeDP.hpp"
#include "../../Src/Algebra/Monoid/AffineMonoid.hpp"
#include "atcoder/modint"
using mint = atcoder::modint998244353;
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
using namespace zawa;
struct Path {
    mint ans;
    Affine<mint> hev;
    int sz;
};
struct Point {
    mint ans;
    int sz;
};
using AM = AffineMonoid<mint>;
struct DP {
    using Vertex = mint;
    using Edge = Affine<mint>;
    using PathCluster = Path;
    using PointCluster = Point;
    static PathCluster vertex(const Vertex& v) {
        return {v, AM::identity(), 1};
    }
    static PathCluster addVertex(const PointCluster& p, const Vertex& v) {
        return {p.ans + v, AM::identity(), p.sz + 1};
    }
    static PointCluster addEdge(const PathCluster& p, const Edge& e) {
        return {e.a() * p.ans + e.b() * p.sz, p.sz};
    }
    static PointCluster rake(const PointCluster& p, const PointCluster& q) {
        return {p.ans + q.ans, p.sz + q.sz};
    }
    static PathCluster compress(const PathCluster& p, const Edge& e, const PathCluster& q) {
        auto hev = AM::operation(e, p.hev);
        return {p.ans + hev.a() * q.ans + hev.b() * q.sz, AM::operation(q.hev, hev), p.sz + q.sz};
    }
};
//#include <random>
//mt19937 mt{random_device{}()};
//mint naive(DynamicTreeDPGraph g, vector<DP::Vertex> vs, vector<DP::Edge> es) {
//    auto rec = [&](auto rec, int v, int p) -> pair<mint, int> {
//        int sz = 1;
//        mint ans = vs[v];
//        for (auto [x, e] : g[v])
//            if (x != p) {
//                auto [a, b] = rec(rec, x, v);
//                ans += es[e].a() * a + es[e].b() * b;
//                sz += b;
//            }
//        return {ans, sz};
//    };
//    return rec(rec, 0, -1).first;
//}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N, Q;
    cin >> N >> Q;
    vector<DP::Vertex> vs(N);
    vector<DP::Edge> es(N - 1);
    for (int i = 0 ; i < N ; i++) {
        int a;
        cin >> a;
        vs[i] = a;
    }
    DynamicTreeDPGraph g(N);
    for (int i = 0 ; i < N - 1 ; i++) {
        int u, v, b, c;
        cin >> u >> v >> b >> c;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
        es[i] = Affine<mint>{b, c};
    }
    DynamicTreeDP<DP> dp(g, 0, vs, es);
    while (Q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int w, x;
            cin >> w >> x;
            dp.assignVertex(w, x);
        }
        else if (t == 1) {
            int e, y, z;
            cin >> e >> y >> z;
            dp.assignEdge(e, Affine<mint>{y, z});
        }
        else
            assert(0);
        cout << dp().ans.val() << '\n';
    }
}
