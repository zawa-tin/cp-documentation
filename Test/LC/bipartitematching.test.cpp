#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Graph/Matching/BipartiteMatching.hpp"
using namespace zawa;

#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int L,R,M;
    cin >> L >> R >> M;
    vector<pair<int,int>> E(M);
    for (auto& [u,v] : E)
        cin >> u >> v;
    auto ans = BipartiteMatching(L,R,E);
    cout << ssize(ans) << '\n';
    for (auto [u,v] : ans)
        cout << u << ' ' << v << '\n';
}
