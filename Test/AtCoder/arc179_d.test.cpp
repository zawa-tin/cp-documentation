// #define PROBLEM "https://atcoder.jp/contests/arc179/tasks/arc179_d"
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
/*
 * AtCoder Regular Contest 179 D - Portable Gate 
 * https://atcoder.jp/contests/arc179/submissions/80190724
 */
#include "../../Src/Graph/Tree/Rerooting.hpp"
#include <algorithm>
#include <array>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
using namespace zawa;
struct Item {
    array<int,2> aru{0,0}; // 根にゲートがある状態での最小コスト
    int ed=0; // 辺数
    int far=0; // 最遠点までの距離
    int nai() const { // 根にゲートがない状態での最小コスト
        return 2*ed-far;
    }
};
struct DP {
    using Tree = Item;
    using Cluster = Item;
    using Edge = struct {};
    using Vertex = struct {};
    static Tree Convert(Vertex) {
        return {array<int,2>{0,0},0,0};
    }
    static Cluster AddEdge(Tree t,Edge) {
        int ed=t.ed+1;
        int far=t.far+1;
        array<int,2> aru{min(t.aru[0]+2,t.nai()+1),min(t.aru[1]+1,t.nai()+1)};
        return {aru,ed,far};
    }
    static Cluster Merge(Cluster l,Cluster r) {
        int ed=l.ed+r.ed;
        int far=max(l.far,r.far);
        array<int,2> aru{l.aru[0]+r.aru[0],min(l.aru[0]+r.aru[1],l.aru[1]+r.aru[0])};
        return {aru,ed,far};
    }
    static Tree AddVertex(Cluster c,Vertex) {
        return c;
    }
};
int main() {
#ifdef ATCODER
    int N;
    cin >> N;
    vector<pair<int,int>> E(N-1);
    for (auto& [u,v] : E) {
        cin >> u >> v;
        u--; v--;
    }
    Rerooting<DP,int> dp(N,E,vector<DP::Vertex>(N),vector<DP::Edge>(N-1));
    int ans=(int)1e9;
    for (int i = 0 ; i < N ; i++)
        ans=min(ans,dp[i].aru[1]);
    cout << ans << '\n';
#else
    int a,b;
    cin >> a >> b;
    cout << a+b << '\n';
#endif
}
