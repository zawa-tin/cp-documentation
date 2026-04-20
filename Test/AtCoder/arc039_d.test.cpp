// #define PROBLEM "https://atcoder.jp/contests/arc039/tasks/arc039_d"
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

/*
 * AtCoder Regular Contest 039 D - 旅行会社高橋君
 * https://atcoder.jp/contests/arc039/submissions/75134174
 */

#include "../../Src/Graph/Tree/LowestCommonAncestor.hpp"
#include "../../Src/Graph/Components/BridgeTree.hpp"

#include <iostream>
#include <iterator>
#include <vector>
#include <ranges>
using namespace std;

int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N,M;
    cin >> N >> M;
    zawa::BridgeTree<int> BT(N);
    for (int i = 0 ; i < M ; i++) {
        int x,y;
        cin >> x >> y;
        BT.addEdge(--x,--y);
    }
    auto twoedge = BT.build();
    vector<std::vector<int>> g(twoedge.size());
    for (int i = 0 ; i < ssize(g) ; i++)
        for (int j : twoedge[i] | views::keys)
            g[i].push_back(j);
    zawa::LowestCommonAncestor lca(g); 
    int Q;
    cin >> Q;
    while (Q--) {
        int a,b,c;
        cin >> a >> b >> c;
        a--; b--; c--;
        a = twoedge.id(a);
        b = twoedge.id(b);
        c = twoedge.id(c);
        bool ans = lca.distance(a,b)+lca.distance(b,c)==lca.distance(a,c);
        cout << (ans ? "OK\n" : "NG\n");
    }
#else
    int a,b;
    cin >> a >> b;
    cout << a + b << '\n';
#endif
}
