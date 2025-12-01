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
using G = TreeDPGraph<DP>;
//#include <random>
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0); 
    int N;
    cin >> N;
    G g(N);
    for (int i = 1 ; i < N ; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back({v, 0});
        g[v].push_back({u, 0});
    }
    auto far = Rerooting<DP>(g, vector<int>(N));
    for (int i = 0 ; i < N ; i++)
        cout << 2 * (N - 1) - far[i] << '\n';
}
