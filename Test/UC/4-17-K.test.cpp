// #define PROBLEM "https://contest.ucup.ac/contest/3384/problem/17171"
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

/*
 * GP of St. Petersburg K. Traversal of a Triangular Grid
 * https://contest.ucup.ac/submission/2053140
 */

#include "../../Src/Graph/EulerianTrail.hpp"
using namespace zawa;
#include <algorithm>
#include <iostream>
#include <ranges>
#include <utility>
#include <vector>
using namespace std;
int main() {
#ifdef ONLINE_JUDGE
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<pair<int,int>> p;
    for (int i = 0 ; i <= N ; i++)
        for (int j = 0 ; j <= i ; j++)
            p.push_back({i,j});
    vector<pair<int,int>> E, dir;
    for (int i = 0 ; i <= N ; i++)
        for (int j = 0 ; j <= i ; j++) {
            const int u = ranges::find(p,pair{i,j}) - p.begin();
            if (j + 1 <= i) {
                const int v = ranges::find(p,pair{i,j+1}) - p.begin();
                E.push_back({u,v});
                dir.push_back({0,3});
            }
            if (i + 1 <= N) {
                const int v = ranges::find(p,pair{i+1,j}) - p.begin();
                E.push_back({u,v});
                dir.push_back({4,1});
            }
            if (i + 1 <= N) {
                const int v = ranges::find(p,pair{i+1,j+1}) - p.begin();
                E.push_back({u,v});
                dir.push_back({5,2});
            }
        }
    const int s = ranges::find(p,pair{0,0}) - p.begin();
    auto [vs, es] = *EulerianTrail((int)p.size(),E,false,s);
    // for (int i : vs)
    //     cout << '(' << p[i].first << ',' << p[i].second << ')';
    // cout << endl;
    for (int i = 0 ; i < ssize(es) ; i++) {
        int u = vs[i], v = vs[i+1];
        if (E[es[i]] == pair{u,v})
            cout << dir[es[i]].first;
        else if (E[es[i]] == pair{v,u})
            cout << dir[es[i]].second;
        else
            assert(0);
    }
    cout << '\n';
#else
    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
#endif
}
