// #define PROBLEM "https://atcoder.jp/contests/abc456/tasks/abc456_e"
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

/*
 * AtCoder Beginner Contest 456 E - Endless Holidays
 * https://atcoder.jp/contests/abc456/submissions/75471175
 */

#include "../../Src/Graph/CycleDetection.hpp"
#include <iostream>
#include <vector>
using namespace std;
int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int N,M;
        cin >> N >> M;
        vector<pair<int,int>> E(M);
        for (auto& [u,v] : E) {
            cin >> u >> v;
            u--; v--;
        }
        for (int i = 0 ; i < N ; i++)
            E.push_back({i,i});
        int W;
        cin >> W;
        vector<string> S(N);
        for (auto& s : S)
            cin >> s;
        vector<vector<int>> G(N*W);
        auto f = [&](int v,int day) -> int {
            day %= W;
            return v*W+day;
        };
        for (auto [u,v] : E)
            for (int i = 0 ; i < W ; i++) {
                if (S[u][i] == 'o' and S[v][(i+1)%W] == 'o')
                    G[f(u,i)].push_back(f(v,i+1));
                if (u != v and S[v][i] == 'o' and S[u][(i+1)%W] == 'o')
                    G[f(v,i)].push_back(f(u,i+1));
            }
        cout << (zawa::CycleDetection<int,true>(G).has_value() ? "Yes\n" : "No\n");
    }
#else
    int a,b;
    cin >> a >> b;
    cout << a + b << '\n';
#endif
}
