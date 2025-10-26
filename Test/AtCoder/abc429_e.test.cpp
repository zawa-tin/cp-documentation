// #define PROBLEM "https://atcoder.jp/contests/abc429/tasks/abc429_e"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
#include "../../Src/Utility/SeparatedFamilySet.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> g(N);
    for (int i = 0 ; i < M ; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    string S;
    cin >> S;
    vector<int> safe, danger;
    for (int i = 0 ; i < N ; i++) {
        if (S[i] == 'S')
            safe.push_back(i);
        else
            danger.push_back(i);
    }
    const int INF = (int)1e9;
    auto bfs = [&](const vector<bool>& use) -> vector<int> {
        vector<int> dist(N, INF), que;
        for (int i = 0 ; i < ssize(safe) ; i++)
            if (use[i]) {
                dist[safe[i]] = 0;
                que.push_back(safe[i]);
            }
        for (int t = 0 ; t < ssize(que) ; t++) {
            const int v = que[t];
            for (int x : g[v])
                if (dist[x] == INF) {
                    dist[x] = dist[v] + 1;
                    que.push_back(x);
                }
        }
        return dist;
    };
    vector<int> ans(N, INF);
    for (vector<bool> sep : zawa::SeparatedFamilySet(safe.size())) {
        vector<int> da = bfs(sep);
        for (int i = 0 ; i < ssize(sep) ; i++)
            sep[i] = !sep[i];
        vector<int> db = bfs(sep);
        for (int i : danger)
            ans[i] = min(ans[i], da[i] + db[i]);
    }
    for (int i : danger)
        cout << ans[i] << '\n';
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
#ifdef ATCODER
    solve();
#else
    cout << "Hello World\n";
#endif
}
