#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
// #define PROBLEM "https://atcoder.jp/contests/abc351/tasks/abc351_g"

/*
 * AtCoder Beginner Contest 351 G - Hash on Tree
 * https://atcoder.jp/contests/abc351/submissions/71410674
 */

#include "atcoder/modint"
using mint = atcoder::modint998244353;
#include "../../Src/Algebra/Monoid/AffineMonoid.hpp"
#include "../../Src/Graph/Tree/DynamicTreeDP.hpp"

#include <iostream>
using namespace std;
using namespace zawa;
using AM = AffineMonoid<mint>;
struct Void {};
struct Path {
    mint ans, boundA;
    Affine<mint> ab;
};
using Point = mint;
struct DP {
    using Vertex = mint;
    using Edge = Void;
    using PathCluster = Path;
    using PointCluster = Point;
    static PathCluster vertex(const Vertex& v) {
        return {v, v, Affine<mint>{1, 0}};
    }
    static PathCluster addVertex(const PointCluster& p, const Vertex& v) {
        return {v, v, Affine<mint>{p, 0}};
    }
    static PointCluster addEdge(const PathCluster& p, const Edge&) {
        return p.ans;
    }
    static PointCluster rake(const PointCluster& p, const PointCluster& q) {
        return p * q;
    }
    static PathCluster compress(const PathCluster& p, const Edge&, const PathCluster& q) {
        return {p.ans + p.ab(q.ans), p.boundA, AM::operation(q.ab, p.ab)};
    }
};
//struct Printer {
//    void operator()(int i, string type, int par, Path p) const {
//        std::cout << i << " -> " << type << ' ' << par << '|' << p.ans.val() << ',' << p.boundA.val() << ',' << p.ab.a().val() << ',' << p.ab.b().val() << endl;
//    }
//    void operator()(int i, string type, int par, Point p) const {
//        std::cout << i << " -> " << type << ' ' << par << '|' << p.val() << endl;
//    }
//};
int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N, Q;
    cin >> N >> Q;
    DynamicTreeDPGraph g(N);
    for (int i = 1 ; i < N ; i++) {
        int p;
        cin >> p;
        g[--p].push_back({i, i - 1});
    }
    vector<DP::Vertex> A(N);
    for (int i = 0 ; i < N ; i++) {
        int a;
        cin >> a;
        A[i] = a;
    }
    DynamicTreeDP<DP> dp(g, 0, A, vector<DP::Edge>(N - 1));
    //dp.visit(Printer{});
    while (Q--) {
        int v, x;
        cin >> v >> x;
        dp.assignVertex(--v, mint{x});
        cout << dp().ans.val() << '\n';
    }
#else
    cout << "Hello World\n";
#endif
}
