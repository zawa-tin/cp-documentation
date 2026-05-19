// #define PROBLEM "https://atcoder.jp/contests/awc0071/tasks/awc0071_e"
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
/*
 * AtCoder Weekday Contest 0071 Beta E - Wi-Fiアクセスポイントの設置
 * https://atcoder.jp/contests/awc0071/submissions/75960503
 */
#include "../../Src/Graph/Matching/BipartiteMatching.hpp"
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int main() {
#ifdef ATCODER
    int N,M;
    cin >> N >> M;
    vector<pair<int,int>> E(M);
    for (auto& [u,v] : E) {
        cin >> u >> v;
        u--; v--;
    }
    int ans = zawa::BipartiteMatching(N,E).value().size();
    cout << ans << '\n';
#else
    int a,b;
    cin >> a >> b;
    cout << a+b << '\n';
#endif
}
