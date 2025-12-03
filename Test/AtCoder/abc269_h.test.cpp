#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
// #define PROBLEM "https://atcoder.jp/contests/abc269/tasks/abc269_h"

/*
 * AtCoder Beginner Contest 269 Ex - Antichain
 * https://atcoder.jp/contests/abc269/submissions/71411446
 */

#include "../../Src/Graph/Tree/DynamicTreeDP.hpp"
#include "atcoder/modint"
#include "atcoder/convolution"
using mint = atcoder::modint998244353;
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
using namespace zawa;
vector<mint> operator+(vector<mint> a, vector<mint> b) {
    a.resize(max(a.size(), b.size()));
    for (int i = 0 ; i < ssize(b) ; i++)
        a[i] += b[i];
    return a;
}
struct DP {
    using Vertex = struct {};
    using Edge = struct {};
    // first... must use root(heavy path), second... must not use root
    using PathCluster = pair<vector<mint>, vector<mint>>;
    using PointCluster = vector<mint>;
    static PathCluster vertex(Vertex) {
        return {vector<mint>{0, 1}, vector<mint>{1, 0}};
    }
    static PathCluster addVertex(PointCluster p, Vertex) {
        return {vector<mint>{0, 1}, p};
    }
    static PointCluster addEdge(PathCluster p, Edge) {
        return p.first + p.second;
    }
    static PointCluster rake(PointCluster p, PointCluster q) {
        return atcoder::convolution(p, q);
    }
    static PathCluster compress(PathCluster p, Edge, PathCluster q) {
        return {p.first + atcoder::convolution(p.second, q.first), atcoder::convolution(p.second, q.second)};
    }
};
ostream& operator<<(ostream& os, vector<mint> v) {
    for (auto x : v)
        os << x.val() << ' ';
    return os; 
}
struct Printer {
    void operator()(int i, string name, int par, DP::PathCluster path) {
        cout << i << ' ' << name << ' ' << par << " -> " << path.first << '|' << path.second << endl;
    }
    void operator()(int i, string name, int par, DP::PointCluster point) {
        cout << i << ' ' << name << ' ' << par << " -> " << point << endl;
    }
};
int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    DynamicTreeDPGraph g(N);
    for (int i = 1 ; i < N ; i++) {
        int p;
        cin >> p;
        g[--p].push_back({i, i - 1});
    }
    DynamicTreeDP<DP> dp(g, 0, vector<DP::Vertex>(N), vector<DP::Edge>(N - 1));
    //dp.visit(Printer{});
    auto [p, q] = dp();
    auto ans = p + q;
    while (ssize(ans) <= N)
        ans.push_back(0);
    for (int i = 1 ; i <= N ; i++)
        cout << ans[i].val() << '\n';
#else
    cout << "Hello World\n";
#endif
}
