// #define PROBLEM "https://codeforces.com/contest/2134/problem/D"
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
/*
 * Codeforces Round 1045 (Div. 2) D. Sliding Tree
 * https://codeforces.com/contest/2134/submission/396998123
 */
#include "../../Src/Graph/Tree/TreeCenters.hpp"
#include <iostream>
#include <vector>
using namespace std;
void solve() {
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for (int i = 0 ; i < N - 1 ; i++) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> path=zawa::TreeCenters<int,int>(G).diameterPath();
    if (ssize(path)==N) 
        cout << -1 << '\n';
    else {
        for (int i = 1 ; i + 1 < ssize(path) ; i++) 
            if (ssize(G[path[i]])>=3) {
                int c=-1;
                for (int v : G[path[i]])
                    if (v!=path[i-1] and v!=path[i+1])
                        c=v;
                assert(c!=-1);
                cout << path[i-1]+1 << ' ' << path[i]+1 << ' ' << c+1 << '\n';
                return;
            }
    }
}
int main() {
#ifdef ONLINE_JUDGE
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--)
        solve();
#else
    int a,b;
    cin >> a >> b;
    cout << a+b << '\n';
#endif
}
