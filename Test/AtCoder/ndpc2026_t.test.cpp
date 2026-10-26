// #define PROBLEM "https://atcoder.jp/contests/ndpc/tasks/ndpc2026_t"
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
/*
 * Next DP Contest T - 独立集合 (Subtask)
 * https://atcoder.jp/contests/ndpc/submissions/80403501
 */
#include "../../Src/FPS/FPSNTTFriendly.hpp"
#include "../../Src/FPS/MultipointEvaluation.hpp"
#include "../../Src/Graph/Tree/STTFold.hpp"
#include "atcoder/modint"
using mint=atcoder::modint998244353;
#include <vector>
#include <array>
#include <iostream>
using namespace std;
using namespace zawa;
using fps=FPSNTTFriendly<mint::mod()>;
struct DP {
    using Vertex = struct {};
    using Edge = struct {};
    // 1..ue,2..sita
    using PathCluster = array<fps,4>;
    using PointCluster = array<fps,2>;
    static PathCluster vertex(const Vertex&) {
        fps notuse{1};
        fps use{0,1};
        fps ban;
        return {notuse,ban,ban,use};
    }
    static PathCluster addVertex(PointCluster f, const Vertex&) {
        fps notuse=f[0]+f[1];
        fps use=f[0]*fps{0,1};
        fps ban;
        return {notuse,ban,ban,use};
    }
    static PointCluster addEdge(PathCluster fs, const Edge&) {
        return {fs[0]+fs[2],fs[1]+fs[3]};
    }
    static PointCluster rake(PointCluster l, PointCluster r) {
        return {l[0]*r[0],l[0]*r[1]+l[1]*r[0]+l[1]*r[1]};
    }
    static PathCluster compress(PathCluster p, Edge, const PathCluster c) {
        array<fps,4> res;
        res.fill(fps{});
        for (int i = 0 ; i < 4 ; i++)
            for (int j = 0 ; j < 4 ; j++) {
                if ((i&2) and (j&1))
                    continue;
                int idx=0;
                if (i&1)
                    idx|=1;
                if (j&2)
                    idx|=2;
                res[idx]+=p[i]*c[j];
            }
        return res;
    }
};
int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N,Q;
    cin >> N >> Q;
    STTGraph g(N);
    for (int i = 0 ; i < N-1 ; i++) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back({v,i});
        g[v].push_back({u,i});
    }
    auto fold=STTFold<DP>(move(g),0,vector<DP::Vertex>(N),vector<DP::Edge>(N-1));
    fps f=fold[1]+fold[3];
    vector<mint> x(Q);
    for (int i = 0 ; i < Q ; i++) {
        int v,q;
        cin >> v >> q;
        if (v != 1)
            exit(0);
        x[i]=mint::raw(q);
    }
    for (mint ans : MultipointEvaluation(f,x))
        cout << ans.val() << '\n';
#else
    int a,b;
    cin >> a >> b;
    cout << a+b << '\n';
#endif
}
