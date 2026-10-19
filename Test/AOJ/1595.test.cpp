#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/1595"

#include "../../Src/Graph/Tree/Rerooting.hpp"
#include <iostream>
#include <algorithm>
using namespace std;
using namespace zawa;
struct DP {
    using Tree = int;
    using Cluster = int;
    using Edge = int;
    using Vertex = int;
    static Tree Convert(Vertex) {
        return 0;
    }
    static Cluster AddEdge(Tree t, Edge) {
        return t + 1;
    }
    static Cluster Merge(Cluster l, Cluster r) {
        return max(l, r);
    }
    static Tree AddVertex(Cluster c, Vertex) {
        return c;
    }
};
//#include <random>
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0); 
    int N;
    cin >> N;
    vector<pair<int,int>> E(N-1);
    for (auto& [u,v] : E) {
        cin >> u >> v;
        u--; v--;
    }
    auto far = Rerooting<DP,int>(N,E,vector<int>(N),vector<int>(N-1));
    for (int i = 0 ; i < N ; i++)
        cout << 2 * (N - 1) - far[i] << '\n';
}
